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
static char*     op_str                    = "symv";
static char*     o_types                   = "mvv";  // a x y
static char*     p_types                   = "ucc";  // uploa conja conjx
static thresh_t  thresh[BLIS_NUM_FP_TYPES] = { { 1e-04, 1e-05 },   // warn, pass for s
                                               { 1e-04, 1e-05 },   // warn, pass for c
                                               { 1e-13, 1e-14 },   // warn, pass for d
                                               { 1e-13, 1e-14 } }; // warn, pass for z

// Local prototypes.
void libblis_test_symv_deps( test_params_t* params,
                             test_op_t*     op );

void libblis_test_symv_experiment( test_params_t* params,
                                   test_op_t*     op,
                                   iface_t        iface,
                                   num_t          datatype,
                                   char*          pc_str,
                                   char*          sc_str,
                                   unsigned int   p_cur,
                                   perf_t*        perf,
                                   double*        resid );

void libblis_test_symv_impl( iface_t   iface,
                             obj_t*    alpha,
                             obj_t*    a,
                             obj_t*    x,
                             obj_t*    beta,
                             obj_t*    y );

void libblis_test_symv_check( obj_t*  alpha,
                              obj_t*  a,
                              obj_t*  x,
                              obj_t*  beta,
                              obj_t*  y,
                              obj_t*  y_orig,
                              double* resid );



void libblis_test_symv_deps( test_params_t* params, test_op_t* op )
{
	libblis_test_randv( params, &(op->ops->randv) );
	libblis_test_randm( params, &(op->ops->randm) );
	libblis_test_normfv( params, &(op->ops->normfv) );
	libblis_test_subv( params, &(op->ops->subv) );
	libblis_test_copyv( params, &(op->ops->copyv) );
	libblis_test_scalv( params, &(op->ops->scalv) );
	libblis_test_gemv( params, &(op->ops->gemv) );
}



void libblis_test_symv( test_params_t* params, test_op_t* op )
{

	// Return early if this test has already been done.
	if ( op->test_done == TRUE ) return;

	// Return early if operation is disabled.
	if ( op->op_switch == DISABLE_ALL ||
	     op->ops->l2_over == DISABLE_ALL ) return;

	// Call dependencies first.
	if ( TRUE ) libblis_test_symv_deps( params, op );

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
		                        libblis_test_symv_experiment );
	}
}



void libblis_test_symv_experiment( test_params_t* params,
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

	dim_t        m;

	uplo_t       uploa;
	conj_t       conja;
	conj_t       conjx;

	obj_t        kappa;
	obj_t        alpha, a, x, beta;
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	dim_t 		 test_way = bli_read_nway_from_env( "BLIS_LB_NT" );
	obj_t	     y[test_way];
	obj_t        y_save[test_way];
	double       resid_local[test_way];
	unsigned int j;
#else
	obj_t        y, y_save;
#endif


	// Map the dimension specifier to an actual dimension.
	m = libblis_test_get_dim_from_prob_size( op->dim_spec[0], p_cur );

	// Map parameter characters to BLIS constants.
	bli_param_map_char_to_blis_uplo( pc_str[0], &uploa );
	bli_param_map_char_to_blis_conj( pc_str[1], &conja );
	bli_param_map_char_to_blis_conj( pc_str[2], &conjx );

	// Create test scalars.
	bli_obj_scalar_init_detached( datatype, &alpha );
	bli_obj_scalar_init_detached( datatype, &beta );
	bli_obj_scalar_init_detached( datatype, &kappa );

	// Create test operands (vectors and/or matrices).
	libblis_test_mobj_create( params, datatype, BLIS_NO_TRANSPOSE,
	                          sc_str[0], m, m, &a );
	libblis_test_vobj_create( params, datatype,
	                          sc_str[1], m,    &x );

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		libblis_test_vobj_create( params, datatype,
		                          sc_str[2], m,    &y[i] );
		libblis_test_vobj_create( params, datatype,
		                          sc_str[2], m,    &y_save[i] );
	}
#else
	libblis_test_vobj_create( params, datatype,
		                      sc_str[2], m,    &y );
	libblis_test_vobj_create( params, datatype,
		                      sc_str[2], m,    &y_save );
#endif

	// Set alpha and beta.
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	if ( bli_obj_is_real( y[0] ) )
#else
	if ( bli_obj_is_real( y ) )
