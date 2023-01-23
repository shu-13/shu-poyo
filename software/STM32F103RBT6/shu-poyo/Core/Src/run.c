// Running functions for shu-poyo

#include "run.h"
#include "parameters.h"

void test_run_forward(TIM_HandleTypeDef *htim){
    // Sets the pulse for the duty ratio. 
    // The pulse's maximum value = Counter Period
    // duty ratio = pulse / Counter Period 
    for(uint16_t i=0; i<5; i++){
        __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 18*(i+1));
        __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 18*(i+1));

        HAL_Delay(1000);
    }

    for(uint16_t i=0; i<5; i++){
        __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 18*(5-i));
        __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 18*(5-i));

        HAL_Delay(1000);
    }

}