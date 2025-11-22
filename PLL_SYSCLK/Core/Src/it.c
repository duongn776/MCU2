/*
 * it.c
 *
 *  Created on: Nov 18, 2025
 *      Author: nhduong
 */


#include "stm32f4xx_hal.h"

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
