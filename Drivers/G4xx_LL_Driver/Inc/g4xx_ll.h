/**
 ******************************************************************************
 * @file    g4xx_ll.h
 * @author  Gatis Fridenbergs
 * @brief   Header file of LL module.
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

#ifndef __G4XX_LL_H__
#define __G4XX_LL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"



/**
 * @defgroup LL configuration parameters
 * @{
*/
#define ICEN                        (FLASH_ACR_ICEN)                /*!< Instruction cache enable */
#define DCEN                        (FLASH_ACR_DCEN)                /*!< Data cache enable */
#define PREFETCH                    (FLASH_ACR_PRFTEN)              /*!< Prefetch enable */
#define SYSCFGEN                    (RCC_APB2ENR_SYSCFGEN)          /*!< SYSCFG + COMP + VREFBUF + OPAMP clock enable */
#define PWREN                       (RCC_APB1ENR1_PWREN)            /*!< Power interface clock enable */
#define UCPD1_DBDIS                 (PWR_CR3_UCPD_DBDIS)            /*!< USB Type-C and Power Delivery Dead Battery disable. */
/**
 * @}
*/

LL_StatusTypeDef LL_Init(void);
LL_StatusTypeDef LL_InitTick(uint32_t sysClock);

#ifdef __cplusplus
}
#endif
#endif /*__G4XX_LL_H__ */