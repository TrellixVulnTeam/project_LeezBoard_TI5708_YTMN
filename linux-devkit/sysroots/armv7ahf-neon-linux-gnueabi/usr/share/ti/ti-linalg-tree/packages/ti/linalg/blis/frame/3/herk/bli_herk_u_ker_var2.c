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

#define FUNCPTR_T herk_fp

typedef void (*FUNCPTR_T)(
                           doff_t  diagoffc,
                           pack_t  schema_a,
                           pack_t  schema_b,
                           dim_t   m,
                           dim_t   n,
                           dim_t   k,
                           void*   alpha,
                           void*   a, inc_t cs_a, inc_t pd_a, inc_t ps_a,
                           void*   b, inc_t rs_b, inc_t pd_b, inc_t ps_b,
                           void*   beta,
                           void*   c, inc_t rs_c, inc_t cs_c,
                           void*   gemm_ukr,
                           herk_thrinfo_t* thread
                         );

static FUNCPTR_T GENARRAY(ftypes,herk_u_ker_var2);


void bli_herk_u_ker_var2( obj_t*  a,
                          obj_t*  b,
                          obj_t*  c,
                          gemm_t* cntl,
                          herk_thrinfo_t* thread )
{
	num_t     dt_exec   = bli_obj_execution_datatype( *c );

	doff_t    diagoffc  = bli_obj_diag_offset( *c );

	pack_t    schema_a  = bli_obj_pack_schema( *a );
	pack_t    schema_b  = bli_obj_pack_schema( *b );

	dim_t     m         = bli_obj_length( *c );
	dim_t     n         = bli_obj_width( *c );
	dim_t     k         = bli_obj_width( *a );

	void*     buf_a     = bli_obj_buffer_at_off( *a );
	inc_t     cs_a      = bli_obj_col_stride( *a );
	inc_t     pd_a      = bli_obj_panel_dim( *a );
	inc_t     ps_a      = bli_obj_panel_stride( *a );

	void*     buf_b     = bli_obj_buffer_at_off( *b );
	inc_t     rs_b      = bli_obj_row_stride( *b );
	inc_t     pd_b      = bli_obj_panel_dim( *b );
	inc_t     ps_b      = bli_obj_panel_stride( *b );

	void*     buf_c     = bli_obj_buffer_at_off( *c );
	inc_t     rs_c      = bli_obj_row_stride( *c );
	inc_t     cs_c      = bli_obj_col_stride( *c );

	obj_t     scalar_a;
	obj_t     scalar_b;

	void*     buf_alpha;
	void*     buf_beta;

	FUNCPTR_T f;

	func_t*   gemm_ukrs;
	void*     gemm_ukr;


	// Detach and multiply the scalars attached to A and B.
	bli_obj_scalar_detach( a, &scalar_a );
	bli_obj_scalar_detach( b, &scalar_b );
	bli_mulsc( &scalar_a, &scalar_b );

	// Grab the addresses of the internal scalar buffers for the scalar
	// merged above and the scalar attached to C.
	buf_alpha = bli_obj_internal_scalar_buffer( scalar_b );
	buf_beta  = bli_obj_internal_scalar_buffer( *c );

	// Index into the type combination array to extract the correct
	// function pointer.
	f = ftypes[dt_exec];

	// Extract from the control tree node the func_t object containing
	// the gemm micro-kernel function addresses, and then query the
	// function address corresponding to the current datatype.
	gemm_ukrs = cntl_gemm_ukrs( cntl );
	gemm_ukr  = bli_func_obj_query( dt_exec, gemm_ukrs );

	// Invoke the function.
	f( diagoffc,
	   schema_a,
	   schema_b,
	   m,
	   n,
	   k,
	   buf_alpha,
	   buf_a, cs_a, pd_a, ps_a,
	   buf_b, rs_b, pd_b, ps_b,
	   buf_beta,
	   buf_c, rs_c, cs_c,
	   gemm_ukr,
	   thread );
}
#ifdef BLIS_ENABLE_C66X_MEM_POOLS

#if defined (BLIS_ENABLE_C66X_EDMA) && defined (BLIS_ENABLE_C66X_IDMA)

