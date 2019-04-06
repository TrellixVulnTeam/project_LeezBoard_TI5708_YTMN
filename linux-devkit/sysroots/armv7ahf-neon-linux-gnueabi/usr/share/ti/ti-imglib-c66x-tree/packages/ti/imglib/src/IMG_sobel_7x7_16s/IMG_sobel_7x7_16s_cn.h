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

#ifndef IMG_SOBEL_7x7_16S_C_H_
#define IMG_SOBEL_7x7_16S_C_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_sobel_7x7_16s_cn                                                */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_sobel_7x7_16s_cn                                           */
/*      (                                                                   */
/*          const short restrict  *in,     // Input image data  //          */
/*                short restrict *out,     // Output image data //          */
/*                short          cols,     // image columns     //          */
/*                short          rows      // Image rows        //          */
/*      )                                                                   */
/*      The sobel_7x7 filter is applied to the input image.  The input      */
/*      image dimensions are given by the arguments 'cols' and 'rows'.      */
/*      The output image is 'cols' pixels wide and 'rows - 6' pixels        */
/*      tall.                                                               */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      To see how the implementation is going to work on the input         */
/*      buffer, lets imagine we have the following input buffer:            */
/*      lets imagine we have the following input buffer:                    */
/*                                                                          */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyxxxxxxxxxxyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*              yyyyyyyyyyyyyyyy                                            */
/*                                                                          */
/*      The output buffer would be:                                         */
/*                                                                          */
/*              tttXXXXXXXXXXzzz                                            */
/*              zzzXXXXXXXXXXzzz                                            */
/*              zzzXXXXXXXXXXzzz                                            */
/*              zzzXXXXXXXXXXttt                                            */
/*                                                                          */
/*      Where:                                                              */
/*                                                                          */
/*          X = sobel(x)    The algorithm is applied to that pixel.         */
/*                          The correct output is obtained, the data        */
/*                          around the pixels we work on is used            */
/*                                                                          */
/*          t               Whatever was in the output buffer in that       */
/*                          position is kept there.                         */
/*                                                                          */
/*          z = sobel(y)    The algorithm is applied to that pixel.         */
/*                          The output is not meaningful, because the       */
/*                          necessary data to process the pixel is not      */
/*                          available.  This is because for each output     */
/*                          pixel we need input pixels from the right and   */
/*                          from the left of the output pixel.  But this    */
/*                          data doesn't exist.                             */
/*                                                                          */
/*      This means that we will only process (rows-6) lines.  Then, we      */
/*      will process all the pixels inside each line. Even though the       */
/*      results for the first 3 and last 3 pixels in each line will not     */
/*      be relevant, it makes the control much simpler and ends up          */
/*      saving cycles.                                                      */
/*                                                                          */
/*      Also the first 3 pixels in the first processed line and the         */
/*      last 3 pixels in the last processed line will not be computed.      */
/*      It is not necessary, since the results would be bogus.              */
/*                                                                          */
/*      The following horizontal and vertical masks that are                */
/*      applied to the input buffer to obtain one output pixel.             */
/*                                                                          */
/*          Horizontal:                                                     */
/*              -1 -1 -1 -2 -1 -1 -1                                        */
/*              -1 -1 -1 -2 -1 -1 -1                                        */
/*              -1 -1 -1 -2 -1 -1 -1                                        */
/*               0  0  0  0  0  0  0                                        */
/*               1  1  1  2  1  1  1                                        */
/*               1  1  1  2  1  1  1                                        */
/*               1  1  1  2  1  1  1                                        */
/*                                                                          */
/*          Vertical:                                                       */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -2 -2 -2  0  2  2  2                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*              -1 -1 -1  0  1  1  1                                        */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes have restrictions as noted in the ASSUMPTIONS   */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. cols :     'cols' >  7 and multiple of 2.                        */
/*      2. rows :     'rows' >= 7.                                          */
/*      3. cols * (rows - 6) - 6 should be greater than or equal to 2.      */
/*      4. Input and output arrays do not overlap.                          */
/*      5. Input and output arrays should be half-word aligned.             */
/*                                                                          */
/*  NOTES                                                                   */
/*      The values of the three left-most and three right-most pixels       */
/*      on each line of the output are not well-defined.                    */
/*                                                                          */
/* ======================================================================== */

void IMG_sobel_7x7_16s_cn
(
    const short *restrict  in,   /* Input image data   */
          short *restrict out,   /* Output image data  */
          short          cols,   /* image columns      */
          short          rows    /* Image rows         */
);

#endif

/* ======================================================================== */
/*  end of file:  IMG_sobel_7x7_16s_c.h                                     */
/* ======================================================================== */
