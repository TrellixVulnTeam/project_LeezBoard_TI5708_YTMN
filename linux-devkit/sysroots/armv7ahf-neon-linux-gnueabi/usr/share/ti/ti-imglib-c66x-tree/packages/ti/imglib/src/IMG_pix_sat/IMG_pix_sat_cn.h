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

#ifndef IMG_PIX_SAT_CN_H_
#define IMG_PIX_SAT_CN_H_ 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_pix_sat_cn -- 16 to 8 bit conversion                            */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void IMG_pix_sat_cn                                                 */
/*      (                                                                   */
/*          int Size,                         // Number of pixels //        */
/*          const short   *restrict in_data,  // Incoming data    //        */
/*          unsigned char *restrict out_data  // Outgoing data    //        */
/*      )                                                                   */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*                                                                          */
/*      The function IMG_pix_sat() takes signed 16-bit input pixels and     */
/*      saturates them to unsigned 8-bit results.  Pixel values above       */
/*      255 are clamped to 255, and values below 0 are clamped to 0.        */
/*                                                                          */
/* ======================================================================== */

void IMG_pix_sat_cn
(
    int                     n,
    const short   *restrict in_data,
    unsigned char *restrict out_data
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_pix_sat_cn.h                                          */
/* ======================================================================== */
