/**
 ******************************************************************************
 * @file    rcc.c
 * @author  Gatis Fridenbergs
 * @brief   This file provides code for the configuration of 
 *          Reset and Clock Control (RCC).
 * 
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 LielaisG.
 * https://github.com/LielaisG
 * 
 * All rights reserved.
 *
 ******************************************************************************
*/

#include "rcc.h"

LL_RCC_HandleTypeDef rcc;

/**
 * @brief
*/
void RCC_Init(void)
{
    /* Initialize the RCC Oscillators according to the specified parameters */
    rcc.Instance = RCC;
    rcc.Init.LOW_POWER_MODE = DISABLE;
    rcc.Init.SYSCLK_SOURCE = PLLCLK;
    rcc.Init.PLLSRC = HSI16;
    rcc.Init.PLLM = PLLM_DIV4;
    rcc.Init.PLLN = PLLN_DIV85;
    rcc.Init.PLLR = PLLR_DIV2;
    rcc.Init.PLLP = PLLP_DIV2;
    rcc.Init.PLLQ = PLLQ_DIV2;
    rcc.Init.AHB_PRE = HPRE_DIV1;
    rcc.Init.APB1_PRE = PPRE1_DIV1;
    rcc.Init.APB2_PRE = PPRE2_DIV1;
    if (LL_RCC_Init(&rcc) != LL_OK) Error_Handler();
}