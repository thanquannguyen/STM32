/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "usb_device.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_gyroscope.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi5;

/* USER CODE BEGIN PV */
Point pp_down[] = {{120,10}, {100,30}, {140,30}};
Point pp_right[] = {{240,160}, {220,140}, {220,180}};
Point pp_left[] = {{10,160}, {30,140}, {30,180}};
Point pp_up[] = {{120,300}, {100,280}, {140,280}};


int16_t ThresholdHigh = 10;
int16_t ThresholdLow = -10;
float valxyz[3] = {0};
float xval, yval, zval = 0x00;
float absxval, absyval, abszval = 0x00;
int8_t dataOut[256];


float xAngle = 0x00;
float yAngle = 0x00;
float zAngle = 0x00;

char buffer[20];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI5_Init(void);
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
  MX_USB_DEVICE_Init();
  MX_SPI5_Init();
  /* USER CODE BEGIN 2 */
  MX_GPIO_Init();
    BSP_GYRO_Init();
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(1, SDRAM_DEVICE_ADDR);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_DisplayOn();
    BSP_LCD_Clear(LCD_COLOR_BLUE);
    BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  BSP_GYRO_GetXYZ(valxyz);
	  	  xval = valxyz[0];
	  	  yval = valxyz[1];
		  sprintf(dataOut, "Gyr -> GYR_X: %f, GYR_Y: %f, GYR_Z: %f\n", valxyz[0],valxyz[1],valxyz[2]);
		  CDC_Transmit_HS(dataOut,strlen(dataOut));
	  	  if (xval < 0) absxval = -xval;
	  	  else absxval = xval;


	  	  if (yval < 0) absyval = -yval;
	  	  else absyval = yval;


	 if(absxval>2000){
	  	  xAngle += xval*0.05/1000;
	 }

	 if(absyval>2000){
	  	  yAngle += yval*0.05/1000;
	 }


	    if (yAngle < ThresholdLow && xAngle < ThresholdLow){
//	  			BSP_LCD_DisplayStringAtLine(4,"Pos1");
	      BSP_LCD_Clear(LCD_COLOR_BLUE);
	      BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	      BSP_LCD_SetTextColor(LCD_COLOR_WHITE);	  		   	BSP_LCD_FillPolygon(pp_left, 3);
     BSP_LCD_FillPolygon(pp_down, 3);

	    }

		//North West
	    if (yAngle > ThresholdHigh && xAngle < ThresholdLow){
//		  		BSP_LCD_DisplayStringAtLine(4,"Pos2");
	      BSP_LCD_Clear(LCD_COLOR_BLUE);
	      BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	      BSP_LCD_SetTextColor(LCD_COLOR_WHITE);	  		    BSP_LCD_FillPolygon(pp_down, 3);
	   	BSP_LCD_FillPolygon(pp_right, 3);

	    }
		//South East
	    if (yAngle < ThresholdLow && xAngle > ThresholdHigh){
//	  		   	BSP_LCD_DisplayStringAtLine(4,"Pos3");
	      BSP_LCD_Clear(LCD_COLOR_BLUE);
	      BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	      BSP_LCD_SetTextColor(LCD_COLOR_WHITE);	  		   	BSP_LCD_FillPolygon(pp_up, 3);
	   	BSP_LCD_FillPolygon(pp_left, 3);

	    }
		//South West
	    if (yAngle > ThresholdHigh && xAngle > ThresholdHigh){
//		  		BSP_LCD_DisplayStringAtLine(4,"Pos4");
	      BSP_LCD_Clear(LCD_COLOR_BLUE);
	      BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	      BSP_LCD_SetTextColor(LCD_COLOR_WHITE);	  		   	BSP_LCD_FillPolygon(pp_up, 3);
	   	BSP_LCD_FillPolygon(pp_right, 3);
	    }

	    HAL_Delay(50);
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
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI5_Init(void)
{

  /* USER CODE BEGIN SPI5_Init 0 */

  /* USER CODE END SPI5_Init 0 */

  /* USER CODE BEGIN SPI5_Init 1 */

  /* USER CODE END SPI5_Init 1 */
  /* SPI5 parameter configuration*/
  hspi5.Instance = SPI5;
  hspi5.Init.Mode = SPI_MODE_MASTER;
  hspi5.Init.Direction = SPI_DIRECTION_2LINES;
  hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi5.Init.NSS = SPI_NSS_SOFT;
  hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi5.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI5_Init 2 */

  /* USER CODE END SPI5_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
//void Send_Data_to_USB(int16_t *Value_DAT)
//{
//  int8_t dataOut[256];
//    sprintf(dataOut, "Gyr -> GYR_X: %d, GYR_Y: %d, GYR_Z: %d\n", Value_DAT[0], Value_DAT[1], Value_DAT[2]);
//    CDC_Transmit_HS(dataOut, strlen(dataOut));
//  }

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
