/* ======================================================================= */
/* DSP_fir_cplx_d.c -- Complex FIR Filter                                  */
/*                     Driver code implementation                          */
/*                                                                         */
/* Rev 0.0.1                                                               */
/*                                                                         */
/*                                                                         */
/* Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/  */ 
/*                                                                         */
/*                                                                         */
/*  Redistribution and use in source and binary forms, with or without     */
/*  modification, are permitted provided that the following conditions     */
/*  are met:                                                               */
/*                                                                         */
/*    Redistributions of source code must retain the above copyright       */
/*    notice, this list of conditions and the following disclaimer.        */
/*                                                                         */
/*    Redistributions in binary form must reproduce the above copyright    */
/*    notice, this list of conditions and the following disclaimer in the  */
/*    documentation and/or other materials provided with the               */
/*    distribution.                                                        */
/*                                                                         */
/*    Neither the name of Texas Instruments Incorporated nor the names of  */
/*    its contributors may be used to endorse or promote products derived  */
/*    from this software without specific prior written permission.        */
/*                                                                         */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
/*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT   */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
/*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
/*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   */
/*                                                                         */
/* ======================================================================= */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <c6x.h>

/* ======================================================================= */
/* Interface header files for the natural C and optimized C code           */
/* ======================================================================= */
#include "DSP_fir_cplx_cn.h"
#include "DSP_fir_cplx.h"

/* Defines */
#if defined(__TI_EABI__)
#define kernel_size _kernel_size
#endif

extern char kernel_size;

#define FORMULA_SIZE          4
#define FORMULA_DEVIDE        8
#define CYCLE_FORMULA_NX_PT1  100
#define CYCLE_FORMULA_NX_PT2  92
#define CYCLE_FORMULA_NR_PT1  24
#define CYCLE_FORMULA_NR_PT2  20
/* inverse of [100*24 100 24 1] */
/*            [100*20 100 20 1] */
/*            [ 92*24  92 24 1] */
/*            [ 92*20  92 20 1] */
float form_inv[FORMULA_SIZE][FORMULA_SIZE] = 
{{ 0.0313,   -0.0313,   -0.0313,    0.0313},
 {-0.6250,    0.7500,    0.6250,   -0.7500},
 {-2.8750,    2.8750,    3.1250,   -3.1250},
 {57.5000,  -69.0000,  -62.5000,   75.0000}
};
float form_temp  [FORMULA_SIZE];
int   form_cycle [FORMULA_SIZE];
int   form_result[FORMULA_SIZE];

/* ======================================================================= */
/* Inform the compiler the arrays are double word alligned                 */
/* ======================================================================= */
#pragma DATA_ALIGN(x, 8);
#pragma DATA_ALIGN(h, 8);
#pragma DATA_ALIGN(r_c, 8);
#pragma DATA_ALIGN(r_i, 8);

/* ======================================================================= */
/* Parameters of fixed dataset                                             */
/* ======================================================================= */
#define NX  (256)
#define NH  (24)
#define NR  (100)
#define PAD (16)

