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
#include "rcc.h"

/**
 * @brief  The application entry point.
 * @retval int
*/
int main(void)
{
    LL_Init();
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
  /* User can add his own implementation to report the LL error return state */
  __disable_irq();
  while (1){}
}

