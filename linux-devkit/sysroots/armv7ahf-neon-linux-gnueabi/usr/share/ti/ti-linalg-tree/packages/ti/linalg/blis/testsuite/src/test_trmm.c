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
#include "test_libblis.h"


// Static variables.
static char*     op_str                    = "trmm";
static char*     o_types                   = "mm";   // a b
static char*     p_types                   = "suhd"; // side uploa transa diaga
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_trmm_deps( test_params_t* params,
                             test_op_t*     op );

void libblis_test_trmm_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid );

void libblis_test_trmm_impl( iface_t   iface,
                             side_t    side,
                             obj_t*    alpha,
                             obj_t*    a,
                             obj_t*    b );

void libblis_test_trmm_check( side_t  side,
                              obj_t*  alpha,
                              obj_t*  a,
                              obj_t*  b,
                              obj_t*  b_orig,
                              double* resid );



void libblis_test_trmm_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_randv( params, &(op->ops->randv) );
	libblis_test_randm( params, &(op->ops->randm) );
	libblis_test_setv( params, &(op->ops->setv) );
	libblis_test_normfv( params, &(op->ops->normfv) );
	libblis_test_subv( params, &(op->ops->subv) );
	libblis_test_scalv( params, &(op->ops->scalv) );
	libblis_test_copym( params, &(op->ops->copym) );
	libblis_test_scalm( params, &(op->ops->scalm) );
	libblis_test_gemv( params, &(op->ops->gemv) );
	libblis_test_trmv( params, &(op->ops->trmv) );
}



void libblis_test_trmm( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l3_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_trmm_deps( params, op );

	// Execute the test driver for each implementation requested.
	if ( op->front_seq == ENABLE )
	{
		libblis_test_op_driver( params,
		                        op,
		                        BLIS_TEST_SEQ_FRONT_END,
		                        op_str,
		                        p_types,
		                        o_types,
		                        thresh,
		                        libblis_test_trmm_experiment );
	}
}



void libblis_test_trmm_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid )
{
	unsigned int n_repeats = params->n_repeats;
	unsigned int i;

	double       time_min  = 1e9;
	double       time;

	dim_t        m, n;
	dim_t        mn_side;

	side_t       side;
	uplo_t       uploa;
	trans_t      transa;
	diag_t       diaga;

	obj_t        kappa;
	obj_t        alpha, a;
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	dim_t 		 test_way = bli_read_nway_from_env( "BLIS_LB_NT" );
	obj_t	     b[test_way];
	obj_t        b_save[test_way];
	double       resid_local[test_way];
	unsigned int j;
#else
	obj_t        b, b_save;
#endif


	// Map the dimension specifier to actual dimensions.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );
	n = libblis_test_get_dim_from_prob_size( op->dim_spec[1], p_cur );

	// Map parameter characters to BLIS constants.
	bli_param_map_char_to_blis_side( pc_str[0], &side );
	bli_param_map_char_to_blis_uplo( pc_str[1], &uploa );
	bli_param_map_char_to_blis_trans( pc_str[2], &transa );
	bli_param_map_char_to_blis_diag( pc_str[3], &diaga );

	// Create test scalars.
	bli_obj_scalar_init_detached( datatype, &kappa );
	bli_obj_scalar_init_detached( datatype, &alpha );

	// Create test operands (vectors and/or matrices).
	bli_set_dim_with_side( side, m, n, mn_side );
	libblis_test_mobj_create( params, datatype, transa,
	                          sc_str[0], mn_side, mn_side, &a );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
		                          sc_str[1], m,       n,       &b[i] );
		libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
		                          sc_str[1], m,       n,       &b_save[i] );
	}
#else
	libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
	                          sc_str[1], m,       n,       &b );
	libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
	                          sc_str[1], m,       n,       &b_save );
#endif


	// Set alpha and beta.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	if ( bli_obj_is_real( b[0] ) )
#else
	if ( bli_obj_is_real( b ) )
#endif
	{
		bli_setsc(  0.8,  0.0, &alpha );
	}
	else
	{
		bli_setsc(  0.8,  0.5, &alpha );
	}

	// Set the structure and uplo properties of A.
	bli_obj_set_struc( BLIS_TRIANGULAR, a );
	bli_obj_set_uplo( uploa, a );

	// Randomize A, make it densely triangular.
	bli_randm( &a );
	bli_mktrim( &a );
	//bli_setsc( 0.5, 0.0, &kappa );
	//bli_scalm( &kappa, &a );

	// Randomize B and save B.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_randm( &b[i] );
		bli_copym( &b[i], &b_save[i] );
	}
#else
	bli_randm( &b );
	bli_copym( &b, &b_save );
#endif


	// Normalize by m.
	bli_setsc( 1.0/( double )m, 0.0, &kappa );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_scalm( &kappa, &b[i] );
	}
#else
	bli_scalm( &kappa, &b );
