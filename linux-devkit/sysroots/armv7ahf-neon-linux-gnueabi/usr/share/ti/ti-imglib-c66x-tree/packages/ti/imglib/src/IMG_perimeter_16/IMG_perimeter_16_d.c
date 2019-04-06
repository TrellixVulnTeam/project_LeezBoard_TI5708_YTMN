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

#include <stdio.h>
#include <ti/imglib/src/common/IMG_profile.h>
#include <ti/imglib/src/common/IMG_memory.h>
#include "IMG_perimeter_16.h"
#include "IMG_perimeter_16_cn.h"

#define N 80
#define PAD 32
#define I_N (N*3)
#define I_SIZE (I_N + 2*PAD)
#define O_SIZE (N + 2*PAD)

typedef unsigned short I_type;
typedef unsigned short O_type;

I_type input[I_SIZE];
O_type output[O_SIZE];
O_type ref_output[O_SIZE];


main()
{
  int in_size, out_size;
  short align_in, align_out;
  I_type *src_ptr;
  O_type *output_ptr, *ref_output_ptr;
  int found, found_ref;
  int cols;

  int *inp  = &in_data[0];
  int *outp = &out_data[0];

  align_in  = *inp++;
  align_out = *inp++;

  src_ptr        = (I_type *)((unsigned int) &input[PAD]      + align_in);
  output_ptr     = (O_type *)((unsigned int) &output[PAD]     + align_out);
  ref_output_ptr = (O_type *)((unsigned int) &ref_output[PAD] + align_out);

  /* Initialize profiling */
  IMG_profile_init (2, "IMG_perimeter_16");

  for (test_index=1; test_index<=testcases; test_index++) {
    est_test  = *inp++;
    cols      = *inp++;
    in_size   = *inp++;
    out_size  = *inp++;
    found_ref = *inp++;

    /* Check memory allocation */
    IMG_assert ((I_N >= in_size), "Insufficient memory allocated (in_size)");

    /* Prepare output arrays */
    IMG_clear_memory (input,      sizeof(input));
    IMG_clear_memory (ref_output, sizeof(ref_output));

    /* Copy input and ref output to respective buffers */
    IMG_copy_int_to_ushort (src_ptr,        inp,  in_size);
    IMG_copy_int_to_ushort (ref_output_ptr, outp, out_size);
    inp  += in_size;
    outp += out_size;

    /* Test optimized kernel */
    IMG_clear_memory  (output, sizeof(output));
    IMG_profile_start (img_KERNEL_OPT);
    found = IMG_perimeter_16 (src_ptr + cols, cols, output_ptr);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) output, (void *) ref_output, sizeof(ref_output));
    IMG_assert        ((found == found_ref), "Pixels found failure");

    /* Test natural C kernel */
    IMG_clear_memory  (output, sizeof(output));
    IMG_profile_start (img_KERNEL_CN);
    found = IMG_perimeter_16_cn (src_ptr + cols, cols, output_ptr);
    IMG_profile_stop  ();
    IMG_compare_mem   ((void *) output, (void *) ref_output, sizeof(ref_output));
    IMG_assert        ((found == found_ref), "Pixels found failure");

    /* Profile display and preparation for cycle estimation */
    IMG_formula_add_test (cols, NULL, NULL);
  } /* for */

  /* Calculate and display cycle formula (and testing success) */
  IMG_profile_cycle_formula ();
  IMG_profile_cycle_info    ("N = Columns");
  
  /* Provide memory requirements */
  IMG_kernel_memory ();
}
