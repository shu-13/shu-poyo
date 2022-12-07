// Sensors function for shu-poyo
#include "sensors.h"

float read_sensor_R(ADC_HandleTypeDef *hadc, float adc_val){
    SENSOR_OUT_R_ON;

    SENSOR_OUT_R_OFF;
    return adc_val;
}
