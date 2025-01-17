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

#define FUNCPTR_T gemm_fp

typedef void (*FUNCPTR_T)( obj_t*  a,
                           obj_t*  b,
                           obj_t*  c,
                           gemm_t* cntl,
                           gemm_thrinfo_t* thread );

static FUNCPTR_T vars[6][3] =
{
    // unblocked          optimized unblocked   blocked
    { NULL,               NULL,                 bli_gemm_blk_var1f },
    { NULL,               bli_gemm_ker_var2,    bli_gemm_blk_var2f },
    { NULL,               NULL,                 bli_gemm_blk_var3f },
    { NULL,               NULL,                 NULL               },
    { NULL,               NULL,                 NULL               },
    { NULL,               NULL,                 NULL               }
};

void bli_gemm_int( obj_t*  alpha,
                   obj_t*  a,
                   obj_t*  b,
                   obj_t*  beta,
                   obj_t*  c,
                   gemm_t* cntl,
                   gemm_thrinfo_t* thread )
{
	obj_t     a_local;
	obj_t     b_local;
	obj_t     c_local;
	varnum_t  n;
	impl_t    i;
	FUNCPTR_T f;
#if defined(BLIS_ENABLE_PROFILE)
    uint64_t counter_start;
    uint64_t counter_end;
    extern profile_data_t *bli_gemm_profile_data;
    dim_t m_var, k_var, n_var;
    dim_t index;
#endif

	// Extract the variant number and implementation type.
	n = cntl_var_num( cntl );
	i = cntl_impl_type( cntl );

	// Check parameters.
	if ( bli_error_checking_is_enabled() )
		bli_gemm_int_check( alpha, a, b, beta, c, cntl );  // creating the errors. print sizes of a,b,c

	// If C has a zero dimension, return early.
	if ( bli_obj_has_zero_dim( *c ) ) return;

	// If A or B has a zero dimension, scale C by beta and return early.
	if ( bli_obj_has_zero_dim( *a ) ||
	     bli_obj_has_zero_dim( *b ) )
	{
        if( thread_am_ochief( thread ) )
		    bli_scalm( beta, c );
        thread_obarrier( thread );
		return;
	}

	// If A or B is marked as being filled with zeros, scale C by beta and
	// return early.
	if ( bli_obj_is_zeros( *a ) ||
	     bli_obj_is_zeros( *b ) )
	{
        if( thread_am_ochief( thread ) )
		    bli_scalm( beta, c );
        thread_obarrier( thread );
		return;
	}

	// Alias A and B in case we need to update attached scalars.
	bli_obj_alias_to( *a, a_local );
	bli_obj_alias_to( *b, b_local );

	// Alias C in case we need to induce a transposition.
	bli_obj_alias_to( *c, c_local );

	// If we are about to call a leaf-level implementation, and matrix C
	// still needs a transposition, then we must induce one by swapping the
	// strides and dimensions. Note that this transposition would normally
	// be handled explicitly in the packing of C, but if C is not being
	// packed, this is our last chance to handle the transposition.
	if ( cntl_is_leaf( cntl ) && bli_obj_has_trans( *c ) )
	{
        //if( thread_am_ochief( thread ) ) {
            bli_obj_induce_trans( c_local );
            bli_obj_set_onlytrans( BLIS_NO_TRANSPOSE, c_local );
       // }
	}

	// If alpha is non-unit, typecast and apply it to the scalar attached
	// to B.
	if ( !bli_obj_equals( alpha, &BLIS_ONE ) )
	{
        bli_obj_scalar_apply_scalar( alpha, &b_local );
	}


	// If beta is non-unit, typecast and apply it to the scalar attached
	// to C.
	if ( !bli_obj_equals( beta, &BLIS_ONE ) )
	{
        bli_obj_scalar_apply_scalar( beta, &c_local );
	}

	// Extract the variant number and implementation type.
	n = cntl_var_num( cntl );
	i = cntl_impl_type( cntl );

	// Index into the variant array to extract the correct function pointer.
	f = vars[n][i];  // print out n and i

	// Invoke the variant.
#if defined(BLIS_ENABLE_PROFILE)
	m_var     = bli_obj_length( c_local );
	k_var = bli_obj_width_after_trans( a_local );
	n_var = bli_obj_width( c_local );

#if defined(BLIS_ENABLE_C66X_BUILD)
    lib_clock_enable();
    counter_start = lib_clock_read();
#else
    counter_start = (uint64_t) (bli_clock()*1.2e9);
#endif
#endif
	f( &a_local,
	   &b_local,
	   &c_local,
	   cntl,
	   thread );

#if defined(BLIS_ENABLE_PROFILE)
#if defined(BLIS_ENABLE_C66X_BUILD)
	counter_end = lib_clock_read();
#else
	counter_end = (uint64_t) (bli_clock()*1.2e9);
#endif
	bli_profile_get_index(n, i, index);
	bli_profile_data_update(bli_gemm_profile_data[index], (counter_end-counter_start), m_var*k_var*n_var);
#endif
}

