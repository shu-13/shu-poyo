// Sensor functions for shu-poyo
#ifndef __SENSORS_H

#include "stm32f1xx_hal.h"
#include "parameters.h"

// How should i give the ADC guy...?
float read_sensor_R(ADC_HandleTypeDef *hadc, float adc_val);
// float read_sensor_FR(ADC_HandleTypeDef *hadc, float adc_val);
// float read_sensor_FL(ADC_HandleTypeDef *hadc, float adc_val);
// float read_sensor_L(ADC_HandleTypeDef *hadc, float adc_val);

#define __SENSORS_H

#endif /* __SENSORS_H */