#endif

	// Apply the remaining parameters.
	bli_obj_set_conjtrans( transa, a );
	bli_obj_set_diag( diaga, a );

	// Repeat the experiment n_repeats times and record results. 
	for ( i = 0; i < n_repeats; ++i )
	{
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
		// Need only one call to initialize the CBLAS OpenCL kernel
		bli_copym( &b_save[0], &b[0] );
		libblis_test_trmm_impl( iface, side, &alpha, &a, &b[0] );
		//but need to re-initialize C for each of iteration of n_repeats
		for(j = 0; j < test_way; j++)
		{
			bli_copym( &b_save[j], &b[j] );
		}

#else
		bli_copym( &b_save, &b );
		libblis_test_trmm_impl( iface, side, &alpha, &a, &b );
		bli_copym( &b_save, &b );
#endif

		time = bli_clock();
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
#pragma omp parallel num_threads(test_way)
		{
			#pragma omp for
			for(j = 0; j < test_way; j++)
			{
				libblis_test_trmm_impl( iface, side, &alpha, &a, &b[j] );
			}
		}
#else
		libblis_test_trmm_impl( iface, side, &alpha, &a, &b );
#endif

		time_min = bli_clock_min_diff( time_min, time );
	}
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 1.0 * mn_side * m * n ) * test_way / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( b[0] ) ) perf->gflops *= 4.0;
#else
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 1.0 * mn_side * m * n ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( b ) ) perf->gflops *= 4.0;
#endif

	perf->time = time_min;

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Check output of each thread, and send max residue to main
	for(i = 0; i < test_way; i++)
	{
		// Perform checks.
		libblis_test_trmm_check( side, &alpha, &a, &b[i], &b_save[i], &resid_local[i] );

		// Zero out performance and residual if output matrix is empty.
		libblis_test_check_empty_problem( &b[i], perf, &resid_local[i] );

		if(i == 0)
		{
			*resid = resid_local[i];
		}
		else if (resid_local[i] > *resid)
		{
			*resid = resid_local[i];
		}
	}

#else
	// Perform checks.
	libblis_test_trmm_check( side, &alpha, &a, &b, &b_save, resid );

	// Zero out performance and residual if output matrix is empty.
	libblis_test_check_empty_problem( &b, perf, resid );
#endif


	// Free the test objects.
	bli_obj_free( &a );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_obj_free( &b[i] );
		bli_obj_free( &b_save[i] );
	}
#else
	bli_obj_free( &b );
	bli_obj_free( &b_save );
#endif
}



void libblis_test_trmm_impl( iface_t   iface,
                             side_t    side,
                             obj_t*    alpha,
                             obj_t*    a,
                             obj_t*    b )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
			;
#ifdef CBLAS
			enum CBLAS_SIDE cblas_side;
			enum CBLAS_ORDER cblas_order;
			enum CBLAS_UPLO cblas_uplo;
			enum CBLAS_TRANSPOSE cblas_trans;
			enum CBLAS_DIAG cblas_diag;

			int m, n;
			int lda, ldb;

			m     = bli_obj_length( *b );
			n     = bli_obj_width( *b );

			if(side == BLIS_RIGHT)
			{
				cblas_side = CblasRight;
			}
			else if (side == BLIS_LEFT)
			{
				cblas_side = CblasLeft;
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_SIDE );
				return;
			}

			if(bli_obj_is_upper( *a ))
			{
				cblas_uplo = CblasUpper;
			}
			else if (bli_obj_is_lower( *a ))
			{
				cblas_uplo = CblasLower;
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_UPLO );
				return;
			}

			if(bli_obj_has_notrans( *a ) && bli_obj_has_noconj( *a ))
			{
				cblas_trans = CblasNoTrans;
			}
			else if(bli_obj_has_trans( *a ) && bli_obj_has_noconj( *a ))
			{
				cblas_trans = CblasTrans;
			}
			else if(bli_obj_has_trans( *a ) && bli_obj_has_conj( *a ))
			{
				cblas_trans = CblasConjTrans;
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_TRANS );
				return;
			}

			if (bli_obj_has_nonunit_diag( *a ))
			{
				cblas_diag = CblasNonUnit;
			}
			else if(bli_obj_has_unit_diag( *a ))
			{
				cblas_diag = CblasUnit;
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_DIAG );
				return;
			}

			if(bli_obj_is_col_stored( *a ) )
			{
				cblas_order = CblasColMajor;
				lda = bli_obj_col_stride(*a);
				ldb = bli_obj_col_stride(*b);
			}
			else if(bli_obj_is_row_stored( *a ))
			{
				cblas_order = CblasRowMajor;
				lda = bli_obj_row_stride(*a);
				ldb = bli_obj_row_stride(*b);
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_DIM_STRIDE_COMBINATION );
				return;
			}

			if (bli_obj_is_float( *a ))
			{
				float *cblas_alpha;
				float *cblas_a, *cblas_b;

				cblas_alpha = (float *) bli_obj_buffer( *alpha );
				cblas_a     = (float *) bli_obj_buffer( *a );
				cblas_b     = (float *) bli_obj_buffer( *b );

				cblas_strmm(cblas_order, cblas_side,
				            cblas_uplo, cblas_trans,
				            cblas_diag, m, n,
				            *cblas_alpha, cblas_a, lda,
				            cblas_b, ldb);

			}
			else if (bli_obj_is_double( *a ))
			{
				double *cblas_alpha;
				double *cblas_a, *cblas_b;

				cblas_alpha = (double *) bli_obj_buffer( *alpha );
				cblas_a     = (double *) bli_obj_buffer( *a );
				cblas_b     = (double *) bli_obj_buffer( *b );

				cblas_dtrmm(cblas_order, cblas_side,
				            cblas_uplo, cblas_trans,
				            cblas_diag, m, n,
				            *cblas_alpha, cblas_a, lda,
				            cblas_b, ldb);
			}
			else if (bli_obj_is_scomplex( *a ))
			{
				void *cblas_alpha;
				void *cblas_a, *cblas_b;

				cblas_alpha = bli_obj_buffer( *alpha );
				cblas_a     = bli_obj_buffer( *a );
				cblas_b     = bli_obj_buffer( *b );

				cblas_ctrmm(cblas_order, cblas_side,
				            cblas_uplo, cblas_trans,
				            cblas_diag, m, n,
				            cblas_alpha, cblas_a, lda,
				            cblas_b, ldb);

			}
			else if (bli_obj_is_dcomplex( *a ))
			{
				void *cblas_alpha;
				void *cblas_a, *cblas_b;

				cblas_alpha = bli_obj_buffer( *alpha );
				cblas_a     = bli_obj_buffer( *a );
				cblas_b     = bli_obj_buffer( *b );

				cblas_ztrmm(cblas_order, cblas_side,
						    cblas_uplo, cblas_trans,
						    cblas_diag, m, n,
						    cblas_alpha, cblas_a, lda,
						    cblas_b, ldb);
			}

