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

/*
#define FUNCPTR_T dotv_fp

typedef void (*FUNCPTR_T)(
                           conj_t conjx,
                           conj_t conjy,
                           dim_t  n,
                           void*  x, inc_t incx,
                           void*  y, inc_t incy,
                           void*  rho
                         );

// If some mixed datatype functions will not be compiled, we initialize
// the corresponding elements of the function array to NULL.
#ifdef BLIS_ENABLE_MIXED_PRECISION_SUPPORT
static FUNCPTR_T GENARRAY3_ALL(ftypes,dotv_ref);
#else
#ifdef BLIS_ENABLE_MIXED_DOMAIN_SUPPORT
static FUNCPTR_T GENARRAY3_EXT(ftypes,dotv_ref);
#else
static FUNCPTR_T GENARRAY3_MIN(ftypes,dotv_ref);
#endif
#endif


void bli_dotv_ref( obj_t*  x,
                        obj_t*  y,
                        obj_t*  rho )
{
	num_t     dt_x      = bli_obj_datatype( *x );
	num_t     dt_y      = bli_obj_datatype( *y );
	num_t     dt_rho    = bli_obj_datatype( *rho );

	conj_t    conjx     = bli_obj_conj_status( *x );
	conj_t    conjy     = bli_obj_conj_status( *y );
	dim_t     n         = bli_obj_vector_dim( *x );

	inc_t     inc_x     = bli_obj_vector_inc( *x );
	void*     buf_x     = bli_obj_buffer_at_off( *x );

	inc_t     inc_y     = bli_obj_vector_inc( *y );
	void*     buf_y     = bli_obj_buffer_at_off( *y );

	void*     buf_rho   = bli_obj_buffer_at_off( *rho );

	FUNCPTR_T f;

	// Index into the type combination array to extract the correct
	// function pointer.
	f = ftypes[dt_x][dt_y][dt_rho];

	// Invoke the function.
	f( conjx,
	   conjy,
	   n,
	   buf_x, inc_x, 
	   buf_y, inc_y,
	   buf_rho );
}
*/

#undef  GENTFUNC3
#define GENTFUNC3( ctype_x, ctype_y, ctype_r, chx, chy, chr, varname ) \
\
void PASTEMAC3(chx,chy,chr,varname) \
     ( \
       conj_t            conjx, \
       conj_t            conjy, \
       dim_t             n, \
       ctype_x* restrict x, inc_t incx, \
       ctype_y* restrict y, inc_t incy, \
       ctype_r* restrict rho  \
     ) \
{ \
	ctype_x* x_cast   = x; \
	ctype_y* y_cast   = y; \
	ctype_r* rho_cast = rho; \
	ctype_x* chi1; \
	ctype_y* psi1; \
	ctype_r  dotxy; \
	dim_t    i; \
	conj_t   conjx_use; \
	\
\
	if ( bli_zero_dim1( n ) ) \
	{ \
		PASTEMAC(chr,set0s)( *rho_cast ); \
		return; \
	} \
\
	PASTEMAC(chr,set0s)( dotxy ); \
\
	chi1 = x_cast; \
	psi1 = y_cast; \
\
	conjx_use = conjx; \
\
	/* If y must be conjugated, we do so indirectly by first toggling the
	   effective conjugation of x and then conjugating the resulting dot
	   product. */ \
	if ( bli_is_conj( conjy ) ) \
		bli_toggle_conj( conjx_use ); \
\
	if ( bli_is_conj( conjx_use ) ) \
	{ \
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC3(chx,chy,chr,dotjs)( *chi1, *psi1, dotxy ); \
\
			chi1 += incx; \
			psi1 += incy; \
		} \
	} \
	else \
	{ \
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC3(chx,chy,chr,dots)( *chi1, *psi1, dotxy ); \
\
			chi1 += incx; \
			psi1 += incy; \
		} \
	} \
\
	if ( bli_is_conj( conjy ) ) \
		PASTEMAC(chr,conjs)( dotxy ); \
\
	PASTEMAC2(chr,chr,copys)( dotxy, *rho_cast ); \
}

// Define the basic set of functions unconditionally, and then also some
// mixed datatype functions if requested.
INSERT_GENTFUNC3_BASIC0( dotv_ref )

#ifdef BLIS_ENABLE_MIXED_DOMAIN_SUPPORT
INSERT_GENTFUNC3_MIX_D0( dotv_ref )
#endif

#ifdef BLIS_ENABLE_MIXED_PRECISION_SUPPORT
INSERT_GENTFUNC3_MIX_P0( dotv_ref )
#endif