#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname, ukrtype ) \
\
void PASTEMAC(ch,varname)( \
                           doff_t  diagoffc, \
                           pack_t  schema_a, \
                           pack_t  schema_b, \
                           dim_t   m, \
                           dim_t   n, \
                           dim_t   k, \
                           void*   alpha, \
                           void*   a, inc_t cs_a, inc_t pd_a, inc_t ps_a, \
                           void*   b, inc_t rs_b, inc_t pd_b, inc_t ps_b, \
                           void*   beta, \
                           void*   c, inc_t rs_c, inc_t cs_c, \
                           void*   gemm_ukr, \
                           herk_thrinfo_t* thread \
                         ) \
{ \
	/* Cast the micro-kernel address to its function pointer type. */ \
	PASTECH(ch,ukrtype) gemm_ukr_cast = (PASTECH(ch,ukrtype)) gemm_ukr; \
\
	/* Temporary C buffer for edge cases. */ \
	ctype           ct[ PASTEMAC(ch,maxmr) * \
	                    PASTEMAC(ch,maxnr) ] \
	                    __attribute__((aligned(BLIS_STACK_BUF_ALIGN_SIZE))); \
	const inc_t     rs_ct      = 1; \
	const inc_t     cs_ct      = PASTEMAC(ch,maxmr); \
\
	/* Alias some constants to simpler names. */ \
	const dim_t     MR         = pd_a; \
	const dim_t     NR         = pd_b; \
	const dim_t     PACKMR     = cs_a; \
	const dim_t     PACKNR     = rs_b; \
\
	ctype* restrict zero       = PASTEMAC(ch,0); \
	ctype* restrict a_cast     = a; \
	ctype* restrict b_cast     = b; \
	ctype* restrict c_cast     = c; \
	ctype* restrict alpha_cast = alpha; \
	ctype* restrict beta_cast  = beta; \
	ctype* restrict b1; \
	ctype* restrict c1; \
\
	doff_t          diagoffc_ij; \
	dim_t           m_iter, m_left; \
	dim_t           n_iter, n_left; \
	dim_t           m_cur; \
	dim_t           n_cur; \
	dim_t  			n_next; \
	dim_t           i, j, jp; \
	inc_t           rstep_a; \
	inc_t           cstep_b; \
	/*inc_t           rstep_c; */\
	inc_t           cstep_c; \
	inc_t           rstep_c11, rs_c11, cs_c11; \
	inc_t           istep_a; \
	inc_t           istep_b; \
	auxinfo_t       aux; \
\
	herk_thrinfo_t* caucus = herk_thread_sub_herk( thread ); \
	dim_t jr_num_threads = thread_n_way( thread ); \
	dim_t jr_thread_id   = thread_work_id( thread ); \
	dim_t ir_num_threads = thread_n_way( caucus ); \
	dim_t ir_thread_id   = thread_work_id( caucus ); \
\
	mem_t b1_L1_mem; \
	/*memcpy does not like b1_L1 if it is restrict. The resid of gemm is non zero if this is changed to ctype* restrict*/ \
	ctype* b1_L1; \
\
	mem_t a1_L1_mem, a2_L1_mem; \
	ctype *a1_L1, *a2_L1, *temp; \
\
    mem_t c0_L2_mem, c1_L2_mem, c2_L2_mem; \
	ctype *cNew0, *cNew1, *cNew2, *cNewTemp; \
	/*EDMA Declarations */ \
\
	lib_emt_Handle emt_handle_b = NULL; \
	lib_emt_Handle emt_handle_c0 = NULL; \
	lib_emt_Handle emt_handle_c1 = NULL; \
\
	/*For DSP timing*/ \
	uint64_t counter_start_ker, counter_start_nr, counter_start_mr; \
	uint64_t counter_end_ker, counter_end_nr, counter_end_mr; \
	extern profile_data_t *bli_herk_profile_data; \
\
	/*
	   Assumptions/assertions:
	     rs_a == 1
	     cs_a == PACKMR
	     pd_a == MR
	     ps_a == stride to next micro-panel of A
	     rs_b == PACKNR
	     cs_b == 1
	     pd_b == NR
	     ps_b == stride to next micro-panel of B
	     rs_c == (no assumptions)
	     cs_c == (no assumptions)
	*/ \
\
	/* If any dimension is zero, return immediately. */ \
	if ( bli_zero_dim3( m, n, k ) ) return; \
\
	/* Safeguard: If the current panel of C is entirely below the diagonal,
	   it is not stored. So we do nothing. */ \
	if ( bli_is_strictly_below_diag_n( diagoffc, m, n ) ) return; \
\
	/* If there is a zero region to the left of where the diagonal of C
	   intersects the top edge of the panel, adjust the pointer to C and B
	   and treat this case as if the diagonal offset were zero. */ \
	if ( diagoffc > 0 ) \
	{ \
		jp       = diagoffc / NR; \
		j        = jp * NR; \
		n        = n - j; \
		diagoffc = diagoffc % NR; \
		c_cast   = c_cast + (j  )*cs_c; \
		b_cast   = b_cast + (jp )*ps_b; \
	} \
\
	/* If there is a zero region below where the diagonal of C intersects
	   the right edge of the panel, shrink it to prevent "no-op" iterations
	   from executing. */ \
	if ( -diagoffc + n < m ) \
	{ \
		m = -diagoffc + n; \
	} \
\
	/* Clear the temporary C buffer in case it has any infs or NaNs. */ \
	PASTEMAC(ch,set0s_mxn)( MR, NR, \
	                        ct, rs_ct, cs_ct ); \
\
	/* Compute number of primary and leftover components of the m and n
	   dimensions. */ \
	n_iter = n / NR; \
	n_left = n % NR; \
\
	m_iter = m / MR; \
	m_left = m % MR; \
\
	if ( n_left ) ++n_iter; \
	if ( m_left ) ++m_iter; \
\
	/* Determine some increments used to step through A, B, and C. */ \
	rstep_a = ps_a; \
\
	cstep_b = ps_b; \
\
	/*rstep_c = rs_c * MR; */\
	cstep_c = cs_c * NR; \
\
	/* When C (MC*NR) is moved to L2 the stride to get to the next panel of MRxNR*/ \
    rstep_c11 = MR; /*stride to get to next panel of MRxNR in a panel of MCxNR*/\
    rs_c11 = 1;\
	cs_c11 = (m%2 == 0) ? m : m+1 ; /*(m_iter-ir_thread_id)*MR;*/ /*stride to get to next column in a panel of MRxNR*/\
\
	istep_a = PACKMR * k; \
	istep_b = PACKNR * k; \
\
	/* Save the pack schemas of A and B to the auxinfo_t object. */ \
	bli_auxinfo_set_schema_a( schema_a, aux ); \
	bli_auxinfo_set_schema_b( schema_b, aux ); \
\
	/* Save the imaginary stride of A and B to the auxinfo_t object. */ \
	bli_auxinfo_set_is_a( istep_a, aux ); \
	bli_auxinfo_set_is_b( istep_b, aux ); \
\
	b1 = b_cast; \
	c1 = c_cast; \
\
	/*Acquiring a buffer for B in L1*/ \
	bli_mem_acquire_m( k*NR*sizeof(ctype), BLIS_BUFFER_FOR_B_PANEL_L1, &b1_L1_mem); \
	b1_L1 = bli_mem_buffer( &b1_L1_mem ); \
	b1_L1 = (ctype *) ((char *) b1_L1_mem.buf + PASTEMAC(ch,bank)); \
\
	/*Acquiring a buffer for A in L1*/ \
	bli_mem_acquire_m( k*MR*sizeof(ctype), BLIS_BUFFER_FOR_A_BLOCK_L1, &a1_L1_mem); \
	a1_L1 = bli_mem_buffer( &a1_L1_mem ); \
	a1_L1 = a1_L1; \
\
	bli_mem_acquire_m( k*MR*sizeof(ctype), BLIS_BUFFER_FOR_A_BLOCK_L1, &a2_L1_mem); \
	a2_L1 = bli_mem_buffer( &a2_L1_mem ); \
\
	/*Acquiring buffers for C (MC_x_NR) in L2 */\
	bli_mem_acquire_m( cs_c11*NR*sizeof(ctype), BLIS_BUFFER_FOR_C_PANEL_L2, &c0_L2_mem); \
	cNew0 = bli_mem_buffer( &c0_L2_mem ); \
\
	bli_mem_acquire_m( cs_c11*NR*sizeof(ctype), BLIS_BUFFER_FOR_C_PANEL_L2, &c1_L2_mem); \
	cNew1 = bli_mem_buffer( &c1_L2_mem ); \
\
	bli_mem_acquire_m( cs_c11*NR*sizeof(ctype), BLIS_BUFFER_FOR_C_PANEL_L2, &c2_L2_mem); \
	cNew2 = bli_mem_buffer( &c2_L2_mem ); \
\
	/*Acquiring an EDMA  handle from the pool*/ \
	bli_dma_channel_acquire(&(emt_handle_b), lib_get_coreID()); \
	if(emt_handle_b == NULL) \
	{ \
		printf("ker_var2 Failed to alloc edma handle CoreID %d \n", lib_get_coreID()); \
	} \
	bli_dma_channel_acquire(&(emt_handle_c0), lib_get_coreID()); \
	if(emt_handle_c0 == NULL) \
	{ \
		printf("ker_var2 Failed to alloc edma handle for C0 CoreID %d \n", lib_get_coreID()); \
	} \
	/*Acquiring an EDMA  handle from the pool*/ \
	bli_dma_channel_acquire(&(emt_handle_c1), lib_get_coreID()); \
	if(emt_handle_c1 == NULL) \
	{ \
		printf("ker_var2 Failed to alloc edma handle for C1 CoreID %d \n", lib_get_coreID()); \
	} \
\
	/* initiate first c transfer */ \
	/* For C need to transfer mxn_cur. For smaller matrix sizes it can happen that
	 * (m_iter-ir_thread_id)*MR is not equal to m which would lead to incorrect
	 * values of C written back.*/ \
	n_cur = ( bli_is_not_edge_f( jr_thread_id, n_iter, n_left ) ? NR : n_left ); \
\
	if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
	{ \
		counter_start_nr = lib_clock_read();  \
	} \
\
	if (cs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
	{ \
		lib_emt_copy2D2D(emt_handle_c0, c_cast+jr_thread_id*cstep_c, \
							cNew1, m*sizeof(ctype), \
							n_cur, cs_c*sizeof(ctype), cs_c11*sizeof(ctype)); \
	}\
	else \
	{ \
		dim_t ii; \
		ctype *ptr_source; \
		ctype *ptr_dest; \
		ptr_source =  c_cast+jr_thread_id*cstep_c; \
		ptr_dest = cNew1; \
		for(ii = 0; ii < n_cur; ii++) \
		{ \
			memcpy(ptr_dest, ptr_source, m*sizeof(ctype)); \
			ptr_source += cs_c; \
			ptr_dest   += cs_c11; \
		} \
	} \
	/* Loop over the n dimension (NR columns at a time). */ \
	for ( j = jr_thread_id; j < n_iter; j += jr_num_threads ) \
	{ \
		ctype* restrict a1; \
		ctype* restrict c11; \
		ctype* restrict b2; \
\
		b1 = b_cast + j * cstep_b; \
		c1 = c_cast + j * cstep_c; \
\
		n_cur = ( bli_is_not_edge_f( j, n_iter, n_left ) ? NR : n_left ); \
		n_next = ( bli_is_not_edge_f( j+jr_num_threads, n_iter, n_left ) ? NR : n_left ); \
\
		m_cur = ( bli_is_not_edge_f( ir_thread_id, m_iter, m_left ) ? MR : m_left ); \
		/* Initialize our next panel of B to be the current panel of B. */ \
		b2 = b1; \
\
        lib_emt_copy1D1D(emt_handle_b, b1, b1_L1, k*NR*sizeof(ctype)); \
        lib_imt_copy(a_cast + ir_thread_id * rstep_a, a2_L1, k*MR*sizeof(ctype)); \
        /* wait for previous c transfer to complete and initiate next transfer */ \
        lib_emt_wait(emt_handle_c0); \
        if(j < (n_iter-jr_num_threads)) /* no transfer for last iteration */ \
        { \
        	if (cs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
        	{ \
        		lib_emt_copy2D2D(emt_handle_c0, c1+jr_num_threads*cstep_c, \
        							cNew0, m*sizeof(ctype), /*(m_iter-ir_thread_id)*sizeof(ctype)*MR,*/ \
                                	n_next, cs_c*sizeof(ctype), \
                                	cs_c11*sizeof(ctype)); \
        	}\
        	else \
        	{ \
        		dim_t ii; \
        		ctype *ptr_source; \
        		ctype *ptr_dest; \
        		ptr_source =  c1+jr_num_threads*cstep_c; \
        		ptr_dest = cNew0; \
        		for(ii = 0; ii < n_next; ii++) \
        		{ \
        			memcpy(ptr_dest, ptr_source, m*sizeof(ctype)); \
        			ptr_source += cs_c; \
        			ptr_dest   += cs_c11; \
        		} \
        	} \
        }\
		/* Interior loop over the m dimension (MR rows at a time). */ \
\
		if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
		{ \
			counter_start_mr = lib_clock_read();  \
		} \
\
		for ( i = ir_thread_id; i < m_iter; i += ir_num_threads ) \
		{ \
			ctype* restrict a2; \
\
			a1  = a_cast + i * rstep_a; \
			c11 = cNew1  + i * rstep_c11; \
			/*c11 = c1  + i * rstep_c;*/ \
\
			/* Compute the diagonal offset for the submatrix at (i,j). */ \
			diagoffc_ij = diagoffc - (doff_t)j*NR + (doff_t)i*MR; \
\
			m_cur = ( bli_is_not_edge_f( i, m_iter, m_left ) ? MR : m_left ); \
\
			/* Compute the addresses of the next panels of A and B. */ \
			a2 = herk_get_next_a_micropanel( caucus, a1, rstep_a ); \
			temp = a1_L1; \
			a1_L1 = a2_L1; \
			a2_L1 = temp; \
			/*a1 = a2; Make the next panel the current panel for the next iteration*/ \
			lib_imt_wait(); \
			if ( bli_is_last_iter( i, m_iter, ir_thread_id, ir_num_threads ) ) \
			{ \
				a2 = a_cast; \
				b2 = herk_get_next_b_micropanel( thread, b1, cstep_b ); \
				if ( bli_is_last_iter( j, n_iter, jr_thread_id, jr_num_threads ) ) \
					b2 = b_cast; \
			} \
			else \
			{\
				/*Start next panel*/ \
				lib_imt_copy(a2, a2_L1, k*MR*sizeof(ctype)); \
			}\
			if(i == ir_thread_id) \
			{ \
				lib_emt_wait(emt_handle_b);\
			} \
\
			/* Save addresses of next panels of A and B to the auxinfo_t
			   object. */ \
			bli_auxinfo_set_next_a( a2, aux ); \
			bli_auxinfo_set_next_b( b2, aux ); \
\
			/* If the diagonal intersects the current MR x NR submatrix, we
			   compute it the temporary buffer and then add in the elements
			   on or below the diagonal.
			   Otherwise, if the submatrix is strictly above the diagonal,
			   we compute and store as we normally would.
			   And if we're strictly below the diagonal, we do nothing and
			   continue. */ \
			if ( bli_intersects_diag_n( diagoffc_ij, m_cur, n_cur ) ) \
			{ \
\
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_start_ker = lib_clock_read();  \
				} \
\
				/* Invoke the gemm micro-kernel. */ \
				gemm_ukr_cast( k, \
				               alpha_cast, \
				               a1_L1, /*a1_L1,*/ \
				               b1_L1, /*b1_L1,*/ \
				               zero, \
				               ct, rs_ct, cs_ct,\
				               &aux ); \
\
				/* Scale C and add the result to only the stored part. */ \
				PASTEMAC(ch,xpbys_mxn_u)( diagoffc_ij, \
				                          m_cur, n_cur, \
				                          ct,  rs_ct, cs_ct, \
				                          beta_cast, \
				                          c11, rs_c11, cs_c11 /*rs_c,  cs_c  */); \
\
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_end_ker = lib_clock_read();  \
				    bli_profile_data_update(bli_herk_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_KER_LOOP_IND], \
				    						(counter_end_ker-counter_start_ker), 2*k*m_cur*n_cur); \
				} \
\
			} \
			else if ( bli_is_strictly_above_diag_n( diagoffc_ij, m_cur, n_cur ) ) \
			{ \
\
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_start_ker = lib_clock_read();  \
				} \
\
				/* Handle interior and edge cases separately. */ \
				if ( m_cur == MR && n_cur == NR ) \
				{ \
					/* Invoke the gemm micro-kernel. */ \
					gemm_ukr_cast( k, \
					               alpha_cast, \
					               a1_L1, /*a1_L1,*/ \
					               b1_L1, /*b1_L1,*/ \
					               beta_cast, \
					               c11, rs_c11, cs_c11 /* rs_c,  cs_c */, \
					               &aux ); \
				} \
				else \
				{ \
					/* Invoke the gemm micro-kernel. */ \
					gemm_ukr_cast( k, \
					               alpha_cast, \
					               a1_L1, /*a1_L1,*/ \
					               b1_L1, /*b1_L1,*/ \
					               zero, \
					               ct, rs_ct, cs_ct, \
					               &aux ); \
\
					/* Scale the edge of C and add the result. */ \
					PASTEMAC(ch,xpbys_mxn)( m_cur, n_cur, \
					                        ct,  rs_ct, cs_ct, \
					                        beta_cast, \
					                        c11,  rs_c11, cs_c11 /*rs_c,  cs_c */); \
				} \
				if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
				{ \
					counter_end_ker = lib_clock_read();  \
					bli_profile_data_update(bli_herk_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_KER_LOOP_IND], \
											(counter_end_ker-counter_start_ker), 2*k*m_cur*n_cur); \
				} \
			} \
		} \
		if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
		{ \
			counter_end_mr = lib_clock_read();  \
			bli_profile_data_update(bli_herk_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_IR_LOOP_IND], \
									(counter_end_mr-counter_start_mr), 2*m*k*n_cur); \
		} \
		/* circularly shift buffers */ \
		cNewTemp = cNew0; \
		cNew0 = cNew2; \
		cNew2 = cNew1; \
		cNew1 = cNewTemp; \
		if(j != jr_thread_id) /* wait for save c to complete; skip first iteration */ \
		{ \
		    lib_emt_wait(emt_handle_c1); \
        } \
		/* save updated c */ \
		if (cs_c*sizeof(ctype) < BLIS_C66X_MAXDMASTRIDE) \
		{ \
			lib_emt_copy2D2D(emt_handle_c1, cNew2, c1, m*sizeof(ctype), \
								n_cur, cs_c11*sizeof(ctype), cs_c*sizeof(ctype)); \
		} \
        else \
        { \
        	dim_t ii; \
        	ctype *ptr_source; \
			ctype *ptr_dest; \
			ptr_source = cNew2; \
			ptr_dest = c1; \
            for(ii = 0; ii < n_cur; ii++) \
            { \
            	memcpy(ptr_dest, ptr_source, m*sizeof(ctype)); \
            	ptr_source += cs_c11; \
                ptr_dest   += cs_c; \
            } \
        } \
	} \
