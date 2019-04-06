/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

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

#include "blis.h"

extern scalm_t*   scalm_cntl;

blksz_t*          gemm_mc;
blksz_t*          gemm_nc;
blksz_t*          gemm_kc;
blksz_t*          gemm_mr;
blksz_t*          gemm_nr;
blksz_t*          gemm_kr;

blksz_t*          gemm_upanel_a_align;
blksz_t*          gemm_upanel_b_align;

func_t*           gemm_ukrs;

packm_t*          gemm_packa_cntl;
packm_t*          gemm_packb_cntl;

#ifdef BLIS_ENABLE_C66X_EDMA
dmam_t*			  gemm_dmaa_cntl;
dmam_t*			  gemm_dmab_cntl;
#endif

gemm_t*           gemm_cntl_bp_ke;
gemm_t*           gemm_cntl_op_bp;
gemm_t*           gemm_cntl_mm_op;
gemm_t*           gemm_cntl_vl_mm;

gemm_t*           gemm_cntl;

void bli_gemm_cntl_init()
{
	// Create blocksize objects for each dimension.
	gemm_mc
	=
	bli_blksz_obj_create( BLIS_DEFAULT_MC_S, BLIS_MAXIMUM_MC_S,
	                      BLIS_DEFAULT_MC_D, BLIS_MAXIMUM_MC_D,
	                      BLIS_DEFAULT_MC_C, BLIS_MAXIMUM_MC_C,
	                      BLIS_DEFAULT_MC_Z, BLIS_MAXIMUM_MC_Z );
	gemm_nc
	=
	bli_blksz_obj_create( BLIS_DEFAULT_NC_S, BLIS_MAXIMUM_NC_S,
	                      BLIS_DEFAULT_NC_D, BLIS_MAXIMUM_NC_D,
	                      BLIS_DEFAULT_NC_C, BLIS_MAXIMUM_NC_C,
	                      BLIS_DEFAULT_NC_Z, BLIS_MAXIMUM_NC_Z );
	gemm_kc
	=
	bli_blksz_obj_create( BLIS_DEFAULT_KC_S, BLIS_MAXIMUM_KC_S,
	                      BLIS_DEFAULT_KC_D, BLIS_MAXIMUM_KC_D,
	                      BLIS_DEFAULT_KC_C, BLIS_MAXIMUM_KC_C,
	                      BLIS_DEFAULT_KC_Z, BLIS_MAXIMUM_KC_Z );
	gemm_mr
	=
	bli_blksz_obj_create( BLIS_DEFAULT_MR_S, BLIS_PACKDIM_MR_S,
	                      BLIS_DEFAULT_MR_D, BLIS_PACKDIM_MR_D,
	                      BLIS_DEFAULT_MR_C, BLIS_PACKDIM_MR_C,
	                      BLIS_DEFAULT_MR_Z, BLIS_PACKDIM_MR_Z );
	gemm_nr
	=
	bli_blksz_obj_create( BLIS_DEFAULT_NR_S, BLIS_PACKDIM_NR_S,
	                      BLIS_DEFAULT_NR_D, BLIS_PACKDIM_NR_D,
	                      BLIS_DEFAULT_NR_C, BLIS_PACKDIM_NR_C,
	                      BLIS_DEFAULT_NR_Z, BLIS_PACKDIM_NR_Z );
	gemm_kr
	=
	bli_blksz_obj_create( BLIS_DEFAULT_KR_S, BLIS_PACKDIM_KR_S,
	                      BLIS_DEFAULT_KR_D, BLIS_PACKDIM_KR_D,
	                      BLIS_DEFAULT_KR_C, BLIS_PACKDIM_KR_C,
	                      BLIS_DEFAULT_KR_Z, BLIS_PACKDIM_KR_Z );


	// Create objects for micro-panel alignment (in bytes).
	gemm_upanel_a_align
	=
	bli_blksz_obj_create( BLIS_UPANEL_A_ALIGN_SIZE_S, 0,
	                      BLIS_UPANEL_A_ALIGN_SIZE_D, 0,
	                      BLIS_UPANEL_A_ALIGN_SIZE_C, 0,
	                      BLIS_UPANEL_A_ALIGN_SIZE_Z, 0 );
	gemm_upanel_b_align
	=
	bli_blksz_obj_create( BLIS_UPANEL_B_ALIGN_SIZE_S, 0,
	                      BLIS_UPANEL_B_ALIGN_SIZE_D, 0,
	                      BLIS_UPANEL_B_ALIGN_SIZE_C, 0,
	                      BLIS_UPANEL_B_ALIGN_SIZE_Z, 0 );


	// Attach the register blksz_t objects as blocksize multiples to the cache
	// blksz_t objects.
	bli_blksz_obj_attach_to( gemm_mr, gemm_mc );
	bli_blksz_obj_attach_to( gemm_nr, gemm_nc );
	bli_blksz_obj_attach_to( gemm_kr, gemm_kc );

	//bli_blksz_obj_attach_mult_to( gemm_mr, gemm_mc );
	//bli_blksz_obj_attach_mult_to( gemm_nr, gemm_nc );
	//bli_blksz_obj_attach_mult_to( gemm_kr, gemm_kc );


	// Attach the mr and nr blksz_t objects to each cache blksz_t object.
	// The primary example of why this is needed relates to nudging kc.
	// In hemm, symm, trmm, or trmm3, we need to know both mr and nr,
	// since the multiple we target in nudging depends on whether the
	// structured matrix is on the left or the right.
	//bli_blksz_obj_attach_mr_nr_to( gemm_mr, gemm_nr, gemm_mc );
	//bli_blksz_obj_attach_mr_nr_to( gemm_mr, gemm_nr, gemm_nc );
	//bli_blksz_obj_attach_mr_nr_to( gemm_mr, gemm_nr, gemm_kc );

	// Create function pointer object for each datatype-specific gemm
	// micro-kernel.
	gemm_ukrs
	=
	bli_func_obj_create( BLIS_SGEMM_UKERNEL, BLIS_SGEMM_UKERNEL_PREFERS_CONTIG_ROWS,
	                     BLIS_DGEMM_UKERNEL, BLIS_DGEMM_UKERNEL_PREFERS_CONTIG_ROWS,
	                     BLIS_CGEMM_UKERNEL, BLIS_CGEMM_UKERNEL_PREFERS_CONTIG_ROWS,
	                     BLIS_ZGEMM_UKERNEL, BLIS_ZGEMM_UKERNEL_PREFERS_CONTIG_ROWS );

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
	// Create control tree objects for packm operations.
	gemm_packa_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           gemm_mr,
	                           gemm_kr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_ROW_PANELS,
	                           BLIS_BUFFER_FOR_A_BLOCK_L2 );

	gemm_packb_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           gemm_kr,
	                           gemm_nr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_COL_PANELS,
	                           BLIS_BUFFER_FOR_B_PANEL_L3 );