#endif
	{
		bli_setsc(  1.0,  0.0, &alpha );
		bli_setsc( -1.0,  0.0, &beta );
	}
	else
	{
		bli_setsc(  0.0,  1.0, &alpha );
		bli_setsc(  0.0, -1.0, &beta );
	}

	// Set the structure and uplo properties of A.
	bli_obj_set_struc( BLIS_SYMMETRIC, a );
	bli_obj_set_uplo( uploa, a );

	// Randomize A, make it densely symmetric, and zero the unstored triangle
	// to ensure the implementation reads only from the stored region.
	bli_randm( &a );
	bli_mksymm( &a );
	bli_mktrim( &a );

	// Randomize x and y, and save y.
	bli_randv( &x );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_randv( &y[i] );
		bli_copyv( &y[i], &y_save[i] );
	}
#else
	bli_randv( &y );
	bli_copyv( &y, &y_save );
#endif


	// Normalize vectors by m.
	bli_setsc( 1.0/( double )m, 0.0, &kappa );
	bli_scalv( &kappa, &x );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_scalv( &kappa, &y[i] );
		bli_scalv( &kappa, &y_save[i] );
	}
#else
	bli_scalv( &kappa, &y );
	bli_scalv( &kappa, &y_save );
#endif


	// Apply the remaining parameters.
	bli_obj_set_conj( conja, a );
	bli_obj_set_conj( conjx, x );

	// Repeat the experiment n_repeats times and record results.
	for ( i = 0; i < n_repeats; ++i )
	{
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
		// Need only one call to initialize the CBLAS OpenCL kernel
		bli_copyv( &y_save[0], &y[0] );
		libblis_test_symv_impl( iface, &alpha, &a, &x, &beta, &y[0] );
		//but need to re-initialize C for each of iteration of n_repeats
		for(j = 0; j < test_way; j++)
		{
			bli_copyv( &y_save[j], &y[j] );
		}
#else
		bli_copyv( &y_save, &y );
		libblis_test_symv_impl( iface, &alpha, &a, &x, &beta, &y );
		bli_copyv( &y_save, &y );
#endif

		time = bli_clock();

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
#pragma omp parallel num_threads(test_way)
		{
			#pragma omp for
			for(j = 0; j < test_way; j++)
			{
				libblis_test_symv_impl( iface, &alpha, &a, &x, &beta, &y[j] );
			}
		}
#else
		libblis_test_symv_impl( iface, &alpha, &a, &x, &beta, &y );
#endif

		time_min = bli_clock_min_diff( time_min, time );
	}
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 1.0 * m * m ) * test_way / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( y[0] ) ) perf->gflops *= 4.0;
#else
	// Estimate the performance of the best experiment repeat.
	perf->gflops = ( 1.0 * m * m ) / time_min / FLOPS_PER_UNIT_PERF;
	if ( bli_obj_is_complex( y ) ) perf->gflops *= 4.0;
#endif
	perf->time = time_min;

#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	// Check output of each thread, and send max residue to main
	for(i = 0; i < test_way; i++)
	{
		// Perform checks.
		libblis_test_symv_check( &alpha, &a, &x, &beta, &y[i], &y_save[i], &resid_local[i] );

		//check manipulates the A matrix.
		bli_obj_set_struc( BLIS_SYMMETRIC, a );
		bli_obj_set_uplo( uploa, a );
		bli_obj_set_conj( conja, a );

		// Zero out performance and residual if output vector is empty.
		libblis_test_check_empty_problem( &y[i], perf, &resid_local[i] );

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
	libblis_test_symv_check( &alpha, &a, &x, &beta, &y, &y_save, resid );

	// Zero out performance and residual if output vector is empty.
	libblis_test_check_empty_problem( &y, perf, resid );
#endif


	// Free the test objects.
	bli_obj_free( &a );
	bli_obj_free( &x );
#ifdef BLIS_ENABLE_MULTITHREAD_TEST
	for(i = 0; i < test_way; i++)
	{
		bli_obj_free( &y[i] );
		bli_obj_free( &y_save[i] );
	}
#else
	bli_obj_free( &y );
	bli_obj_free( &y_save );
#endif
}



