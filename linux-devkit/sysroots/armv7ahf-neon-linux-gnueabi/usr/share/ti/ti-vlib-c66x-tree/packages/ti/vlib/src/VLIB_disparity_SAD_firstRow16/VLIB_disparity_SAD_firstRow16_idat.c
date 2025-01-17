/*******************************************************************************
 **+--------------------------------------------------------------------------+**
 **|                            ****                                          |**
 **|                            ****                                          |**
 **|                            ******o***                                    |**
 **|                      ********_///_****                                   |**
 **|                      ***** /_//_/ ****                                   |**
 **|                       ** ** (__/ ****                                    |**
 **|                           *********                                      |**
 **|                            ****                                          |**
 **|                            ***                                           |**
 **|                                                                          |**
 **|         Copyright (c) 2007-2014 Texas Instruments Incorporated           |**
 **|                        ALL RIGHTS RESERVED                               |**
 **|                                                                          |**
 **| Permission to use, copy, modify, or distribute this software,            |**
 **| whether in part or in whole, for any purpose is forbidden without        |**
 **| a signed licensing agreement and NDA from Texas Instruments              |**
 **| Incorporated (TI).                                                       |**
 **|                                                                          |**
 **| TI makes no representation or warranties with respect to the             |**
 **| performance of this computer program, and specifically disclaims         |**
 **| any responsibility for any damages, special or consequential,            |**
 **| connected with the use of this program.                                  |**
 **|                                                                          |**
 **+--------------------------------------------------------------------------+**
 *******************************************************************************/
#include "../common/VLIB_memory.h"
#include "VLIB_disparity_SAD_firstRow16_idat.h"

static uint16_t inpL[] = {
    0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 
    0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15
};

static uint16_t inpRPos[] = {
    0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 
    1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
    2, 3, 4, 5, 6, 7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17,
    3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
};

static uint16_t inpRNeg[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    1, 0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14,
    2, 1, 0, 1, 2, 3, 4, 5, 6, 7,  8,  9, 10, 11, 12, 13,
    3, 2, 1, 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11, 12,
    4, 3, 2, 1, 0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11
};

static uint16_t inpRBoth[] = {
    2, 1, 0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, 12, 13,
    1, 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11, 12, 13, 14,
    0, 1, 2, 3, 4, 5, 6, 7,  8,  9, 10, 11, 12, 13, 14, 15,
    1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
};

static int8_t staticOutPos[] = {
    1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3
};

static int8_t staticOutNeg[] = {
    -1, -1, -1, -1, -1, -1,
    -2, -2, -2, -2, -2, -2,
    -3, -3, -3, -3, -3, -3
};

static int8_t staticOutBoth[] = {
    -1, -1, -1, -1, -1, -1,
     0,  0,  0,  0,  0,  0,
     1,  1,  1,  1,  1,  1
};

static uint16_t inpLRand[] = {
    17767,  9158, 39017, 18547, 56401, 23807, 37962, 22764,  7977, 31949, 22714, 55211, 16882,  7931, 43491, 57670,
      124, 25282,  2132, 10232,  8987, 59880, 52711, 17293,  3958,  9562, 63790, 29283, 49715, 55199, 50377,  1946,
    64358, 23858, 20493, 55223, 47665, 58456, 12451, 55642, 24869, 35165, 45317, 41751, 43096, 23273, 33886, 43220,
    48555, 36018, 53453, 57542, 30363, 40628,  9300, 34321, 50190,  7554, 63604, 34369, 62753, 48445, 36316, 61575,
     6768, 56809, 51262, 54433, 49729, 63713, 44540,  9063, 33342, 24321, 50814, 10903, 47594, 19164, 54123, 30614
};

static uint16_t inpRRand[] = {
    55183, 42040, 22620, 20010, 17132, 31920, 54331,  1787, 39474, 52399, 36156, 36692, 35308,  6936, 32731, 42076,
    63746, 18458, 30974, 47939, 16635,  9978, 57002, 49978, 34299, 42281, 60881, 16358, 61445, 49468, 46972, 51092,
    25973,  4056,  5566, 43105, 35977, 59897, 44892,  9915, 46760, 15513, 46607, 16533, 22449, 13803, 58609, 20659,
    32261, 24047,  3063, 48896, 34025, 60065, 33338,  2789, 36810, 28683, 19147, 32720, 12616,   583, 18276, 38589,
     4639, 23843, 16158, 40616, 18204, 61051, 50532, 64965, 11028, 31603, 15962, 33477, 45406,  9035, 54137, 12131
};

static int8_t staticOutRand[] = {
    0, 8, 8, 5, 1, 1, 
    0, 5, 1, 1, 1, 1, 
    5, 5, 1, 3, 1, 6, 
};

static disparity_SAD_firstRow16_testParams_t    testParams[]=
{
    /********************************************
        {
           testPattern,
           *staticInLeft, *staticInRight, *staticOut,
           width, height, minDisp, maxDisp, windowSize
        },
    *********************************************/

    {
        STATIC,
        inpL, inpRPos, staticOutPos,
        16, 5,  0, 8, 3
    },
    {
        STATIC,
        inpL, inpRNeg, staticOutNeg,
        16, 5, -8, 0, 3
    },
    {
        STATIC,
        inpL, inpRBoth, staticOutBoth,
        16, 5, -4, 4, 3
    },
    {
        STATIC,
        inpLRand, inpRRand, staticOutRand,
        16, 5,  0, 8, 3
    },
    {
        CONSTANT,
        NULL, NULL, NULL,
        64, 8, 0, 8, 5
    },
    {
        RANDOM,
        NULL, NULL, NULL,
        64, 12, 0, 20, 5
    },
    {
        RANDOM,
        NULL, NULL, NULL,
        120, 12, 0, 85, 5
    },
    {
        RANDOM,
        NULL, NULL, NULL,
        120, 24, 0, 85, 9
    },
    {
        RANDOM,
        NULL, NULL, NULL,
        320, 24, 0, 127, 11
    },
    {
        RANDOM,
        NULL, NULL, NULL,
        320, 24, -64, 127, 11
    }
};

/*
 *  Sends the test parameter structure and number of tests
 */
void disparity_SAD_firstRow16_getTestParams(disparity_SAD_firstRow16_testParams_t * *params, int32_t *numTests)
{
    *params = testParams;
    *numTests = sizeof(testParams) / sizeof(disparity_SAD_firstRow16_testParams_t);
}