\
	if (BLIS_ENABLE_PROFILE_KERVAR2 == 1) \
	{ \
		counter_end_nr = lib_clock_read();  \
		bli_profile_data_update(bli_herk_profile_data[bli_get_thread_num()+BLIS_MAX_NUM_THREADS*BLIS_PROFILE_JR_LOOP_IND],\
								(counter_end_nr-counter_start_nr), 2*m*k*n); \
	} \
\
    bli_mem_release( &c2_L2_mem ); \
	bli_mem_release( &c1_L2_mem ); \
	bli_mem_release( &c0_L2_mem ); \
	bli_mem_release( &a2_L1_mem ); \
	bli_mem_release( &a1_L1_mem ); \
	bli_mem_release( &b1_L1_mem ); \
	if ( emt_handle_b != NULL ) \
    { \
		bli_dma_channel_release(emt_handle_b, lib_get_coreID()); \
		emt_handle_b = NULL; \
    } \
    if ( emt_handle_c0 != NULL ) \
    { \
        bli_dma_channel_release(emt_handle_c0, lib_get_coreID()); \
        emt_handle_c0 = NULL; \
    } \
    if ( emt_handle_c1 != NULL ) \
    { \
        lib_emt_wait(emt_handle_c1); /* wait for save c to complete */ \
        bli_dma_channel_release(emt_handle_c1, lib_get_coreID()); \
        emt_handle_c1 = NULL; \
    } \
}

