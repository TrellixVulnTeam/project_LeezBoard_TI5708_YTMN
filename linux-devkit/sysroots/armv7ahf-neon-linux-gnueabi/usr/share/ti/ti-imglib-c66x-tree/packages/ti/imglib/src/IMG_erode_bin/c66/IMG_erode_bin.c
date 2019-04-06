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
/*      IMG_erode_bin                                                       */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable, and has the following C prototype:      */
/*                                                                          */
/*      void IMG_erode_bin                                                  */
/*      (                                                                   */
/*          const unsigned char *restrict in_data,   // Incoming image  //  */
/*          unsigned char       *restrict out_data,  // Filtered output //  */
/*          const char          *restrict mask,      // Filter mask     //  */
/*          int cols  // Number of columns to process, in bytes.        //  */
/*      );                                                                  */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The function IMG_erode_bin() implements binary erosion using an     */
/*      arbitrary 3x3 mask.  The erosion operator generates output pixels   */
/*      by ANDing the pixels under the input mask together to generate      */
/*      the output pixel.  The input mask specifies whether one or more     */
/*      pixels from the input are to be ignored.                            */
/*                                                                          */
/*      In pseudo-code, the filtering operation for a pixel at (x, y)       */
/*      works like so:                                                      */
/*                                                                          */
/*          result = 1;                                                     */
/*          if (mask[0][0] != DONT_CARE) result &= input[y + 0][x + 0];     */
/*          if (mask[0][1] != DONT_CARE) result &= input[y + 1][x + 1];     */
/*          if (mask[0][2] != DONT_CARE) result &= input[y + 2][x + 2];     */
/*          if (mask[1][0] != DONT_CARE) result &= input[y + 0][x + 0];     */
/*          if (mask[1][1] != DONT_CARE) result &= input[y + 1][x + 1];     */
/*          if (mask[1][2] != DONT_CARE) result &= input[y + 2][x + 2];     */
/*          if (mask[2][0] != DONT_CARE) result &= input[y + 0][x + 0];     */
/*          if (mask[2][1] != DONT_CARE) result &= input[y + 1][x + 1];     */
/*          if (mask[2][2] != DONT_CARE) result &= input[y + 2][x + 2];     */
/*          output[y][x] = result;                                          */
/*                                                                          */
/*      For this code, "DONT_CARE" is specified by a negative value         */
/*      in the input mask.  Non-negative values in the mask cause the       */
/*      corresponding pixel to be included in the erosion operation.        */
/*                                                                          */
/*      Note that this code operates on a bitmap where each pixel is        */
/*      represented as a single bit within a byte or word.  Although        */
/*      the pseudo-code above operates only on one pixel at a time,         */
/*      with a single pixel in each array element, this implementation      */
/*      operates on a bitmap which contains 8 pixels in each byte.          */
/*                                                                          */
/*      Pixels are organized within each byte such that the pixel with      */
/*      the smallest index is in the LSB position, and the pixel with       */
/*      the largest index is in the MSB position.  (That is, the code       */
/*      assumes a LITTLE ENDIAN bit ordering.)                              */
/*                                                                          */
/*      Note that the "cols" argument actually specifies the number of      */
/*      BYTES in the output, not the number of columns.  The number of      */
/*      columns is 8 times this argument.                                   */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The 3x3 erosion mask is applied to 32 output pixels                 */
/*      simultaneously.  This is done with 32-bit-wide bitwise              */
/*      operators in the register file.  In order to do this, the code      */
/*      reads in a 34-bit-wide input window, and 40-bit operations          */
/*      are used to manipulate the pixels initially.                        */
/*                                                                          */
/*      Because the code reads a 34-bit context for each 32-bits of         */
/*      output, the input needs to be one byte longer than the output       */
/*      in order to make the rightmost two pixels well-defined.             */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1.  Negative values in the mask specify "DONT_CARE", and non-       */
/*          negative values specify that pixels are included in the         */
/*          erosion operation.                                              */
/*                                                                          */
/*      2.  The input image needs to have a multiple of 64 pixels(bits)     */
/*          per row.  Therefore, "cols" must be a multiple of 8.            */
/*                                                                          */
/*  NOTES                                                                   */
/*      Little Endian                                                       */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_erode_bin,   ".text:optimized");

void IMG_erode_bin
(
    const unsigned char *restrict in_data, 
          unsigned char *restrict out_data, 
    const          char *restrict mask, 
    int                           cols
)
{
  int i;
  unsigned __int40_t p0l, p3l, p6l;
  unsigned m0, m1, m2, m3, m4, m5, m6, m7, m8;
  unsigned p0, p1, p2, p3, p4, p5, p6, p7, p8;
  unsigned rA, rB, rC, result;

  /* -------------------------------------------------------------------- */
  /*  "Don't care" values in mask become '1's for the ORing step.  We     */
  /*  do this by converting negative values to "-1" (all 1s in binary)    */
  /*  and converting positive values to 0.                                */
  /* -------------------------------------------------------------------- */
  m0 = mask[0] < 0 ? ~0U : 0;
  m1 = mask[1] < 0 ? ~0U : 0;
  m2 = mask[2] < 0 ? ~0U : 0;
  m3 = mask[3] < 0 ? ~0U : 0;
  m4 = mask[4] < 0 ? ~0U : 0;
  m5 = mask[5] < 0 ? ~0U : 0;
  m6 = mask[6] < 0 ? ~0U : 0;
  m7 = mask[7] < 0 ? ~0U : 0;
  m8 = mask[8] < 0 ? ~0U : 0;

  _nassert((int) cols % 4 == 0);

  #pragma MUST_ITERATE(2,,2);
  #pragma UNROLL(2);
  
  /* -------------------------------------------------------------------- */
  /*  Iterate over the input, processing 32 pixels per iteration.         */
  /* -------------------------------------------------------------------- */
  for (i=0; i<cols; i+=4) {
    /* ---------------------------------------------------------------- */
    /*  Load in our 34-bit by 3-bit context for applying the 3x3 mask.  */
    /* ---------------------------------------------------------------- */
    p0l = _dtol(_memd8_const(&in_data[i         ]));
    p3l = _dtol(_memd8_const(&in_data[i + cols  ]));
    p6l = _dtol(_memd8_const(&in_data[i + cols*2]));

    /* ---------------------------------------------------------------- */
    /*  Generate 3 offset copies of each row.                           */
    /* ---------------------------------------------------------------- */
    p0 = p0l;       p1 = p0l >> 1;       p2 = p0l >> 2;
    p3 = p3l;       p4 = p3l >> 1;       p5 = p3l >> 2;
    p6 = p6l;       p7 = p6l >> 1;       p8 = p6l >> 2;

    /* ---------------------------------------------------------------- */
    /*  Now sum the filtered pixels together by ANDing.                 */
    /* ---------------------------------------------------------------- */
    rA = p0 | m0;   rA &= p1 | m1;       if (!m2) rA &= p2;
    rB = p3 | m3;   if (!m4) rB &= p4;   if (!m5) rB &= p5;
    rC = p6 | m6;   if (!m7) rC &= p7;   if (!m8) rC &= p8;
    result = rA & rB & rC;

    /* ---------------------------------------------------------------- */
    /*  Write the result as four bytes.                                 */
    /* ---------------------------------------------------------------- */
    _mem4(&out_data[i]) = result;
  }
}

/* ======================================================================== */
/*  End of file:  IMG_erode_bin.c                                           */
/* ======================================================================== */
