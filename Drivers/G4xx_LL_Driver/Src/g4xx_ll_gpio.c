/**
 ******************************************************************************
 * @file    g4xx_ll_rcc.c
 * @author  Gatis Fridenbergs
 * @brief   GPIO LL module driver.
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

#include "g4xx_ll_gpio.h"

/**
 * @brief Initialize the GPIOx peripheral according to the specified parameters.
*/
LL_StatusTypeDef LL_GPIO_Init(LL_GPIO_HandleTypeDef *GPIOx)
{
    LL_StatusTypeDef tmp_status = LL_OK;

    /* Enable clock for the GPIO and reset it */
    if (GPIOx->Init.CLOCK == ENABLE)
    {
        if (GPIOx->Instance == GPIOA)
        {
            RCC->AHB2ENR    |=  GPIOA_CLK_EN;
            if (GPIOx->Init.PORT == 5)
            {
                GPIOx->Instance->BRR    |=  BR5;
            }
        }
        else if (GPIOx->Instance == GPIOC)
        {
            RCC->AHB2ENR    |=  GPIOC_CLK_EN;
            if (GPIOx->Init.PORT == 13)
            {
                GPIOx->Instance->BRR    |=  BR13;
            }
        }  
    }
    else
    {
        tmp_status = LL_ERROR;
    }

    /* GPIO mode configuration */
    if (GPIOx->Init.MODE == OUTPUT)
    {
        if (GPIOx->Init.PORT == 5)
        {
            GPIOx->Instance->MODER      |=  (OUTPUT << MODE5);
            GPIOx->Instance->OTYPER     |=  (PUSH_PULL << OT5);
            GPIOx->Instance->OSPEEDR    |=  (LOW_SPEED << OSPEEDR5);
            GPIOx->Instance->PUPDR      |=  (NO_PULL << PUPDR5);
        }
    }
    else if (GPIOx->Init.MODE == INPUT)
    {
        if (GPIOx->Init.PORT == 13)
        {
            GPIOx->Instance->MODER  |=  (INPUT << MODE13);
            GPIOx->Instance->OSPEEDR    |=  (LOW_SPEED << OSPEEDR13);
            GPIOx->Instance->PUPDR      |=  (NO_PULL << PUPDR13);
        }
    }
    else
    {
        tmp_status = LL_ERROR;
    }

    return tmp_status;
}