INSERT_GENTFUNC_BASIC( herk_u_ker_var2, gemm_ukr_t )


#else

#endif

#else

#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname, ukrtype ) \
\
void PASTEMAC(ch,varname)( \
                           doff_t  diagoffc, \
                           pack_t  schema_a, \
                           pack_t  schema_b, \
                           dim_t   m, \
                           dim_t   n, \
                           dim_t   k, \
                           void*   alpha, \
                           void*   a, inc_t cs_a, inc_t pd_a, inc_t ps_a, \
                           void*   b, inc_t rs_b, inc_t pd_b, inc_t ps_b, \
                           void*   beta, \
                           void*   c, inc_t rs_c, inc_t cs_c, \
                           void*   gemm_ukr, \
                           herk_thrinfo_t* thread \
                         ) \
{ \
	/* Cast the micro-kernel address to its function pointer type. */ \
	PASTECH(ch,ukrtype) gemm_ukr_cast = gemm_ukr; \
\
	/* Temporary C buffer for edge cases. */ \
	ctype           ct[ PASTEMAC(ch,maxmr) * \
	                    PASTEMAC(ch,maxnr) ] \
	                    __attribute__((aligned(BLIS_STACK_BUF_ALIGN_SIZE))); \
	const inc_t     rs_ct      = 1; \
	const inc_t     cs_ct      = PASTEMAC(ch,maxmr); \
\
	/* Alias some constants to simpler names. */ \
	const dim_t     MR         = pd_a; \
	const dim_t     NR         = pd_b; \
	const dim_t     PACKMR     = cs_a; \
	const dim_t     PACKNR     = rs_b; \
\
	ctype* restrict zero       = PASTEMAC(ch,0); \
	ctype* restrict a_cast     = a; \
	ctype* restrict b_cast     = b; \
	ctype* restrict c_cast     = c; \
	ctype* restrict alpha_cast = alpha; \
	ctype* restrict beta_cast  = beta; \
	ctype* restrict b1; \
	ctype* restrict c1; \
\
	doff_t          diagoffc_ij; \
	dim_t           m_iter, m_left; \
	dim_t           n_iter, n_left; \
	dim_t           m_cur; \
	dim_t           n_cur; \
	dim_t           i, j, jp; \
	inc_t           rstep_a; \
	inc_t           cstep_b; \
	inc_t           rstep_c, cstep_c; \
	inc_t           istep_a; \
	inc_t           istep_b; \
	auxinfo_t       aux; \
\
	herk_thrinfo_t* caucus = herk_thread_sub_herk( thread ); \
	dim_t jr_num_threads = thread_n_way( thread ); \
	dim_t jr_thread_id   = thread_work_id( thread ); \
	dim_t ir_num_threads = thread_n_way( caucus ); \
	dim_t ir_thread_id   = thread_work_id( caucus ); \
\
	/*
	   Assumptions/assertions:
	     rs_a == 1
	     cs_a == PACKMR
	     pd_a == MR
	     ps_a == stride to next micro-panel of A
	     rs_b == PACKNR
	     cs_b == 1
	     pd_b == NR
	     ps_b == stride to next micro-panel of B
	     rs_c == (no assumptions)
	     cs_c == (no assumptions)
	*/ \
\
	/* If any dimension is zero, return immediately. */ \
	if ( bli_zero_dim3( m, n, k ) ) return; \
\
	/* Safeguard: If the current panel of C is entirely below the diagonal,
	   it is not stored. So we do nothing. */ \
	if ( bli_is_strictly_below_diag_n( diagoffc, m, n ) ) return; \
\
	/* If there is a zero region to the left of where the diagonal of C
	   intersects the top edge of the panel, adjust the pointer to C and B
	   and treat this case as if the diagonal offset were zero. */ \
	if ( diagoffc > 0 ) \
	{ \
		jp       = diagoffc / NR; \
		j        = jp * NR; \
		n        = n - j; \
		diagoffc = diagoffc % NR; \
		c_cast   = c_cast + (j  )*cs_c; \
		b_cast   = b_cast + (jp )*ps_b; \
	} \
\
	/* If there is a zero region below where the diagonal of C intersects
	   the right edge of the panel, shrink it to prevent "no-op" iterations
	   from executing. */ \
	if ( -diagoffc + n < m ) \
	{ \
		m = -diagoffc + n; \
	} \
\
	/* Clear the temporary C buffer in case it has any infs or NaNs. */ \
	PASTEMAC(ch,set0s_mxn)( MR, NR, \
	                        ct, rs_ct, cs_ct ); \
\
	/* Compute number of primary and leftover components of the m and n
	   dimensions. */ \
	n_iter = n / NR; \
	n_left = n % NR; \
\
	m_iter = m / MR; \
	m_left = m % MR; \
\
	if ( n_left ) ++n_iter; \
	if ( m_left ) ++m_iter; \
\
	/* Determine some increments used to step through A, B, and C. */ \
	rstep_a = ps_a; \
\
	cstep_b = ps_b; \
\
	rstep_c = rs_c * MR; \
	cstep_c = cs_c * NR; \
\
	istep_a = PACKMR * k; \
	istep_b = PACKNR * k; \
\
	/* Save the pack schemas of A and B to the auxinfo_t object. */ \
	bli_auxinfo_set_schema_a( schema_a, aux ); \
	bli_auxinfo_set_schema_b( schema_b, aux ); \
\
	/* Save the imaginary stride of A and B to the auxinfo_t object. */ \
	bli_auxinfo_set_is_a( istep_a, aux ); \
	bli_auxinfo_set_is_b( istep_b, aux ); \
\
	b1 = b_cast; \
	c1 = c_cast; \
\
	/* Loop over the n dimension (NR columns at a time). */ \
	for ( j = jr_thread_id; j < n_iter; j += jr_num_threads ) \
	{ \
		ctype* restrict a1; \
		ctype* restrict c11; \
		ctype* restrict b2; \
\
		b1 = b_cast + j * cstep_b; \
		c1 = c_cast + j * cstep_c; \
\
		n_cur = ( bli_is_not_edge_f( j, n_iter, n_left ) ? NR : n_left ); \
\
		/* Initialize our next panel of B to be the current panel of B. */ \
		b2 = b1; \
\
		/* Interior loop over the m dimension (MR rows at a time). */ \
		for ( i = ir_thread_id; i < m_iter; i += ir_num_threads ) \
		{ \
			ctype* restrict a2; \
\
			a1  = a_cast + i * rstep_a; \
			c11 = c1     + i * rstep_c; \
\
			/* Compute the diagonal offset for the submatrix at (i,j). */ \
			diagoffc_ij = diagoffc - (doff_t)j*NR + (doff_t)i*MR; \
\
			m_cur = ( bli_is_not_edge_f( i, m_iter, m_left ) ? MR : m_left ); \
\
			/* Compute the addresses of the next panels of A and B. */ \
			a2 = herk_get_next_a_micropanel( caucus, a1, rstep_a ); \
			if ( bli_is_last_iter( i, m_iter, ir_thread_id, ir_num_threads ) ) \
			{ \
				a2 = a_cast; \
				b2 = herk_get_next_b_micropanel( thread, b1, cstep_b ); \
				if ( bli_is_last_iter( j, n_iter, jr_thread_id, jr_num_threads ) ) \
					b2 = b_cast; \
			} \
\
			/* Save addresses of next panels of A and B to the auxinfo_t
			   object. */ \
			bli_auxinfo_set_next_a( a2, aux ); \
			bli_auxinfo_set_next_b( b2, aux ); \
\
			/* If the diagonal intersects the current MR x NR submatrix, we
			   compute it the temporary buffer and then add in the elements
			   on or below the diagonal.
			   Otherwise, if the submatrix is strictly above the diagonal,
			   we compute and store as we normally would.
			   And if we're strictly below the diagonal, we do nothing and
			   continue. */ \
			if ( bli_intersects_diag_n( diagoffc_ij, m_cur, n_cur ) ) \
			{ \
				/* Invoke the gemm micro-kernel. */ \
				gemm_ukr_cast( k, \
				               alpha_cast, \
				               a1, \
				               b1, \
				               zero, \
				               ct, rs_ct, cs_ct, \
				               &aux ); \
\
				/* Scale C and add the result to only the stored part. */ \
				PASTEMAC(ch,xpbys_mxn_u)( diagoffc_ij, \
				                          m_cur, n_cur, \
				                          ct,  rs_ct, cs_ct, \
				                          beta_cast, \
				                          c11, rs_c,  cs_c ); \
			} \
			else if ( bli_is_strictly_above_diag_n( diagoffc_ij, m_cur, n_cur ) ) \
			{ \
				/* Handle interior and edge cases separately. */ \
				if ( m_cur == MR && n_cur == NR ) \
				{ \
					/* Invoke the gemm micro-kernel. */ \
					gemm_ukr_cast( k, \
					               alpha_cast, \
					               a1, \
					               b1, \
					               beta_cast, \
					               c11, rs_c, cs_c, \
					               &aux ); \
				} \
				else \
				{ \
					/* Invoke the gemm micro-kernel. */ \
					gemm_ukr_cast( k, \
					               alpha_cast, \
					               a1, \
					               b1, \
					               zero, \
					               ct, rs_ct, cs_ct, \
					               &aux ); \
\
					/* Scale the edge of C and add the result. */ \
					PASTEMAC(ch,xpbys_mxn)( m_cur, n_cur, \
					                        ct,  rs_ct, cs_ct, \
					                        beta_cast, \
					                        c11, rs_c,  cs_c ); \
				} \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC( herk_u_ker_var2, gemm_ukr_t )

#endif
