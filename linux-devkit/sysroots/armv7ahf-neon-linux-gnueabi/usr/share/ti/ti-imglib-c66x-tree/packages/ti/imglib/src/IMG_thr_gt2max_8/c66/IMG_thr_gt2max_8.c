/* ======================================================================== *
 * IMGLIB -- TI Image and Video Processing Library                          *
 *                                                                          *
 *                                                                          *
 * Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/   *
 *                                                                          *
 *                                                                          *
 *  Redistribution and use in source and binary forms, with or without      *
 *  modification, are permitted provided that the following conditions      *
 *  are met:                                                                *
 *                                                                          *
 *    Redistributions of source code must retain the above copyright        *
 *    notice, this list of conditions and the following disclaimer.         *
 *                                                                          *
 *    Redistributions in binary form must reproduce the above copyright     *
 *    notice, this list of conditions and the following disclaimer in the   *
 *    documentation and/or other materials provided with the                *
 *    distribution.                                                         *
 *                                                                          *
 *    Neither the name of Texas Instruments Incorporated nor the names of   *
 *    its contributors may be used to endorse or promote products derived   *
 *    from this software without specific prior written permission.         *
 *                                                                          *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     *
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       *
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   *
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    *
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   *
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        *
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   *
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   *
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     *
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   *
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    *
 * ======================================================================== */

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_thr_gt2max_8                                                    */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*      void IMG_thr_gt2max_8                                               */
/*      (                                                                   */
/*          const unsigned char *in_data,     //  Input image data  //      */
/*          unsigned char *restrict out_data, //  Output image data //      */
/*          short cols, short rows,           //  Image dimensions  //      */
/*          unsigned char       threshold     //  Threshold value   //      */
/*      )                                                                   */
/*                                                                          */
/*      This routine performs a thresholding operation on an input          */
/*      image in in_data[] whose dimensions are given in the arguments      */
/*      'cols' and 'rows'.  The thresholded pixels are written to the       */
/*      output image pointed to by out_data[].  The input and output        */
/*      are exactly the same dimensions.                                    */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      Pixels that are below or equal to the threshold value are           */
/*      written to the output unmodified.  Pixels that are greater          */
/*      than the threshold are set to 255 in the output image.              */
/*                                                                          */
/*      The exact thresholding function performed is described by           */
/*      the following transfer function diagram:                            */
/*                                                                          */
/*                                                                          */
/*                 255_|          _________                                 */
/*                     |         |                                          */
/*                     |         |                                          */
/*            O        |         |                                          */
/*            U        |         |                                          */
/*            T    th _|. . . . .|                                          */
/*            P        |        /.                                          */
/*            U        |      /  .                                          */
/*            T        |    /    .                                          */
/*                     |  /      .                                          */
/*                   0_|/________.__________                                */
/*                     |         |        |                                 */
/*                     0        th       255                                */
/*                                                                          */
/*                             INPUT                                        */
/*                                                                          */
/*      Please see the IMGLIB functions IMG_thr_gt2thr, IMG_thr_le2thr      */
/*      and IMG_thr_le2min for other thresholding functions.                */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The input and output buffers do not alias.                          */
/*                                                                          */
/*      The input and output buffers must be double-word aligned.           */
/*                                                                          */
/*      The total number of pixels rows*cols must be at least               */
/*      16 and a multiple of 16.                                            */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The loop is manually unrolled 4x.  We ask the compiler to unroll    */
/*      the loop an additional factor of 4x, yielding a total unroll        */
/*      factor of 16x.  Packed-data processing techniques allow us to       */
/*      process all 4 pixels in parallel.                                   */
/*                                                                          */
/*      A single _amem4_const() intrinsic brings in four pixels,            */
/*      designated p0 thru p3.  These pixels are packed into the unsigned   */
/*      integer variable p3p2p1p0 as follows:                               */
/*                                                                          */
/*                            31  24   16    8    0                         */
/*                             +----+----+----+----+                        */
/*                    p3p2p1p0 | p3 | p2 | p1 | p0 |                        */
/*                             +----+----+----+----+                        */
/*                                                                          */
/*      (Note that this diagram assumes a little endian memory              */
/*      configuration, although this kernel works equally well in           */
/*      either endian mode.)                                                */
/*      We compare this packed word against a packed copy of the threshold  */
/*      value.  The packed threshold contains four copies of the threshold  */
/*      value, one in each byte, like so:                                   */
/*                                                                          */
/*                             31  24   16    8    0                        */
/*                              +----+----+----+----+                       */
/*                     thththth | th | th | th | th |                       */
/*                              +----+----+----+----+                       */
/*                                                                          */
/*      We compare using _cmpgtu4().  The comparison results are then       */
/*      expanded to masks using _xpnd4().  The result is a four-byte mask   */
/*      (x3210) which contains 0xFF in bytes that are greater than the      */
/*      threshold, and 0x00 in bytes that are less than or equal to the     */
/*      threshold.                                                          */
/*                                                                          */
/*      To complete the thresholding process, we compute the logical OR     */
/*      between our original pixel values and the mask.  This forces        */
/*      values above the threshold to 0xFF, and leaves the other values     */
/*      unmodified.                                                         */
/*                                                                          */
/*      The four pixels are then written with a single _amem4().            */
/*                                                                          */
/*      In this version of the code, we rely on the compiler to unroll      */
/*      the loop 4x (as noted above), and convert the _amem4_const() and    */
/*      _amem4() calls into _amemd8_const()/_amemd8() as part of its        */
/*      automatic optimizations.                                            */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      This code is ENDIAN NEUTRAL.                                        */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_thr_gt2max_8,   ".text:optimized");

void IMG_thr_gt2max_8
(
    const unsigned char *in_data,                /*  Input image data    */
    unsigned char       *restrict out_data,      /*  Output image data   */
    short cols, short rows,                      /*  Image dimensions    */
    unsigned char       threshold                /*  Threshold value     */
)
{
  int i, pixels = rows * cols;
  unsigned thththth;

  _nassert((int)in_data % 8 == 0);
  _nassert((int)out_data % 8 == 0);
  _nassert(pixels % 16 == 0);
  _nassert(pixels      >= 16);

  thththth = _pack2(threshold, threshold);
  thththth = _packl4(thththth, thththth);

  /* -------------------------------------------------------------------- */
  /*  Step through input image copying pixels to the output.  If the      */
  /*  pixels are above our threshold, set them to 255.                    */
  /* -------------------------------------------------------------------- */
  #pragma MUST_ITERATE(4,,4);
  #pragma UNROLL(4);

  for (i=0; i<pixels; i+=4) {
    unsigned p3p2p1p0, x3x2x1x0;

    p3p2p1p0 = _amem4_const(&in_data[i]);
    x3x2x1x0 = _xpnd4(_cmpgtu4(p3p2p1p0, thththth));
 
    _amem4(&out_data[i]) = p3p2p1p0 | x3x2x1x0;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_thr_gt2max_8.c                                        */
/* ======================================================================== */
