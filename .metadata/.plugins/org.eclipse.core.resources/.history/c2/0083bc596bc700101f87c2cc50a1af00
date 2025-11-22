/*
 * main.c
 *
 *  Created on: Nov 18, 2025
 *      Author: nhduong
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

/* Private function prototypes -----------------------------------------------*/
void SystemClockConfig(void);
void UART2_Init(void);
void Error_Handler(void);

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;
char *user_data = "The application is running\r\n";
int main()
{
	RCC_OscInitTypeDef osc_init;
	RCC_ClkInitTypeDef clk_init;
	char msg[100];
	HAL_Init();
	SystemClockConfig();


	memset(&osc_init, 0, sizeof(osc_init));

	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState = RCC_HSE_ON;

	if (HAL_RCC_OscConfig(&osc_init) != HAL_OK)
	{
		Error_Handler();
	}

	clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
						 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;

	clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
	clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2;
	clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
	clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY) != HAL_OK)
	{
		Error_Handler();
	}

	/*---------------------------- AFTER THIS LINE SYSCLK is SOURCED BY HSE------------------*/
	__HAL_RCC_HSI_DISABLE();
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	UART2_Init();
	uint16_t len_of_data = strlen(user_data);
	HAL_UART_Transmit(&huart2, (uint8_t*)user_data, len_of_data, HAL_MAX_DELAY);

	memset(msg,0,sizeof(msg));
	sprintf(msg,"SYSCLK : %ldHz\r\n",HAL_RCC_GetSysClockFreq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg,strlen(msg),HAL_MAX_DELAY);

	memset(msg,0,sizeof(msg));
	sprintf(msg,"HCLK   : %ldHz\r\n",HAL_RCC_GetHCLKFreq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg,strlen(msg),HAL_MAX_DELAY);

	memset(msg,0,sizeof(msg));
	sprintf(msg,"PCLK1  : %ldHz\r\n",HAL_RCC_GetPCLK1Freq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg,strlen(msg),HAL_MAX_DELAY);

	memset(msg,0,sizeof(msg));
	sprintf(msg,"PCLK2  : %ldHz\r\n",HAL_RCC_GetPCLK2Freq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg,strlen(msg),HAL_MAX_DELAY);
	return 0;
}

void SystemClockConfig(void)
{

}

/**
  * @brief UART2 Initialization Function
  * @param None
  * @retval None
  */
void UART2_Init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;

	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
		Error_Handler();
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
