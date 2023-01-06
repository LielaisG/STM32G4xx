/**
 ******************************************************************************
 * @file    g4xx_ll_rcc.h
 * @author  Gatis Fridenbergs
 * @brief   Header file of RCC LL module.
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

/******************************************************************************/
/*                                                                            */
/*                        Reset and Clock Control                             */
/*                                                                            */
/******************************************************************************/

#ifndef __G4XX_LL_RCC_H__
#define __G4XX_LL_RCC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "stm32g4xx.h"
#include "stm32g431xx.h"

/**
 * @brief
*/
typedef struct __LL_RCC_InitTypeDef
{
    FunctionalState SYSTEM;         /*!<  */

    FunctionalState LOW_POWER_MODE; /*!<  */

    FunctionalState HSI;            /*!<  */

    uint32_t PLLSRC;                /*!<  */

    uint32_t PLLM;                  /*!<  */

    uint32_t PLLN;                  /*!<  */

    uint32_t PLLR;                  /*!<  */

    uint32_t PLLQ;                  /*!<  */

    uint32_t PLLP;                  /*!<  */

} LL_RCC_InitTypeDef;

/**
 * @brief
*/
typedef struct __LL_RCC_HandleTypeDef
{
    RCC_TypeDef				*Instance;          /*!< Register base address */

    LL_RCC_InitTypeDef		Init;               /*!< RCC initialization parameters */

} LL_RCC_HandleTypeDef;

/**
 * @defgroup RCC configuration parameters
 * @{
*/
/*TODO*/
//#define NVIC_PRIORITYGROUP_4        ((uint32_t)0x00000003)          /*!< 4 bits for pre-emption priority,0 bit  for subpriority */
#define LATENCY_4WS                 (4 << FLASH_ACR_LATENCY_Pos)    /*!< SYSCLK period count to access the Flash */
#define VOS1                        (PWR_CR1_VOS_0)                 /*!< Voltage scaling selection to range 1 */
#define MODE1                       (PWR_CR5_R1MODE)                /*!< Selection for Main Regulator in Range1 */
#define HSION                       (RCC_CR_HSION)                  /*!< Internal High Speed oscillator (HSI16) clock enable */
#define HSITRIM_64                  (64 << RCC_ICSCR_HSITRIM_Pos)   /*!< Value for HSI16 clock trimming */
#define HSI16                       (RCC_PLLCFGR_PLLSRC_1)          /*!< HSI16 clock selected as PLL clock entry */
#define PLLM_DIV4                   (RCC_PLLCFGR_PLLM_2)            /*!< Division factor for the main PLL input clock */
#define PLLN_DIV85                  (85 << RCC_PLLCFGR_PLLN_Pos)    /*!< Main PLL multiplication factor for VCO */
#define PLLR_DIV2                   (0 << RCC_PLLCFGR_PLLR_Pos)     /*!< Main PLL division factor for PLL “R” clock (system clock) */
#define PLLQ_DIV2                   (0 << RCC_PLLCFGR_PLLQ_Pos)     /*!< Main PLL division factor for PLL “Q” clock */
#define PLLP_DIV2                   (RCC_PLLCFGR_PLLPDIV_1)         /*!< Main PLLP division factor */
#define PLLREN                      (RCC_PLLCFGR_PLLREN)            /*!< PLL“R”clockoutputenable */
/**
 * @}
*/

/* Function prototypes ----------------------------------------------------------*/
LL_StatusTypeDef LL_RCC_Init(LL_RCC_HandleTypeDef *RCCx);

#ifdef __cplusplus
}
#endif
#endif /*__G4XX_LL_RCC_H__ */
