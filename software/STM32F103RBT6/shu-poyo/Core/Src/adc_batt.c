// Battery ADC functions for shu-poyo

#include "adc_batt.h"
#include "parameters.h"
#include "global_var.h"

extern ADC_HandleTypeDef hadc1;

void check_batt(void){
    HAL_ADC_Start(&hadc1);
}