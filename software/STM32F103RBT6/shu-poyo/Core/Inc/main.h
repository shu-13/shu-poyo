/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "parameters.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
int __io_putchar(int ch);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Light_Right_OUT_Pin GPIO_PIN_0
#define Light_Right_OUT_GPIO_Port GPIOC
#define Light_Right_IN11_Pin GPIO_PIN_1
#define Light_Right_IN11_GPIO_Port GPIOC
#define Light_FrontRight_OUT_Pin GPIO_PIN_2
#define Light_FrontRight_OUT_GPIO_Port GPIOC
#define Light_FrontRight_IN13_Pin GPIO_PIN_3
#define Light_FrontRight_IN13_GPIO_Port GPIOC
#define EncoderL_CH1_Pin GPIO_PIN_0
#define EncoderL_CH1_GPIO_Port GPIOA
#define EncoderL_CH2_Pin GPIO_PIN_1
#define EncoderL_CH2_GPIO_Port GPIOA
#define ADC_BATT_Pin GPIO_PIN_2
#define ADC_BATT_GPIO_Port GPIOA
#define BUZZ_Level_Pin GPIO_PIN_4
#define BUZZ_Level_GPIO_Port GPIOA
#define BUZZ_OnOff_Pin GPIO_PIN_5
#define BUZZ_OnOff_GPIO_Port GPIOA
#define EncoderR_CH1_Pin GPIO_PIN_6
#define EncoderR_CH1_GPIO_Port GPIOA
#define EncoderR_CH2_Pin GPIO_PIN_7
#define EncoderR_CH2_GPIO_Port GPIOA
#define Light_FrontLeft_OUT_Pin GPIO_PIN_4
#define Light_FrontLeft_OUT_GPIO_Port GPIOC
#define Light_FrontLeft_IN15_Pin GPIO_PIN_5
#define Light_FrontLeft_IN15_GPIO_Port GPIOC
#define Light_Left_IN8_Pin GPIO_PIN_0
#define Light_Left_IN8_GPIO_Port GPIOB
#define Light_Left_OUT_Pin GPIO_PIN_1
#define Light_Left_OUT_GPIO_Port GPIOB
#define SPI2_CS_Pin GPIO_PIN_12
#define SPI2_CS_GPIO_Port GPIOB
#define SW0_Pin GPIO_PIN_7
#define SW0_GPIO_Port GPIOC
#define SW1_Pin GPIO_PIN_8
#define SW1_GPIO_Port GPIOC
#define SW2_Pin GPIO_PIN_9
#define SW2_GPIO_Port GPIOC
#define MotorL_CH1_Pin GPIO_PIN_8
#define MotorL_CH1_GPIO_Port GPIOA
#define MotorL_CH2_Pin GPIO_PIN_9
#define MotorL_CH2_GPIO_Port GPIOA
#define MotorR_CH1_Pin GPIO_PIN_10
#define MotorR_CH1_GPIO_Port GPIOA
#define MotorR_CH2_Pin GPIO_PIN_11
#define MotorR_CH2_GPIO_Port GPIOA
#define Motor_Mode_Pin GPIO_PIN_12
#define Motor_Mode_GPIO_Port GPIOA
#define LED0_Pin GPIO_PIN_10
#define LED0_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_11
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_12
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOD
#define BAT_LED_Pin GPIO_PIN_8
#define BAT_LED_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
