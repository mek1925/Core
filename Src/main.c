/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "string.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

void ledSelect(uint8_t led);

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint8_t ledStatus = 0;
char TxString[20];
char RxString[10];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_I2C2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
	
	
  HAL_UART_Transmit_IT(&huart1, (uint8_t *)TxString, strlen(TxString));
  HAL_UART_Receive_IT(&huart1, (uint8_t *)RxString, strlen(RxString));

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		ledSelect(ledStatus);
	 //HAL_UART_Transmit_IT(&huart1, (uint8_t *)TxString, strlen(TxString));
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GreenLed_Pin|OrangeLed_Pin|RedLed_Pin|BlueLed_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PushButton_Pin */
  GPIO_InitStruct.Pin = PushButton_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PushButton_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : GreenLed_Pin OrangeLed_Pin RedLed_Pin BlueLed_Pin */
  GPIO_InitStruct.Pin = GreenLed_Pin|OrangeLed_Pin|RedLed_Pin|BlueLed_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  //UNUSED(GPIO_Pin);
	
  if (ledStatus == 4)
  {
    ledStatus = 1;
  }
  else
  {
    ledStatus++;
  }
	//ledSelect(ledStatus);
	
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  //UNUSED(huart);
	
	if (strcmp(RxString, "LEDSTATUS") == 0)
  {
		switch (ledStatus)
    {
    case 1:
      strcpy(TxString,"Green Led ON\n");
		  HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),50);
      break;

    case 2:
      strcpy(TxString,"Orange Led ON");
		  HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),50);
      break;

    case 3:
     strcpy(TxString,"Red Led ON");
		 HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),50);
      break;

    case 4:
      strcpy(TxString,"Blue Led ON");
		  HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),50);
		  break;
    }
        
  }

  if (strcmp(RxString, "GREENON") == 0)
  {
		ledStatus = 1;
		strcpy(TxString,"Green Led ON");
		HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),10);
        
  }

  if (strcmp(RxString, "ORANGEON") == 0)
  {
		ledStatus = 2;
		strcpy(TxString,"Orange Led ON");
		HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),10);
   
  }

  if (strcmp(RxString, "REDON") == 0)
  {
    ledStatus = 3;
		strcpy(TxString,"Red Led ON");
		HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),10);
    
  }

  if (strcmp(RxString, "BLUEON") == 0)
  {
    ledStatus = 4;
		strcpy(TxString,"Blue Led ON");
		HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),10);
    
  }

  HAL_UART_Receive_IT(&huart1, (uint8_t *)RxString, sizeof(RxString));
}

void ledSelect(uint8_t led)
{
	switch (led)
    {
    case 1:
      HAL_Delay(100);
      HAL_GPIO_WritePin(GreenLed_GPIO_Port, GreenLed_Pin, 1);
      HAL_GPIO_WritePin(OrangeLed_GPIO_Port, OrangeLed_Pin, 0);
      HAL_GPIO_WritePin(RedLed_GPIO_Port, RedLed_Pin, 0);
      HAL_GPIO_WritePin(BlueLed_GPIO_Port, BlueLed_Pin, 0);
		  strcpy(TxString,"Green Led ON\n");
		  HAL_UART_Transmit(&huart1, (uint8_t *)TxString, strlen(TxString),50);
		  break;

    case 2:
      HAL_Delay(100);
      HAL_GPIO_WritePin(GreenLed_GPIO_Port, GreenLed_Pin, 0);
      HAL_GPIO_WritePin(OrangeLed_GPIO_Port, OrangeLed_Pin, 1);
      HAL_GPIO_WritePin(RedLed_GPIO_Port, RedLed_Pin, 0);
      HAL_GPIO_WritePin(BlueLed_GPIO_Port, BlueLed_Pin, 0);
		  break;

    case 3:
      HAL_Delay(100);
      HAL_GPIO_WritePin(GreenLed_GPIO_Port, GreenLed_Pin, 0);
      HAL_GPIO_WritePin(OrangeLed_GPIO_Port, OrangeLed_Pin, 0);
      HAL_GPIO_WritePin(RedLed_GPIO_Port, RedLed_Pin, 1);
      HAL_GPIO_WritePin(BlueLed_GPIO_Port, BlueLed_Pin, 0);
		  break;

    case 4:
      HAL_Delay(100);
      HAL_GPIO_WritePin(GreenLed_GPIO_Port, GreenLed_Pin, 0);
      HAL_GPIO_WritePin(OrangeLed_GPIO_Port, OrangeLed_Pin, 0);
      HAL_GPIO_WritePin(RedLed_GPIO_Port, RedLed_Pin, 0);
      HAL_GPIO_WritePin(BlueLed_GPIO_Port, BlueLed_Pin, 1);
      break;
    }
		
}



/* USER CODE END 4 */

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

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
