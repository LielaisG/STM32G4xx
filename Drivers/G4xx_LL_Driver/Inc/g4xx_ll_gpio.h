/**
 ******************************************************************************
 * @file    g4xx_ll_gpio.h
 * @author  Gatis Fridenbergs
 * @brief   Header file of GPIO LL module.
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
/*                          General-purpose I/Os                              */
/*                                                                            */
/******************************************************************************/

#ifndef __G4XX_LL_GPIO_H__
#define __G4XX_LL_GPIO_H__

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
typedef struct __LL_GPIO_InitTypeDef
{
    FunctionalState         CLOCK;              /*!<  */

    uint32_t                PORT;               /*!<  */

    uint32_t                MODE;               /*!<  */

    uint32_t                OTYPE;              /*!<  */

    uint32_t                SPEED;              /*!<  */

} LL_GPIO_InitTypeDef;

/**
 * @brief
*/
typedef struct __LL_GPIO_HandleTypeDef
{
    GPIO_TypeDef			*Instance;          /*!< Register base address */

    LL_GPIO_InitTypeDef		Init;               /*!< GPIO initialization parameters */

} LL_GPIO_HandleTypeDef;

/**
 * @defgroup GPIO configuration parameters
 * @{
*/
#define GPIOA_CLK_EN        (RCC_AHB2ENR_GPIOAEN)       /*!< IO port A clock enable */
#define GPIOC_CLK_EN        (RCC_AHB2ENR_GPIOCEN)       /*!< IO port C clock enable */
#define BR5                 (GPIO_BSRR_BR5)             /*!< Reset IO port 5 */
#define BR13                (GPIO_BSRR_BR13)            /*!< Reset IO port 13 */
#define MODE5               (GPIO_MODER_MODE5_Pos)      /*!< GPIO Mode register */
#define MODE13              (GPIO_MODER_MODE13_Pos)     /*!< GPIO Mode register */
#define OT5                 (GPIO_OTYPER_OT5_Pos)       /*!< GPIO Output type register */
#define OSPEEDR5            (GPIO_OSPEEDR_OSPEED5_Pos)  /*!< GPIO Speed register */
#define OSPEEDR13           (GPIO_OSPEEDR_OSPEED13_Pos) /*!< GPIO Speed register */
#define PUPDR5              (GPIO_PUPDR_PUPD5_Pos)      /*!< GPIO Pull-up/down register */
#define PUPDR13             (GPIO_PUPDR_PUPD13_Pos)     /*!< GPIO Pull-up/down register */
#define OUTPUT              (0x1UL)                     /*!< GPIO type OUTPUT*/
#define INPUT               (0x0UL)                     /*!< GPIO type INPUT */
#define PUSH_PULL           (0x0UL)                     /*!< GPIO output type PUSH PULL*/
#define LOW_SPEED           (0x0UL)                     /*!< GPIO speed LOW */
#define NO_PULL             (0x0UL)                     /*!< GPIO no pull-up/down */
/**
 * @}
*/

/* Function prototypes ----------------------------------------------------------*/
LL_StatusTypeDef LL_GPIO_Init(LL_GPIO_HandleTypeDef *GPIOx);

#ifdef __cplusplus
}
#endif
#endif /*__G4XX_LL_GPIO_H__ */