#else
			bli_trmm( side, alpha, a, b );
		//bli_trmm4m( side, alpha, a, b );
		//bli_trmm3m( side, alpha, a, b );
#endif
		break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_trmm_check( side_t  side,
                              obj_t*  alpha,
                              obj_t*  a,
                              obj_t*  b,
                              obj_t*  b_orig,
                              double* resid )
{
	num_t  dt      = bli_obj_datatype( *b );
	num_t  dt_real = bli_obj_datatype_proj_to_real( *b );

	dim_t  m       = bli_obj_length( *b );
	dim_t  n       = bli_obj_width( *b );

	obj_t  kappa, norm;
	obj_t  t, v, w, z;

	double junk;

	//
	// Pre-conditions:
	// - a is randomized and triangular.
	// - b_orig is randomized.
	// Note:
	// - alpha should have a non-zero imaginary component in the
	//   complex cases in order to more fully exercise the implementation.
	//
	// Under these conditions, we assume that the implementation for
	//
	//   B := alpha * transa(A) * B_orig    (side = left)
	//   B := alpha * B_orig * transa(A)    (side = right)
	//
	// is functioning correctly if
	//
	//   normf( v - z )
	//
	// is negligible, where
	//
	//   v = B * t
	//
	//   z = ( alpha * transa(A) * B ) * t     (side = left)
	//     = alpha * transa(A) * B * t
	//     = alpha * transa(A) * w
	//
	//   z = ( alpha * B * transa(A) ) * t     (side = right)
	//     = alpha * B * transa(A) * t
	//     = alpha * B * w

	bli_obj_scalar_init_detached( dt,      &kappa );
	bli_obj_scalar_init_detached( dt_real, &norm );

	if ( bli_is_left( side ) )
	{
		bli_obj_create( dt, n, 1, 0, 0, &t );
		bli_obj_create( dt, m, 1, 0, 0, &v );
		bli_obj_create( dt, m, 1, 0, 0, &w );
		bli_obj_create( dt, m, 1, 0, 0, &z );
	}
	else // else if ( bli_is_left( side ) )
	{
		bli_obj_create( dt, n, 1, 0, 0, &t );
		bli_obj_create( dt, m, 1, 0, 0, &v );
		bli_obj_create( dt, n, 1, 0, 0, &w );
		bli_obj_create( dt, m, 1, 0, 0, &z );
	}

	bli_randv( &t );
	bli_setsc( 1.0/( double )n, 0.0, &kappa );
	bli_scalv( &kappa, &t );

	bli_gemv( &BLIS_ONE, b, &t, &BLIS_ZERO, &v );

	if ( bli_is_left( side ) )
	{
		bli_gemv( &BLIS_ONE, b_orig, &t, &BLIS_ZERO, &w );
		bli_trmv( alpha, a, &w );
		bli_copyv( &w, &z );
	}
	else
	{
		bli_copyv( &t, &w );
		bli_trmv( &BLIS_ONE, a, &w );
		bli_gemv( alpha, b_orig, &w, &BLIS_ZERO, &z );
	}

	bli_subv( &z, &v );
	bli_normfv( &v, &norm );
	bli_getsc( &norm, resid, &junk );

	bli_obj_free( &t );
	bli_obj_free( &v );
	bli_obj_free( &w );
	bli_obj_free( &z );
}

