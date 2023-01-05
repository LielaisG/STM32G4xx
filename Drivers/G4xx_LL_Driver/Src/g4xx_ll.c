/**
 ******************************************************************************
 * @file    g4xx_ll.c
 * @author  Gatis Fridenbergs
 * @brief   LL module driver.
 *          This is the common part of the LL initialization
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

#include "g4xx_ll.h"

/**
 * @brief   This function is used to configure the Flash prefetch, the Instruction and 
 *          Data caches, the time base source, NVIC and any required global low level hardware
 * 
 * @note    LL_Init() function is called at the beginning of 
 *          program after reset and before the clock configuration
*/
LL_StatusTypeDef LL_Init(void)
{
    LL_StatusTypeDef status = LL_OK;

    

    return status;
}