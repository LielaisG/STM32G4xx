/**
 ******************************************************************************
 * @file    main.h
 * @author  Gatis Fridenbergs
 * @brief   Header for main.c file.
 *          This file contains the common defines of the application.
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

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief
*/
typedef enum
{
    LL_OK       = 0x00U,
    LL_ERROR    = 0x01U,
    LL_BUSY     = 0x02U,
    LL_TIMEOUT  = 0x03U
} LL_StatusTypeDef;

#include "stm32g4xx_hal.h"
#include "g4xx_ll.h"
#include "g4xx_ll_rcc.h"
#include "g4xx_ll_gpio.h"

void Error_Handler(void);

#define BTN_Pin GPIO_PIN_13
#define BTN_GPIO_Port GPIOC
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
