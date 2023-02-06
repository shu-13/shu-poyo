// Running functions for shu-poyo

#include "run.h"
#include "global_var.h"
#include "parameters.h"

// From the motor.c
extern stENCODER_DATA st_left_enc_data;
extern stENCODER_DATA st_right_enc_data;

void test_run_forward(TIM_HandleTypeDef *htim){
    // Sets the pulse for the duty ratio. 
    // The pulse's maximum value = Counter Period
    // duty ratio = pulse / Counter Period 
    for(uint8_t i=0; i<5; i++){
        __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 18*(i+1));
        __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 18*(i+1));

        HAL_Delay(1000);
    }

    for(uint8_t i=0; i<5; i++){
        __HAL_TIM_SET_COMPARE(htim, MOTORL_CH2, 18*(5-i));
        __HAL_TIM_SET_COMPARE(htim, MOTORR_CH2, 18*(5-i));

        HAL_Delay(1000);
    }
}

void straight(float length, float max_acc, float init_sp, float max_sp, float tar_sp){
    // Stores the maximum speed
    // This is used in the function used in the timer
    max_speed = max_sp;
    accel = max_acc;

    // Checks if the initial speed is bigger than the minimum
    // Also sets the speed value
    if(init_sp < MIN_SPEED){
        speed = MIN_SPEED;
    }else{
        speed = init_sp;
    }
    // Checks if the target is bigger than the minimum speed
    if(tar_sp < MIN_SPEED){
        tar_sp = MIN_SPEED;
    }
    // Checks if the initial speed is bigger than the target
    if(init_sp < tar_sp){
        min_speed = MIN_SPEED;
    }else{
        min_speed = tar_sp;
    }

    // The travelling distance to reach the maximum speed
    float ref_dist_inc = 1 / 2 * accel * ((max_speed - speed) / accel)*((max_speed - speed) / accel);
    // The travelling distance to reach the target speed
    float ref_dist_dec = 1 / 2 * accel * ((max_speed - min_speed) / accel)*((max_speed - min_speed) / accel);

    MOTORR_FORWARD; MOTORL_FORWARD;

    // TODO: Fix this. You should use the right one too, right?
    while(st_left_enc_data.travel_dist < ref_dist_inc);

    // This is when the speed is consistant
    // TODO: Fix this.
    accel = 0.0;
    while(st_left_enc_data.travel_dist < length - (ref_dist_inc + ref_dist_dec));
    
    // This is when the speed is decreasing
    // TODO: Fix this.
    accel = (-1) * max_acc;
    while(st_left_enc_data.travel_dist < length);

}

void turn(float length, float max_acc, float init_sp, float max_sp, float tar_sp){

}