#else

	// Create control tree objects for packm operations.
	gemm_packa_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           gemm_mr,
	                           gemm_kr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_ROW_PANELS,
	                           BLIS_BUFFER_FOR_A_BLOCK );

	gemm_packb_cntl
	=
	bli_packm_cntl_obj_create( BLIS_BLOCKED,
	                           BLIS_VARIANT1,
	                           gemm_kr,
	                           gemm_nr,
	                           FALSE, // do NOT invert diagonal
	                           FALSE, // reverse iteration if upper?
	                           FALSE, // reverse iteration if lower?
	                           BLIS_PACKED_COL_PANELS,
	                           BLIS_BUFFER_FOR_B_PANEL );

#endif

#ifdef BLIS_ENABLE_C66X_EDMA
	// Creating control tree object for DMA operations
	gemm_dmaa_cntl = bli_dmam_cntl_obj_create (BLIS_BLOCKED,
											BLIS_VARIANT1,
											gemm_mc, gemm_kc,
											BLIS_BUFFER_FOR_A_BLOCK_L2);

	gemm_dmab_cntl = bli_dmam_cntl_obj_create (BLIS_BLOCKED,
											BLIS_VARIANT1,
											gemm_kc, gemm_nc,
											BLIS_BUFFER_FOR_B_PANEL_L3);

