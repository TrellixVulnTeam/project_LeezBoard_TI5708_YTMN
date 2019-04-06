/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef BLIS_KERNEL_H
#define BLIS_KERNEL_H

// -- LEVEL-3 MICRO-KERNEL CONSTANTS -------------------------------------------

// -- Cache blocksizes --

//
// Constraints:
//
// (1) MC must be a multiple of:
//     (a) MR (for zero-padding purposes)
//     (b) NR (for zero-padding purposes when MR and NR are "swapped")
// (2) NC must be a multiple of
//     (a) NR (for zero-padding purposes)
//     (b) MR (for zero-padding purposes when MR and NR are "swapped")
// (3) KC must be a multiple of
//     (a) MR and
//     (b) NR (for triangular operations such as trmm and trsm).
//

#if defined(MEM_MODEL_LARGE)
#define BLIS_DEFAULT_MC_S              144
#define BLIS_DEFAULT_KC_S              428
#define BLIS_DEFAULT_NC_S              944

#define BLIS_DEFAULT_MC_D              132
#define BLIS_DEFAULT_KC_D              220
#define BLIS_DEFAULT_NC_D              864

#define BLIS_DEFAULT_MC_C              124
#define BLIS_DEFAULT_KC_C              260
#define BLIS_DEFAULT_NC_C              824

#define BLIS_DEFAULT_MC_Z              90
#define BLIS_DEFAULT_KC_Z              178
#define BLIS_DEFAULT_NC_Z              588

#define BLIS_DEFAULT_4M_MC_C           96
#define BLIS_DEFAULT_4M_KC_C           220
#define BLIS_DEFAULT_4M_NC_C           664

#define BLIS_DEFAULT_4M_MC_Z           90
#define BLIS_DEFAULT_4M_KC_Z           100
#define BLIS_DEFAULT_4M_NC_Z           520

#define BLIS_DEFAULT_3M_MC_C           64
#define BLIS_DEFAULT_3M_KC_C           220
#define BLIS_DEFAULT_3M_NC_C           100

#define BLIS_DEFAULT_3M_MC_Z           60
#define BLIS_DEFAULT_3M_KC_Z           100
#define BLIS_DEFAULT_3M_NC_Z           100

#elif defined (MEM_MODEL_MEDIUM)
#define BLIS_DEFAULT_MC_S              128
#define BLIS_DEFAULT_KC_S              440 
#define BLIS_DEFAULT_NC_S              1224

#define BLIS_DEFAULT_MC_D              120
#define BLIS_DEFAULT_KC_D              220
#define BLIS_DEFAULT_NC_D              1184

#define BLIS_DEFAULT_MC_C              116
#define BLIS_DEFAULT_KC_C              260
#define BLIS_DEFAULT_NC_C              1008

#define BLIS_DEFAULT_MC_Z              86
#define BLIS_DEFAULT_KC_Z              178
#define BLIS_DEFAULT_NC_Z              736

#define BLIS_DEFAULT_4M_MC_C           128
#define BLIS_DEFAULT_4M_KC_C           224
#define BLIS_DEFAULT_4M_NC_C           1184

#define BLIS_DEFAULT_4M_MC_Z           84
#define BLIS_DEFAULT_4M_KC_Z           168
#define BLIS_DEFAULT_4M_NC_Z           736

#define BLIS_DEFAULT_3M_MC_C           88
#define BLIS_DEFAULT_3M_KC_C           200
#define BLIS_DEFAULT_3M_NC_C           792

#define BLIS_DEFAULT_3M_MC_Z           56
#define BLIS_DEFAULT_3M_KC_Z           168
#define BLIS_DEFAULT_3M_NC_Z           488

#elif defined(MEM_MODEL_SMALL)

#define BLIS_DEFAULT_MC_S              128
#define BLIS_DEFAULT_KC_S              224
#define BLIS_DEFAULT_NC_S              1024

#define BLIS_DEFAULT_MC_D              80
#define BLIS_DEFAULT_KC_D              180
#define BLIS_DEFAULT_NC_D              720

#define BLIS_DEFAULT_MC_C              64
#define BLIS_DEFAULT_KC_C              180
#define BLIS_DEFAULT_NC_C              540

#define BLIS_DEFAULT_MC_Z              32
#define BLIS_DEFAULT_KC_Z              145
#define BLIS_DEFAULT_NC_Z              306

#define BLIS_DEFAULT_4M_MC_C           64
#define BLIS_DEFAULT_4M_KC_C           180
#define BLIS_DEFAULT_4M_NC_C           540

#define BLIS_DEFAULT_4M_MC_Z           32
#define BLIS_DEFAULT_4M_KC_Z           145
#define BLIS_DEFAULT_4M_NC_Z           306

#define BLIS_DEFAULT_3M_MC_C           64
#define BLIS_DEFAULT_3M_KC_C           96
#define BLIS_DEFAULT_3M_NC_C           488

#define BLIS_DEFAULT_3M_MC_Z           36
#define BLIS_DEFAULT_3M_KC_Z           108
#define BLIS_DEFAULT_3M_NC_Z           196

#endif

// -- Register blocksizes --
// same for different memory models (C66x architecture), need to redefine for C7x
#define BLIS_DEFAULT_MR_S              4
#define BLIS_DEFAULT_NR_S              8 //4 //

#define BLIS_DEFAULT_MR_D              4
#define BLIS_DEFAULT_NR_D              4

