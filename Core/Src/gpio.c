/**
 ******************************************************************************
 * @file    gpio.c
 * @author  Gatis Fridenbergs
 * @brief   This file provides code for the configuration
 *          of all used GPIO pins.
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

#include "gpio.h"

LL_GPIO_HandleTypeDef gpioa;
LL_GPIO_HandleTypeDef gpioc;

/**
 * @brief
 * 
 * @note Configure pins as
 *          - Input
 *          - Output
*/
void GPIO_Init(void)
{
    /* GPIO Ports Clock Enable */
    gpioa.Init.CLOCK = ENABLE;
    gpioc.Init.CLOCK = ENABLE;

    /*Configure GPIO pin : LD3 */
    gpioa.Instance = GPIOA;
    gpioa.Init.PORT = 5;
    gpioa.Init.MODE = OUTPUT;
    gpioa.Init.OTYPE = PUSH_PULL;
    gpioa.Init.SPEED = LOW_SPEED;
    if (LL_GPIO_Init(&gpioa) != LL_OK) Error_Handler();

    /*Configure GPIO pin : PtPin */
    gpioc.Instance = GPIOC;
    gpioc.Init.PORT = 13;
    gpioc.Init.MODE = INPUT;
    if (LL_GPIO_Init(&gpioc) != LL_OK) Error_Handler();
}