/* ======================================================================= */
/* Initilized arrays with fixed test data                                  */
/* ======================================================================= */
const short x[NX + 2*PAD] =
{
    0x76E2, 0x8B0E, 0x4A09, 0xBA35, 0xEB22, 0xE6EB, 0x8CCF, 0xDF71,     // Beginning
    0xAACF, 0x3CE2, 0xADDA, 0x3E77, 0x8CA7, 0x6C43, 0x0F68, 0xCCF6,     // PAD

    0x5A0A, 0xCD7B, 0x8397, 0xA5BC, 0xB196, 0x963C, 0x61C8, 0xE43A,
    0x1C8B, 0x55F2, 0x32B9, 0xB3DD, 0xE468, 0x64CE, 0x3F29, 0x2815,
    0x99CB, 0x813E, 0xCAB7, 0xE031, 0xE954, 0x8AF2, 0x9943, 0x2780,
    0x8DC1, 0x2C18, 0xA0EA, 0x6371, 0x9033, 0x2F1F, 0xF36D, 0xB972,
    0x5B46, 0x9837, 0x6009, 0x7354, 0x7CBB, 0xCB4E, 0x4D5F, 0x90E4,
    0x27B1, 0xCBF3, 0xD4CD, 0xCA53, 0xD3A7, 0xDD56, 0xEF72, 0x866E,
    0x637B, 0x6CE5, 0x084D, 0x3A65, 0xCA8D, 0x45D0, 0x8A5D, 0xB246,
    0x031B, 0xBC84, 0xB401, 0x9DC2, 0xB285, 0xE273, 0x6C99, 0xE626,
    0x3D8A, 0x5E49, 0x0742, 0xDAE3, 0x7488, 0x5DF7, 0x36BD, 0xA466,
    0xBE5F, 0x8DAB, 0x6647, 0xCF7F, 0x8A8D, 0xBFF5, 0x3E81, 0x867D,
    0x1CD2, 0x1103, 0xF7C9, 0x8B0F, 0xAE8D, 0x03A4, 0x22BE, 0x7CC3,
    0x739C, 0x9D08, 0xC9DF, 0xB2AA, 0x155F, 0x2D3D, 0x80AC, 0xD731,
    0x9654, 0x0273, 0x9582, 0x5C69, 0xBC3B, 0xB957, 0x3641, 0x293F,
    0x3533, 0x94DA, 0x1E69, 0xE5A3, 0xD45A, 0xC82B, 0x8758, 0xFAC3,
    0x7ED0, 0x3E98, 0x4E2C, 0x3C10, 0xDED3, 0x0110, 0x3666, 0xD178,
    0x9683, 0xD6E3, 0x3A24, 0x22E9, 0xFC9F, 0xCD7F, 0x3DE5, 0x2133,
    0x6DE5, 0xD5F3, 0x86A9, 0x8805, 0x8695, 0x54AF, 0xE1AD, 0x5BEE,
    0x856E, 0x8261, 0x0052, 0xA09D, 0xCBAE, 0x9EF8, 0x01F5, 0x52E1,
    0xE2D5, 0xC8A4, 0x55F7, 0xB8A8, 0x1121, 0x6813, 0xE576, 0xBCE3,
    0x1112, 0xB2B4, 0x4070, 0x4C3F, 0x5407, 0xF997, 0x9346, 0xD36C,
    0xDFDE, 0x428A, 0xB497, 0x7E59, 0x5157, 0x6DBD, 0x20E0, 0x23F5,
    0x0D70, 0x34BE, 0x8481, 0x744F, 0xD429, 0x4CBC, 0xC51A, 0xBE15,
    0x9F01, 0xD327, 0x8468, 0xF118, 0x3D36, 0x8B2D, 0xF0EC, 0x4CA5,
    0xEDE8, 0xCE3D, 0x3A04, 0xF5AC, 0x5EB5, 0x2187, 0x7BCE, 0x077C,
    0xFCFD, 0xDF80, 0xC98B, 0xE564, 0xE27F, 0xE342, 0xB89A, 0xF7D3,
    0x4F39, 0xBA12, 0xF418, 0x0337, 0x6F4B, 0x13D7, 0x4B05, 0x54A1,
    0x2394, 0x5020, 0xFC80, 0x913E, 0x8252, 0x889D, 0x1FE9, 0xEBDE,
    0x96A4, 0x07DD, 0x959E, 0x80B0, 0x56EB, 0xF72D, 0xA67D, 0xCFC3,
    0xBD24, 0x437E, 0x08C7, 0xE546, 0xFC8E, 0x7F3E, 0x5B7A, 0x85A7,
    0x5609, 0xCF9D, 0xFB15, 0x6ED7, 0x9BF4, 0x3289, 0x5037, 0x0443,
    0x9B2D, 0x1E91, 0x0DE0, 0x60DB, 0xF474, 0xAC45, 0x0A2D, 0xBFCE,
    0x4848, 0x8093, 0x577F, 0x75CB, 0x2727, 0x898B, 0xF1D3, 0x2781,

    0xCC91, 0xC1DA, 0x2F0A, 0x933F, 0xE304, 0x8432, 0x7602, 0x4CB3,     // Ending
    0xE3A0, 0xFA3F, 0x73BA, 0x6F6D, 0xB144, 0xAB32, 0x5C31, 0x7D9D      // PAD
};