#define BLIS_DEFAULT_MR_C              2
#define BLIS_DEFAULT_NR_C              4

#define BLIS_DEFAULT_MR_Z              1
#define BLIS_DEFAULT_NR_Z              1


// NOTE: If the micro-kernel, which is typically unrolled to a factor
// of f, handles leftover edge cases (ie: when k % f > 0) then these
// register blocksizes in the k dimension can be defined to 1.

//#define BLIS_DEFAULT_KR_S              1
//#define BLIS_DEFAULT_KR_D              1
//#define BLIS_DEFAULT_KR_C              1
//#define BLIS_DEFAULT_KR_Z              1

// -- Cache blocksize extensions (for optimizing edge cases) --

// NOTE: These cache blocksize "extensions" have the same constraints as
// the corresponding default blocksizes above. When these values are
// non-zero, blocksizes used at edge cases are extended (enlarged) if
// such an extension would encompass the remaining portion of the
// matrix dimension.

//#define BLIS_EXTEND_MC_S               0 //(BLIS_DEFAULT_MC_S/4)
//#define BLIS_EXTEND_KC_S               0 //(BLIS_DEFAULT_KC_S/4)
//#define BLIS_EXTEND_NC_S               0 //(BLIS_DEFAULT_NC_S/4)

//#define BLIS_EXTEND_MC_D               0 //(BLIS_DEFAULT_MC_D/4)
//#define BLIS_EXTEND_KC_D               0 //(BLIS_DEFAULT_KC_D/4)
//#define BLIS_EXTEND_NC_D               0 //(BLIS_DEFAULT_NC_D/4)

//#define BLIS_EXTEND_MC_C               0 //(BLIS_DEFAULT_MC_C/4)
//#define BLIS_EXTEND_KC_C               0 //(BLIS_DEFAULT_KC_C/4)
//#define BLIS_EXTEND_NC_C               0 //(BLIS_DEFAULT_NC_C/4)

//#define BLIS_EXTEND_MC_Z               0 //(BLIS_DEFAULT_MC_Z/4)
//#define BLIS_EXTEND_KC_Z               0 //(BLIS_DEFAULT_KC_Z/4)
//#define BLIS_EXTEND_NC_Z               0 //(BLIS_DEFAULT_NC_Z/4)

// -- Register blocksize extensions (for packed micro-panels) --

// NOTE: These register blocksize "extensions" determine whether the
// leading dimensions used within the packed micro-panels are equal to
// or greater than their corresponding register blocksizes above.

//#define BLIS_EXTEND_MR_S               0
//#define BLIS_EXTEND_NR_S               0

//#define BLIS_EXTEND_MR_D               0
//#define BLIS_EXTEND_NR_D               0

//#define BLIS_EXTEND_MR_C               0
//#define BLIS_EXTEND_NR_C               0

//#define BLIS_EXTEND_MR_Z               0
//#define BLIS_EXTEND_NR_Z               0



// -- LEVEL-2 KERNEL CONSTANTS -------------------------------------------------




// -- LEVEL-1F KERNEL CONSTANTS ------------------------------------------------




// -- LEVEL-3 KERNEL DEFINITIONS -----------------------------------------------

// -- gemm --
#define BLIS_SGEMM_UKERNEL         bli_sgemm_ukernel_4x8
#define BLIS_DGEMM_UKERNEL         bli_dgemm_ukernel_4x4
#define BLIS_CGEMM_UKERNEL         bli_cgemm_ukernel_2x4
#define BLIS_ZGEMM_UKERNEL         bli_zgemm_ukernel_2x2

// -- trsm-related --
#define BLIS_SGEMMTRSM_U_UKERNEL bli_sgemmtrsm_u_ukernel_4x4
#define BLIS_SGEMMTRSM_L_UKERNEL bli_sgemmtrsm_l_ukernel_4x4

#define BLIS_STRSM_U_UKERNEL bli_strsm_u_ukernel_4x4
#define BLIS_STRSM_L_UKERNEL bli_strsm_l_ukernel_4x4


// -- LEVEL-1M KERNEL DEFINITIONS ----------------------------------------------

// -- packm --
#define BLIS_SPACKM_4XK_KERNEL bli_spackm_4xk_ukernel
#define BLIS_SPACKM_8XK_KERNEL bli_spackm_8xk_ukernel

// -- unpackm --




// -- LEVEL-1F KERNEL DEFINITIONS ----------------------------------------------

// -- axpy2v --

// -- dotaxpyv --

// -- axpyf --

// -- dotxf --

// -- dotxaxpyf --




// -- LEVEL-1V KERNEL DEFINITIONS ----------------------------------------------

// -- addv --

// -- axpyv --

// -- copyv --

// -- dotv --

// -- dotxv --

// -- invertv --

// -- scal2v --

// -- scalv --

// -- setv --

// -- subv --

// -- swapv --

// adding packm micro kernel prototypes
#include "bli_packm_cxk_ukernels.h"

// Declaration for bli_sgemm_ukernel_4x4 which is used by gemmtrsm ukernel
void bli_sgemm_ukernel_4x4(
                        dim_t              k,
                        float*    restrict alpha,
                        float*    restrict a,
                        float*    restrict b,
                        float*    restrict beta,
                        float*    restrict c, inc_t rs_c, inc_t cs_c,
                        auxinfo_t*         data
                      );

#endif

