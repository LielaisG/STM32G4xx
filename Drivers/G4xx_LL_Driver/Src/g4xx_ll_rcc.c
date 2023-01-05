/**
 ******************************************************************************
 * @file    g4xx_ll_rcc.c
 * @author  Gatis Fridenbergs
 * @brief   RCC LL module driver.
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

#include "g4xx_ll_rcc.h"

/**
 * @brief
*/
LL_StatusTypeDef LL_RCC_Init(LL_RCC_HandleTypeDef *RCCx)
{
    LL_StatusTypeDef tmp_status = LL_OK;

    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    NVIC_SetPriority(SysTick_IRQn, 15);

    /*TODO:
    [] Assure correct function order for system initialization

    NOTE: Use HAL example to do so*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick */
    if (RCCx->Init.SYSTEM)
    {
        RCCx->Instance->APB2ENR     |=  SYSCFGEN;
        RCCx->Instance->APB1ENR1    |=  PWREN;
        PWR->CR3                    |=  UCPD1_DBDIS;
        do {
            FLASH->ACR |= LATENCY_4WS;
        } while (!(FLASH->ACR & FLASH_ACR_LATENCY_4WS));
    }

    /* Configure voltage regulator */
    if (!(RCCx->Init.LOW_POWER_MODE))
    {
        PWR->CR1    |=  VOS1;
        while (PWR->SR2 & PWR_SR2_VOSF);
        PWR->CR5    &=  ~MODE1;
    }

    /* Enable HSI oscillator */
    if (RCCx->Init.HSI) 
    {
        RCC->CR |= HSION;
        while (!(RCC->CR & RCC_CR_HSIRDY));
        RCC->ICSCR  |=  HSITRIM_64;
    }
    
    /* Configure PLL used for SYSCLK Domain */
    RCC->PLLCFGR    |=  (RCCx->Init.PLLSRC |
                        RCCx->Init.PLLM | RCCx->Init.PLLN | RCCx->Init.PLLR |
                        RCCx->Init.PLLQ | RCCx->Init.PLLP |
                        PLLREN);


    return tmp_status;
}