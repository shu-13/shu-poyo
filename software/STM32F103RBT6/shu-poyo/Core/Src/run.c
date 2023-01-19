// Running functions for shu-poyo

#include "run.h"
#include "parameters.h"

void test_run_forward(TIM_HandleTypeDef *htim){
    // Sets the pulse for the duty ratio. 
    // The pulse's maximum value = Counter Period
    // duty ratio = pulse / Counter Period 
    __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 18);
    __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 18);

    HAL_Delay(1000);

    __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 36);
    __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 36);

    HAL_Delay(1000);

    __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 72);
    __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 72);

    HAL_Delay(1000);

    __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 100);
    __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 100);

    HAL_Delay(1000);

    __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 72);
    __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 72);

    HAL_Delay(1000);
  
    __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 36);
    __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 36);

    HAL_Delay(1000);
}