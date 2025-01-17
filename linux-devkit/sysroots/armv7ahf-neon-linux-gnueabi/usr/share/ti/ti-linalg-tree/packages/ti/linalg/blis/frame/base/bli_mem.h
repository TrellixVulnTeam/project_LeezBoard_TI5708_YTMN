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

void bli_mem_acquire_m( siz_t     req_size,
                        packbuf_t buf_type,
                        mem_t*    mem );

void bli_mem_acquire_v( siz_t     req_size,
                        mem_t*    mem );

void bli_mem_release( mem_t* mem );

void bli_mem_init( void );
void bli_mem_finalize( void );

#ifdef BLIS_ENABLE_C66X_MEM_POOLS
void bli_mem_init_pool( char*   pool_mem,
                        siz_t   block_size,
                        dim_t   num_blocks,
                        void**  block_ptrs,
                        pool_t* pool,
                        membuf_t buf_type);
void bli_get_mem_sizes(size_t *smem_size_vfast,  size_t *smem_size_fast, 
                       size_t *smem_size_medium, size_t *smem_size_slow);
int bli_scratch_mem_alloc();

#define BLI_MEM_ALLOC_SUCCESS 0
#define BLI_MEM_ALLOC_ERROR   1

#else
void bli_mem_init_pool( char*   pool_mem,
                        siz_t   block_size,
                        dim_t   n_blocks,
                        void**  block_ptrs,
                        pool_t* pool_struct );
#endif
