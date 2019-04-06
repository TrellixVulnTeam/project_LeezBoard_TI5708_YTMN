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
/*      IMG_errdif_bin_8                                                    */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable, and has the following C prototype:      */
/*                                                                          */
/*              void IMG_errdif_bin_8                                       */
/*              (                                                           */
/*                  unsigned char *restrict errdif_data,                    */
/*                  int           cols,                                     */
/*                  int           rows,                                     */
/*                  short         *restrict err_buf,                        */
/*                  unsigned char thresh                                    */
/*              )                                                           */
/*                                                                          */
/*      errdif_data:     Input/Output image ptr                             */
/*      cols:            Number of columns (Width)                          */
/*      rows:            Number of rows    (Height)                         */
/*      err_buf[cols+1]: Buffer where one row of errors is to be saved      */
/*      thresh:          Threshold in the range [0x00, 0xFF]                */
/*                                                                          */
/*      errdif_data[] is used for both input and output.                    */
/*                                                                          */
/*      err_buf[], additional buffer, should be provided with               */
/*      initialized to all-zero's for the first call with an image.         */
/*      The subsequent call with the same image should provide this         */
/*      kernel the returned err_buf The size of err_buf should be           */
/*      (cols+1)*Half-Word.                                                 */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The code implements the Binary Floyd-Steinberg error diffusion      */
/*      filter.  The filter kernel used is this one:                        */
/*                                                                          */
/*                                  +---+                                   */
/*                                P | 7 |                                   */
/*                          +---+---+---+                                   */
/*                          | 3 | 5 | 1 |                                   */
/*                          +---+---+---+                                   */
/*                                                                          */
/*                                                                          */
/*      Pixels are processed from left-to-right, top-to-bottom.  Each       */
/*      pixel is compared against a user-defined threshold.  Pixels         */
/*      that are larger than the threshold are set to 255, and pixels       */
/*      that are smaller or equal to the threshold are set to 0.  The       */
/*      error value for the pixel (eg. the difference between the           */
/*      thresholded pixel and its original grey level) is propagated to     */
/*      the neighboring pixels according to the filter above.  This         */
/*      error propagation diffuses the error over a larger area, hence      */
/*      the term "error diffusion."                                         */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The processing of the filter itself is inverted so that the         */
/*      errors from previous pixels "propagate into" a given pixel at       */
/*      the time the pixel is processed, rather than "accumulate into"      */
/*      a pixel as its neighbors are processed.  This allows us to          */
/*      keep our image as an 8-bit image, and reduces the number of         */
/*      accesses to the image array.  The inverted filter kernel            */
/*      performs identically to the kernel's original form.  In this        */
/*      form, the weights specify the weighting assigned to the errors      */
/*      coming from the neighboring pixels.                                 */
/*                                                                          */
/*                          +---+---+---+                                   */
/*                          | 1 | 5 | 3 |                                   */
/*                          +---+---+---+                                   */
/*                          | 7 | P                                         */
/*                          +---+                                           */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      err_buf[] must be initialized to zeros for the first call and       */
/*      the returned err_buf should be provided for the next call.          */
/*                                                                          */
/*  SOURCE                                                                  */
/*      Floyd-Steinberg Error Diffusion.                                    */
/*                                                                          */
/* ======================================================================== */

#pragma CODE_SECTION(IMG_errdif_bin_8, ".text:optimized");

void IMG_errdif_bin_8
(
    unsigned char *restrict errdif_data, /* Input/Output image ptr       */
    int           cols,                  /* Number of columns (Width)    */
    int           rows,                  /* Number of rows    (Height)   */
    short         *restrict err_buf,     /* row-to-row error buffer.     */
    unsigned char thresh                 /* Threshold from [0x00, 0xFF]  */
)
{
    int   x, i, y;                /* Loop counters                       */
    int   F;                      /* Current pixel value at [x,y]        */
    int   errA;                   /* Error value at [x-1, y-1]           */
    int   errB;                   /* Error value at [  x, y-1]           */
    int   errC;                   /* Error value at [x+1, y-1]           */
    int   errE;                   /* Error value at [x-1,   y]           */
    int   errsum;                 /* Sum of all errors                   */

    /*-------------------------------------------------------------------*/
    /* Note: F is the current pixel                                      */
    /* For the first pixel of each line, errA and errE are set to zero   */
    /* and read errB. For the subsequent pixels, only errC is read and   */
    /* other errors come from prev pixel processing                      */
    /*-------------------------------------------------------------------*/

    for (y = 0, i = 0; y < rows; y++) {
        /* ----------------------------------------------------- */
        /*  Start off with our initial errors set to zero at the */
        /*  start of the line since we do not have any pixels to */
        /*  the left of the row.  These error terms are          */
        /*  maintained within the inner loop.                    */
        /* ----------------------------------------------------- */
        errA = 0; errE = 0;
        errB = err_buf[0];  

        /* ----------------------------------------------------- */
        /*  Step through pixels in each row.                     */
        /* ----------------------------------------------------- */
        for (x = 0; x < cols; x++, i++) {
            /* ------------------------------------------------- */
            /*  Load the error being propagated from pixel 'C'   */
            /*  from our error buffer.  This was calculated      */
            /*  during the previous line.                        */
            /* ------------------------------------------------- */
            errC = err_buf[x+1];
 
            /* ------------------------------------------------- */
            /*  Load our pixel value to quantize.                */
            /* ------------------------------------------------- */
            F = errdif_data[i];

            /* ------------------------------------------------- */
            /*  Calculate our resulting pixel.  If we assume     */
            /*  that this pixel will be set to zero, this also   */
            /*  doubles as our error term.                       */
            /*  errE = F + ((errE*7+errA+errB*5+errC*3)>>4);     */
            /* ------------------------------------------------- */
            errsum  = errE*7 + errA;
            errsum += errB*5;
            errsum += errC*3;
            errsum >>= 4;
            errE = F + errsum;
    
            /* ------------------------------------------------- */
            /*  Set pixels that are larger than the threshold to */
            /*  255, and pixels that are smaller than the        */
            /*  threshold to 0.                                  */
            /* ------------------------------------------------- */
            errdif_data[i] = (thresh <= (errE - 1)) * 0xFF;   

            /* ------------------------------------------------- */
            /*  If the pixel was larger than the threshold, then */
            /*  we need subtract 255 from our error.  In any     */
            /*  case, store the error to the error buffer.       */
            /* ------------------------------------------------- */
            if (errE > thresh)  errE = errE - 0xFF;

            err_buf[x] = errE;

            /* ------------------------------------------------- */
            /*  Propagate error terms for the next pixel.        */
            /* ------------------------------------------------- */
            errA = errB;
            errB = errC;
        }
    }
}

/* ======================================================================== */
/*  End of file:  IMG_errdif_bin_8.c                                        */
/* ======================================================================== */
