/**
 ******************************************************************************
 * @file    main.c
 * @author  Gatis Fridenbergs
 * @brief   Main program body.
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

#include "main.h"
#include "gpio.h"
#include "rcc.h"

/**
 * @brief  The application entry point.
 * @retval int
*/
int main(void)
{
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	LL_Init();

    /* Configure the system clock */
	RCC_Init();

	/* Infinite loop */
	while (1)
	{
		
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
*/
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}