#endif
	//
	// Create a control tree for packing A and B, and streaming C.
	//

#ifdef BLIS_ENABLE_C66X_EDMA
	// Create control tree object for lowest-level block-panel kernel.
		gemm_cntl_bp_ke
		=
		bli_gemm_cntl_obj_create( BLIS_UNB_OPT,
		                          BLIS_VARIANT2,
		                          NULL,
		                          gemm_ukrs,
		                          NULL, NULL, NULL, NULL,
		                          NULL,
		                          NULL,
		                          NULL,
		                          NULL, NULL );


		gemm_cntl_op_bp
		=
		bli_gemm_cntl_obj_create( BLIS_BLOCKED,
		                          BLIS_VARIANT1,
		                          gemm_mc,
		                          gemm_ukrs,
		                          NULL,
		                          gemm_packa_cntl,
		                          NULL, //gemm_packb_cntl, //
		                          NULL,
		                          BLIS_GEMM_DMAA_CNTL, //gemm_dmaa_cntl, //
		                          NULL, //gemm_dmab_cntl, //
		                          NULL,
		                          gemm_cntl_bp_ke,
		                          NULL );

		// Create control tree object for general problem via multiple
		// rank-k (outer panel) updates.
		gemm_cntl_mm_op
		=
		bli_gemm_cntl_obj_create( BLIS_BLOCKED,
		                          BLIS_VARIANT3,
		                          gemm_kc,
		                          gemm_ukrs,
		                          NULL,
		                          NULL,
		                          gemm_packb_cntl, //NULL, //
		                          NULL,
		                          NULL,
		                          BLIS_GEMM_DMAB_CNTL, // gemm_dmab_cntl, //NULL, //
		                          NULL,
		                          gemm_cntl_op_bp,
		                          NULL );

		// Create control tree object for very large problem via multiple
		// general problems.
		gemm_cntl_vl_mm
		=
		bli_gemm_cntl_obj_create( BLIS_BLOCKED,
		                          BLIS_VARIANT2,
		                          gemm_nc,
		                          gemm_ukrs,
		                          NULL,
		                          NULL,
		                          NULL,
		                          NULL,
		                          NULL,
		                          NULL,
		                          NULL,
		                          gemm_cntl_mm_op,
		                          NULL );

		// Alias the "master" gemm control tree to a shorter name.
		gemm_cntl = gemm_cntl_vl_mm;


#else
	// Create control tree object for lowest-level block-panel kernel.
	gemm_cntl_bp_ke
	=
	bli_gemm_cntl_obj_create( BLIS_UNB_OPT,
	                          BLIS_VARIANT2,
	                          NULL,
	                          gemm_ukrs,
	                          NULL, NULL, NULL,
	                          NULL, NULL, NULL );

	// Create control tree object for outer panel (to block-panel)
	// problem.
	gemm_cntl_op_bp
	=
	bli_gemm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT1,
	                          gemm_mc,
	                          gemm_ukrs,
	                          NULL,
	                          gemm_packa_cntl,
	                          gemm_packb_cntl,
	                          NULL,
	                          gemm_cntl_bp_ke,
	                          NULL );

	// Create control tree object for general problem via multiple
	// rank-k (outer panel) updates.
	gemm_cntl_mm_op
	=
	bli_gemm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT3,
	                          gemm_kc,
	                          gemm_ukrs,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          gemm_cntl_op_bp,
	                          NULL );

	// Create control tree object for very large problem via multiple
	// general problems.
	gemm_cntl_vl_mm
	=
	bli_gemm_cntl_obj_create( BLIS_BLOCKED,
	                          BLIS_VARIANT2,
	                          gemm_nc,
	                          gemm_ukrs,
	                          NULL,
	                          NULL,
	                          NULL,
	                          NULL,
	                          gemm_cntl_mm_op,
	                          NULL );

	// Alias the "master" gemm control tree to a shorter name.
	gemm_cntl = gemm_cntl_vl_mm;
