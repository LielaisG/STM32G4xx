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
 * 
 * @retval  LL status
*/
LL_StatusTypeDef LL_Init(void)
{
    LL_StatusTypeDef status = LL_OK;

    /* Configure Flash prefetch, Instruction cache, Data cache */
#if (INSTRUCTION_CACHE_ENABLE)
    FLASH->ACR |= ICEN;
#endif /* INSTRUCTION_CACHE_ENABLE */
#if (DATA_CACHE_ENABLE)
    FLASH->ACR |= DCEN;
#endif /* DATA_CACHE_ENABLE */
#if (PREFETCH_ENABLE)
    FLASH->ACR |= PREFETCH;
#endif /* PREFETCH_CACHE_ENABLE */

    /* Set Interrupt Group Priority */
    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    /* Configure the SysTick to have interrupt in 1ms time basis*/
    if (LL_InitTick(SystemCoreClock) != LL_OK) status = LL_ERROR;

    /* Initialize global MSP */
    RCC->APB2ENR     |=  SYSCFGEN;
    RCC->APB1ENR1    |=  PWREN;
    PWR->CR3         |=  UCPD1_DBDIS;

    

    return status;
}

/**
 * @brief   This function configures the source of the time base:
 *          The time source is configured to have 1ms time base with a dedicated
 *          Tick interrupt priority.
 * 
 * @note    This function is called  automatically at the beginning of program after
 *          reset by LL_Init() or at any time when clock is reconfigured.
 * 
 * @note    In the default implementation, SysTick timer is the source of time base.
 *          It is used to generate interrupts at regular time intervals.
 *          Care must be taken if LL_Delay() is called from a peripheral ISR process,
 *          The SysTick interrupt must have higher priority (numerically lower)
 *          than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
 *          implementation  in user file.
 * 
 * @retval  LL status
*/
LL_StatusTypeDef LL_InitTick(uint32_t sysClock)
{
    LL_StatusTypeDef status = LL_OK;

    /* Configure the SysTick to have interrupt in 1ms time base */
  	SysTick->LOAD  = (uint32_t)((sysClock / 1000U) - 1UL);         	    /*Set reload register*/
  	//NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); 	/* set Priority for Systick Interrupt */
	SysTick->VAL   = 0UL;                                           	/*Load the SysTick Counter Value*/
  	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk   |
    	            SysTick_CTRL_ENABLE_Msk;                        	/*Enable the Systick Timer*/

    /* Set interrupt priority */
    NVIC_SetPriority(SysTick_IRQn, 0);

    /* This function sets directly SystemCoreClock CMSIS variable. */
    SystemCoreClock = sysClock;

    return status;
}