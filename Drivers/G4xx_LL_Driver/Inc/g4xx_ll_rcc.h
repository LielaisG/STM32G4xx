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
    FunctionalState LOW_POWER_MODE; /*!<  */

    uint32_t SYSCLK_SOURCE;         /*!<  */

    uint32_t PLLSRC;                /*!<  */

    uint32_t PLLM;                  /*!<  */

    uint32_t PLLN;                  /*!<  */

    uint32_t PLLR;                  /*!<  */

    uint32_t PLLQ;                  /*!<  */

    uint32_t PLLP;                  /*!<  */

    uint32_t AHB_PRE;               /*!<  */

    uint32_t APB1_PRE;              /*!<  */

    uint32_t APB2_PRE;              /*!<  */

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
//#define NVIC_PRIORITYGROUP_4        ((uint32_t)0x00000003)                /*!< 4 bits for pre-emption priority,0 bit  for subpriority */
#define LATENCY_4WS                 (0x4UL << FLASH_ACR_LATENCY_Pos)        /*!< SYSCLK period count to access the Flash */
#define VOS1                        (0x1UL << PWR_CR1_VOS_Pos)              /*!< Voltage scaling selection to range 1 */
#define MODE1                       (PWR_CR5_R1MODE)                        /*!< Selection for Main Regulator in Range1 */
#define HSION                       (RCC_CR_HSION)                          /*!< Internal High Speed oscillator (HSI16) clock enable */
#define HSITRIM_64                  (0x40UL << RCC_ICSCR_HSITRIM_Pos)       /*!< Value for HSI16 clock trimming */
#define HSI16                       (RCC_PLLCFGR_PLLSRC_1)                  /*!< HSI16 clock selected as PLL clock entry */
#define PLLCLK                      (RCC_CFGR_SW_PLL)                       /*!< PLL selection as system clock */
#define PLLM_DIV4                   (0x3UL << RCC_PLLCFGR_PLLM_Pos)         /*!< Division factor for the main PLL input clock */
#define PLLN_DIV85                  (0x55UL << RCC_PLLCFGR_PLLN_Pos)        /*!< Main PLL multiplication factor for VCO */
#define PLLR_DIV2                   (0x0UL << RCC_PLLCFGR_PLLR_Pos)         /*!< Main PLL division factor for PLL “R” clock (system clock) */
#define PLLQ_DIV2                   (0x0UL << RCC_PLLCFGR_PLLQ_Pos)         /*!< Main PLL division factor for PLL “Q” clock */
#define PLLP_DIV2                   (0x2UL << RCC_PLLCFGR_PLLPDIV_Pos)                 /*!< Main PLLP division factor */
#define PLLREN                      (RCC_PLLCFGR_PLLREN)                    /*!< PLL“R”clockoutputenable */
#define HPRE_DIV2                   (0x8UL << RCC_CFGR_HPRE_Pos)            /*!< SYSCLK divided by 2 */
#define HPRE_DIV1                   (RCC_CFGR_HPRE_DIV1)                    /*!< SYSCLK not divided */
#define PPRE1_DIV1                  (RCC_CFGR_PPRE1_DIV1)                   /*!< HCLK not divided */
#define PPRE2_DIV1                  (RCC_CFGR_PPRE2_DIV1)                   /*!< HCLK not divided */
/**
 * @}
*/

/* Function prototypes ----------------------------------------------------------*/
LL_StatusTypeDef LL_RCC_Init(LL_RCC_HandleTypeDef *RCCx);

#ifdef __cplusplus
}
#endif
#endif /*__G4XX_LL_RCC_H__ */