void libblis_test_symv_impl( iface_t   iface,
                             obj_t*    alpha,
                             obj_t*    a,
                             obj_t*    x,
                             obj_t*    beta,
                             obj_t*    y )
{
	switch ( iface )
	{
		case BLIS_TEST_SEQ_FRONT_END:
			;
#ifdef CBLAS
			enum CBLAS_ORDER cblas_order;
			enum CBLAS_UPLO cblas_uplo;
			int n;
			int lda, incx, incy;

			n     = bli_obj_width( *a );

			if(bli_obj_is_col_stored( *a ) )
			{
				cblas_order = CblasColMajor;
				lda = bli_obj_col_stride(*a);
			}
			else if(bli_obj_is_row_stored( *a) )
			{
				cblas_order = CblasRowMajor;
				lda = bli_obj_row_stride(*a);
			}
			else
			{
				bli_check_error_code( BLIS_INVALID_DIM_STRIDE_COMBINATION );
				return;
			}

			incx = bli_obj_vector_inc(*x);
			incy = bli_obj_vector_inc(*y);

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

			if (bli_obj_is_float( *a ))
			{
				float *cblas_alpha, *cblas_beta;
				float *cblas_a, *cblas_x, *cblas_y;

				cblas_alpha = (float *) bli_obj_buffer( *alpha );
				cblas_beta  = (float *) bli_obj_buffer( *beta );
				cblas_a     = (float *) bli_obj_buffer( *a );
				cblas_x     = (float *) bli_obj_buffer( *x );
				cblas_y     = (float *) bli_obj_buffer( *y );

				cblas_ssymv(cblas_order, cblas_uplo, n, *cblas_alpha, cblas_a, lda, cblas_x, incx, *cblas_beta, cblas_y, incy);
			}
			else if (bli_obj_is_double( *a ))

			{
				double *cblas_alpha, *cblas_beta;
				double *cblas_a, *cblas_x, *cblas_y;

				cblas_alpha = (double *) bli_obj_buffer( *alpha );
				cblas_beta  = (double *) bli_obj_buffer( *beta );
				cblas_a     = (double *) bli_obj_buffer( *a );
				cblas_x     = (double *) bli_obj_buffer( *x );
				cblas_y     = (double *) bli_obj_buffer( *y );

				cblas_dsymv(cblas_order, cblas_uplo, n, *cblas_alpha, cblas_a, lda, cblas_x, incx, *cblas_beta, cblas_y, incy);
			}
			else
			{
				printf("CBLAS not supported\n");
			}



#else
			bli_symv( alpha, a, x, beta, y );
#endif
		break;

		default:
		libblis_test_printf_error( "Invalid interface type.\n" );
	}
}



void libblis_test_symv_check( obj_t*  alpha,
                              obj_t*  a,
                              obj_t*  x,
                              obj_t*  beta,
                              obj_t*  y,
                              obj_t*  y_orig,
                              double* resid )
{
	num_t  dt      = bli_obj_datatype( *y );
	num_t  dt_real = bli_obj_datatype_proj_to_real( *y );

	dim_t  m       = bli_obj_vector_dim( *y );

	obj_t  v;
	obj_t  norm;

	double junk;

	//
	// Pre-conditions:
	// - a is randomized and symmetric.
	// - x is randomized.
	// - y_orig is randomized.
	// Note:
	// - alpha and beta should have non-zero imaginary components in the
	//   complex cases in order to more fully exercise the implementation.
	//
	// Under these conditions, we assume that the implementation for
	//
	//   y := beta * y_orig + alpha * conja(A) * conjx(x)
	//
	// is functioning correctly if
	//
	//   normf( y - v )
	//
	// is negligible, where
	//
	//   v = beta * y_orig + alpha * conja(A_dense) * x
	//

	bli_obj_scalar_init_detached( dt_real, &norm );

	bli_obj_create( dt, m, 1, 0, 0, &v );

	bli_copyv( y_orig, &v );

	bli_mksymm( a );
	bli_obj_set_struc( BLIS_GENERAL, *a );
	bli_obj_set_uplo( BLIS_DENSE, *a );

	bli_gemv( alpha, a, x, beta, &v );

	bli_subv( &v, y );
	bli_normfv( y, &norm );
	bli_getsc( &norm, resid, &junk );

	bli_obj_free( &v );
}