#endif
}

void bli_gemm_cntl_finalize()
{
	bli_blksz_obj_free( gemm_mc );
	bli_blksz_obj_free( gemm_nc );
	bli_blksz_obj_free( gemm_kc );
	bli_blksz_obj_free( gemm_mr );
	bli_blksz_obj_free( gemm_nr );
	bli_blksz_obj_free( gemm_kr );

	bli_blksz_obj_free( gemm_upanel_a_align );
	bli_blksz_obj_free( gemm_upanel_b_align );

	bli_func_obj_free( gemm_ukrs );

	bli_cntl_obj_free( gemm_packa_cntl );
	bli_cntl_obj_free( gemm_packb_cntl );

#ifdef BLIS_ENABLE_C66X_EDMA
	bli_cntl_obj_free(gemm_dmaa_cntl);
	bli_cntl_obj_free(gemm_dmab_cntl);
#endif

	bli_cntl_obj_free( gemm_cntl_bp_ke );
	bli_cntl_obj_free( gemm_cntl_op_bp );
	bli_cntl_obj_free( gemm_cntl_mm_op );
	bli_cntl_obj_free( gemm_cntl_vl_mm );
}

#ifdef BLIS_ENABLE_C66X_EDMA
gemm_t* bli_gemm_cntl_obj_create( impl_t     impl_type,
                                  varnum_t   var_num,
                                  blksz_t*   b,
                                  func_t*    gemm_ukrs_,
                                  scalm_t*   sub_scalm,
                                  packm_t*   sub_packm_a,
                                  packm_t*   sub_packm_b,
                                  packm_t*   sub_packm_c,
                                  dmam_t*	 sub_dma_a,
                                  dmam_t*	 sub_dma_b,
                                  dmam_t*	 sub_dma_c,
                                  gemm_t*    sub_gemm,
                                  unpackm_t* sub_unpackm_c )
{
	gemm_t* cntl;

	cntl = ( gemm_t* ) bli_malloc( sizeof(gemm_t) );

	cntl->impl_type     = impl_type;
	cntl->var_num       = var_num;
	cntl->b             = b;
	cntl->gemm_ukrs     = gemm_ukrs_; // avoid name conflict with global symbol
	cntl->sub_scalm     = sub_scalm;
	cntl->sub_packm_a   = sub_packm_a;
	cntl->sub_packm_b   = sub_packm_b;
	cntl->sub_packm_c   = sub_packm_c;
	cntl->sub_dmam_a    = sub_dma_a;
	cntl->sub_dmam_b    = sub_dma_b;
	cntl->sub_dmam_c    = sub_dma_c;
	cntl->sub_gemm      = sub_gemm;
	cntl->sub_unpackm_c = sub_unpackm_c;

	return cntl;
}

#else

gemm_t* bli_gemm_cntl_obj_create( impl_t     impl_type,
                                  varnum_t   var_num,
                                  blksz_t*   b,
                                  func_t*    gemm_ukrs_,
                                  scalm_t*   sub_scalm,
                                  packm_t*   sub_packm_a,
                                  packm_t*   sub_packm_b,
                                  packm_t*   sub_packm_c,
                                  gemm_t*    sub_gemm,
                                  unpackm_t* sub_unpackm_c )
{
	gemm_t* cntl;

	cntl = ( gemm_t* ) bli_malloc( sizeof(gemm_t) );

	cntl->impl_type     = impl_type;
	cntl->var_num       = var_num;
	cntl->b             = b;
	cntl->gemm_ukrs     = gemm_ukrs_; // avoid name conflict with global symbol
	cntl->sub_scalm     = sub_scalm;
	cntl->sub_packm_a   = sub_packm_a;
	cntl->sub_packm_b   = sub_packm_b;
	cntl->sub_packm_c   = sub_packm_c;
	cntl->sub_gemm      = sub_gemm;
	cntl->sub_unpackm_c = sub_unpackm_c;

	return cntl;
}
#endif