const short h[2*NH + 2*PAD] =
{
    0x076E, 0x08B0, 0x04A0, 0x0BA3, 0x0EB2, 0x0E6E, 0x08CC, 0x0DF7,     // Beginning
    0x0AAC, 0x03CE, 0x0ADD, 0x03E7, 0x08CA, 0x06C4, 0x00F6, 0x0CCF,     // PAD

    0x05A0, 0x0CD7, 0x0839, 0x0A5B, 0x0B19, 0x0963, 0x061C, 0x0E43,
    0x01C8, 0x055F, 0x032B, 0x0B3D, 0x0E46, 0x064C, 0x03F2, 0x0281,
    0x099C, 0x0813, 0x0CAB, 0x0E03, 0x0E95, 0x08AF, 0x0994, 0x0278,
    0x08DC, 0x02C1, 0x0A0E, 0x0637, 0x0903, 0x02F1, 0x0F36, 0x0B97,
    0x05B4, 0x0983, 0x0600, 0x0735, 0x07CB, 0x0CB4, 0x04D5, 0x090E,
    0x027B, 0x0CBF, 0x0D4C, 0x0CA5, 0x0D3A, 0x0DD5, 0x0EF7, 0x0866,

    0x0CC9, 0x0C1D, 0x02F0, 0x0933, 0x0E30, 0x0843, 0x0760, 0x04CB,     // Ending
    0x0E3A, 0x0FA3, 0x073B, 0x06F6, 0x0B14, 0x0AB3, 0x05C3, 0x07D9      // PAD
};

short r_c[2*NR + 2*PAD];
short r_i[2*NR + 2*PAD];

/* ======================================================================= */
/* Generate pointers to skip beyond array padding                          */
/* ======================================================================= */
const short *const ptr_x = x + 2*(NH-1) + PAD;
const short *const ptr_h = h + PAD;
short *const ptr_r_c = r_c + PAD;
short *const ptr_r_i = r_i + PAD;

/* ======================================================================= */
/* Prototypes for timing functions                                         */
/* ======================================================================= */
clock_t time_c(int nh, int nr);
clock_t time_i(int nh, int nr);

