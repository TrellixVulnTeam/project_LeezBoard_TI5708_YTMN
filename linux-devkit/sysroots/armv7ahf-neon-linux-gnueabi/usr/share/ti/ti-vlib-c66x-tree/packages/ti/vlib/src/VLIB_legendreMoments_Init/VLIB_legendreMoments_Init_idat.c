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
 **|         Copyright (c) 2007-2015 Texas Instruments Incorporated           |**
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
#include "VLIB_legendreMoments_Init_idat.h"

static int16_t origIm[400] = {
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};

static int16_t    GT_LMoments[49] =
{
    12888,  -45,    -19540, -56,    1755,   -77,    11024,
    -36,    -54,    -30,    -126,   -162,   -198,   -312,
    -19560, -135,   29300,  -350,   -3195,  -605,   -17485,
    0,  0,  0,  0,  0,  0,  0,
    1728,   -243,   -3150,  -630,   -648,   -990,   468,
    0,  0,  0,  0,  0,  0,  0,
    10920,  -351,   -17290, -1001,  234,    -1287,  8112
};


static legendreMomentsInit_testParams_t    testParams[]=
{
    /********************************************
        {
           testPattern,
           *staticIn, *staticOut,
           ImH, Order, maxValue
        },
    *********************************************/
    {
        STATIC,
        origIm, GT_LMoments,
        20, 6, 255
    },
    {
        RANDOM,
        NULL, NULL,
        20, 6, 32767
    },
    {
        RANDOM,
        NULL, NULL,
        80, 6, 32767
    },
    {
        RANDOM,
        NULL, NULL,
        128, 6, 32767
    },
    {
        RANDOM,
        NULL, NULL,
        256, 6, 32767
    },
    {
        RANDOM,
        NULL, NULL,
        80, 20, 32767
    },
    {
        RANDOM,
        NULL, NULL,
        128, 20, 32767
    },
    {
        RANDOM,
        NULL, NULL,
        256, 20, 32767
    },
};

/*
 *  Sends the test parameter structure and number of tests
 */
void legendreMomentsInit_getTestParams(legendreMomentsInit_testParams_t * *params, int32_t *numTests)
{
    *params = testParams;
    *numTests = sizeof(testParams) / sizeof(legendreMomentsInit_testParams_t);
}
