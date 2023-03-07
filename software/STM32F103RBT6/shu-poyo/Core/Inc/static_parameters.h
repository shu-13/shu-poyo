// Static parameters for shu-poyo
#ifndef __STATIC_PARAMETERS_H

#include "stm32f1xx_hal.h"

// Maze info
#define FULL_SECTION (180.0) // in mm
#define HALF_SECTION (FULL_SECTION * 0.5) // in mm
#define MAZE_SIZE_X (16)
#define MAZE_SIZE_Y (16)
#define GOAL_X      (7)
#define GOAL_Y      (8)

// System
#define SYSCLOCK_HZ (36000000)
#define PI  (3.14159265359)

// Battery
#define BATT_MIN (2700) // About 5.4V

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
#define LED0_ON HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 1);
#define LED0_OFF HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0);
#define LED1_ON HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 1);
#define LED1_OFF HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 0);
#define LED2_ON HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 1);
#define LED2_OFF HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, 0);
#define LED3_ON HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);
#define LED3_OFF HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);

// Switches
#define READ_SW0 HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
#define READ_SW1 HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
#define READ_SW2 HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);

#define SW_ON (0)
#define SW_OFF (1)

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
// These are defined in sensors.h

// Motors
// Sets the motor mode to PHASE/ENABLE
#define MOTOR_MODE_SET_PE HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);
#define MOTORR_FORWARD HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
#define MOTORR_BACK HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
#define MOTORL_FORWARD HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
#define MOTORL_BACK HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
#define MOTORR_CH2 TIM_CHANNEL_4
#define MOTORL_CH2 TIM_CHANNEL_2
// PWM values
#define MOTOR_PWM_FREQ (100000)
#define MOTOR_PRESCALER (1)
#define MOTOR_COUNTER_PERIOD (SYSCLOCK_HZ / (MOTOR_PWM_FREQ * MOTOR_PRESCALER))
#define MIN_DUTY_RATE (0.05)  // Sets the minimum duty rate to 5%
#define MIN_SPEED_PULSE (MOTOR_COUNTER_PERIOD * MIN_DUTY_RATE)
#define MIN_SPEED (0) // TODO: Calculate this value from the pulse?
// Gear related variables
#define PINION_GEAR_TEETH (14.0)
#define WHEEL_GEAR_TEETH (45.0)
#define GEAR_RATIO (PINION_GEAR_TEETH / WHEEL_GEAR_TEETH)

// Encoder
#define PULSES_PER_ROTATE (4096.0)      // The amount of pulses per rotation

#define __STATIC_PARAMETERS_H

#endif /* __STATIC_PARAMETERS_H */