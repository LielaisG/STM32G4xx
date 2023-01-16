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
 * @brief Initialize the RCC Oscillators according to the specified parameters
*/
LL_StatusTypeDef LL_RCC_Init(LL_RCC_HandleTypeDef *RCCx)
{
    LL_StatusTypeDef tmp_status = LL_OK;

    /* Configure Flash latency */
    do {
        FLASH->ACR |= LATENCY_4WS;
        FLASH->ACR &= ~FLASH_ACR_LATENCY_1WS;
    } while (!(FLASH->ACR & FLASH_ACR_LATENCY_4WS));

    /* Configure voltage regulator */
    if (!(RCCx->Init.LOW_POWER_MODE))
    {
        PWR->CR1    |=  VOS1;
        while (PWR->SR2 & PWR_SR2_VOSF);
        PWR->CR5    &=  ~MODE1;
    }

    /* Configure System clock */
    if (RCCx->Init.SYSCLK_SOURCE == PLLCLK) 
    {
        do {
            RCC->CR |= HSION;
        } while (!(RCC->CR & RCC_CR_HSIRDY));
        RCC->ICSCR  |=  HSITRIM_64;

        /* Adapt Systick interrupt period */
        

        if (RCC->CR & RCC_CR_PLLON) RCC->CR &= ~RCC_CR_PLLON;
        do {
            /* Configure PLL used for SYSCLK Domain */
            RCC->PLLCFGR    =  (RCCx->Init.PLLSRC | \
                                RCCx->Init.PLLM | RCCx->Init.PLLN | RCCx->Init.PLLR | \
                                RCCx->Init.PLLQ | RCCx->Init.PLLP | 
                                PLLREN);

            /* Enable main PLL */                    
            RCC->CR |=  RCC_CR_PLLON;
        } while(!(RCC->CR & RCC_CR_PLLRDY));

        RCC->CFGR   |=  HPRE_DIV2;

        /* Initialize the CPU, AHB and APB buses clocks */
        RCC->CFGR   =  (RCCx->Init.SYSCLK_SOURCE | \
                        RCCx->Init.AHB_PRE | \
                        RCCx->Init.APB1_PRE | \
                        RCCx->Init.APB2_PRE);
        
        /* Update the SystemCoreClock global variable */
        LL_InitTick(170000000);
    }

    return tmp_status;
}