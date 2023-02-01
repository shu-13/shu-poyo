// Battery ADC functions for shu-poyo

#include "adc_batt.h"
#include "parameters.h"
#include "global_var.h"

extern ADC_HandleTypeDef hadc1;

void check_batt(void){
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    batt_val = HAL_ADC_GetValue(&hadc1);

    if(batt_val < BATT_MIN){
        BATT_LEVEL = 0;
    }else{
        BATT_LEVEL = 1;
    }
}

void get_batt_level(void){
    printf("BATT_LEVEL: %4d \n\r", batt_val);
    printf("========== \n\r");
}