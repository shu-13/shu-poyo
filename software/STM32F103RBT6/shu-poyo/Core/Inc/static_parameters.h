// Static parameters for shu-poyo
#ifndef __STATIC_PARAMETERS_H

#include "stm32f1xx_hal.h"

// Buzzer
#define BUZZER_LO_ON HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
#define BUZZER_LO_OFF HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
#define BUZZER_HI_ON HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
#define BUZZER_HI_OFF HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);

// LEDs
#define TOGGLE_LED0 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);
#define TOGGLE_LED1 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_11);
#define TOGGLE_LED2 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_12);
#define TOGGLE_LED3 HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);

// Switches
#define READ_SW0 HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
#define READ_SW1 HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
#define READ_SW2 HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);

// Light sensor - Emmit
#define SENSOR_OUT_R_ON HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
#define SENSOR_OUT_R_OFF HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
#define SENSOR_OUT_FR_ON HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 1);
#define SENSOR_OUT_FR_OFF HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
#define SENSOR_OUT_FL_ON HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
#define SENSOR_OUT_FL_OFF HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
#define SENSOR_OUT_L_ON HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
#define SENSOR_OUT_L_OFF HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);

// Ligh sensor - Collect
// #define SENSOR_IN_R_ON

// Motors
// Sets the motor mode to PHASE/ENABLE
#define MOTOR_MODE_SET_PE HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);
#define MOTORR_FORWARD HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
#define MOTORR_BACK HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
#define MOTORL_FORWARD HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
#define MOTORL_BACK HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
#define MOTORR_CH2 TIM_CHANNEL_4
#define MOTORL_CH2 TIM_CHANNEL_2

// Encoder


#define __STATIC_PARAMETERS_H

#endif /* __STATIC_PARAMETERS_H */