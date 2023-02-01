// Running functions for shu-poyo

#include "run.h"
#include "global_var.h"
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

void straight(float length, float init_sp, float max_sp, float tar_sp){
    // Stores the maximum speed
    // This is used in the function used in the timer
    max_speed = max_sp;

    // Checks if the initial speed is bigger than the minimum
    // Also sets the speed value
    if(init_sp < MIN_SPEED_PULSE){
        speed = MIN_SPEED_PULSE;
    }else{
        speed = init_sp;
    }
    // Checks if the target is bigger than the minimum speed
    if(tar_sp < MIN_SPEED_PULSE){
        tar_sp = MIN_SPEED_PULSE;
    }
    // Checks if the initial speed is bigger than the target
    if(init_sp < tar_sp){
        min_speed = MIN_SPEED_PULSE;
    }else{
        min_speed = tar_sp;
    }

    MOTORR_FORWARD; MOTORL_FORWARD;

    // TODO: Read the encoder value and calculate the length
    // while hogehoge


}

void turn(float length, float init_sp, float max_sp, float tar_sp){

}