/* ======================================================================= */
/* MAIN -- Top level driver for testing the algorithm                      */
/* ======================================================================= */
int main()
{
    clock_t t_overhead, t_start, t_stop;
    clock_t t_c, t_i;
    int i, j, k, nh, nr, fail = 0;
    int form_error = 0;
    short diff, diff_max;

    /* =================================================================== */
    /* Initialize timer for clock */
    TSCL= 0,TSCH=0;
    /* Compute overhead of calling _itoll(TSCH, TSCL) twice to get timing info        */
    /* =================================================================== */
    t_start = _itoll(TSCH, TSCL);
    t_stop = _itoll(TSCH, TSCL);
    t_overhead = t_stop - t_start;

    for(nr = 8, i = 1; nr <= NR; nr += 4) {
        for(nh = 4; nh <= NH; i++, nh += 2) {
            /* =================================================================== */
            /* Force uninitialized arrays to fixed values                          */
            /* =================================================================== */
            memset(r_c, 0x5A, sizeof(r_c));
            memset(r_i, 0x5A, sizeof(r_i));

            /* =================================================================== */
            /* Call the individual timing routines, and subtract off overhead      */
            /* =================================================================== */
            t_c = time_c(nh, nr) - t_overhead;    // Calculate time to run Natural C Algorithm
            t_i = time_i(nh, nr) - t_overhead;    // Calculate time to run Optimized C Algorithm

            /* =================================================================== */
            /* Print timing results                                                */
            /* =================================================================== */
            printf("DSP_fir_cplx\tIter#: %d\t", i);

            /* =================================================================== */
            /* Check the results arrays, and report any failures                   */
            /* =================================================================== */
            diff_max = 0;
            for (k = 0; k < 2*NR + 2*PAD; k++) {
                diff = r_c[k] - r_i[k];
                if (diff < 0)
                    diff = -diff;
                if (diff > diff_max)
                    diff_max = diff;
            }
 
            if (diff_max > 1) {
                fail++;
                printf("Result Failure (r_i)");
            }
            else
                printf("Result Successful (r_i)");

            printf("\tNR = %d\tNH = %d\tnatC: %d\toptC: %d\n", nr, nh, t_c, t_i);

            if (nr == CYCLE_FORMULA_NX_PT1 && nh == CYCLE_FORMULA_NR_PT1)
                form_cycle[0] = t_i;
            if (nr == CYCLE_FORMULA_NX_PT1 && nh == CYCLE_FORMULA_NR_PT2)
                form_cycle[1] = t_i;
            if (nr == CYCLE_FORMULA_NX_PT2 && nh == CYCLE_FORMULA_NR_PT1)
                form_cycle[2] = t_i;
            if (nr == CYCLE_FORMULA_NX_PT2 && nh == CYCLE_FORMULA_NR_PT2)
                form_cycle[3] = t_i;
        }
    }

    /* Provide memory information */
#ifdef __TI_COMPILER_VERSION__            // for TI compiler only
    printf("Memory:  %d bytes\n", &kernel_size);
#endif

    /* Provide profiling information */
    for (i = 0; i < FORMULA_SIZE; i++) {
        form_temp[i] = 0;
        for (j = 0; j < FORMULA_SIZE; j++) {
            form_temp[i] += form_inv[i][j] * form_cycle[j];
        }
        if (i != (FORMULA_SIZE-1)) {
            form_result[i] = (int) (form_temp[i] * FORMULA_DEVIDE + 0.5);
            if ((form_result[i] - form_temp[i] * FORMULA_DEVIDE) >  0.1 ||
                (form_result[i] - form_temp[i] * FORMULA_DEVIDE) < -0.1) {
                form_error = 1;
            }
        }
        else {
            form_result[i] = (int) (form_temp[i] + 0.5);
        }
    }

    if (!form_error) {
      printf("Cycles:  ");
      if (form_result[0])
        printf("%d/%d*Nr*Nh + ", form_result[0], FORMULA_DEVIDE);
      if (form_result[1])
        printf("%d/%d*Nr + ", form_result[1], FORMULA_DEVIDE);
      if (form_result[2])
        printf("%d/%d*Nh + ", form_result[2], FORMULA_DEVIDE);
      if (form_result[3])
        printf("%d\n", form_result[3]);
    }
    else
      printf("Cycles Formula Not Available\n");

    return(fail);
}

/* ======================================================================= */
/* Prototypes for timing functions                                         */
/* ======================================================================= */
clock_t time_c(int nh, int nr)
{
    clock_t t_start, t_stop;

    t_start = _itoll(TSCH, TSCL);
    DSP_fir_cplx_cn(ptr_x, ptr_h, ptr_r_c, nh, nr);
    t_stop = _itoll(TSCH, TSCL);
    return t_stop - t_start;
}

clock_t time_i(int nh, int nr)
{
    clock_t t_start, t_stop;

    t_start = _itoll(TSCH, TSCL);
    DSP_fir_cplx(ptr_x, ptr_h, ptr_r_i, nh, nr);
    t_stop = _itoll(TSCH, TSCL);
    return t_stop - t_start;
}

/* ======================================================================= */
/*  End of file:  DSP_fir_cplx_d.c                                         */
/* ----------------------------------------------------------------------- */
/*            Copyright (c) 2011 Texas Instruments, Incorporated.          */
/*                           All Rights Reserved.                          */
/* ======================================================================= */

