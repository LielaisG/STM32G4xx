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
    rcc.Instance = RCC;
    rcc.Init.SYSTEM = ENABLE;
    rcc.Init.LOW_POWER_MODE = DISABLE;
    rcc.Init.HSI = ENABLE;
    rcc.Init.PLLSRC = HSI16;
    rcc.Init.PLLM = PLLM_DIV4;
    rcc.Init.PLLN = PLLN_DIV85;
    rcc.Init.PLLR = PLLR_DIV2;
    if (LL_RCC_Init(&rcc) != LL_OK) Error_Handler();
    
}