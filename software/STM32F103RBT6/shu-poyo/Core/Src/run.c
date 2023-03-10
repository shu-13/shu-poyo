// Running functions for shu-poyo

#include "run.h"
#include "motors.h"
#include "global_var.h"
#include "parameters.h"

// From the main.c
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

// From the motor.c
extern stENCODER_DATA st_left_enc_data;
extern stENCODER_DATA st_right_enc_data;

void speed_val_init(void){
    init_speed = 0.0;

    prev_speed = 0.0;
    min_speed = 0.0;
    max_speed = 0.0;
    goal_speed = 0.0;
    accel = 0.0;
    r_accel = 0.0;

    err_speed = 0.0;
    err_sum = 0.0;
    v_PID = 0.0;
}

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
    // Reseting the encoder
    motor_encode_init();
    // DEBUG
    // get_encoder_val();
    // Reseting the speed variables
    speed_val_init();
    // Sets RUN MODE
    RUN_MODE = MODE_FORWARD;
    MOTORL_FORWARD; MOTORR_FORWARD;

    // Stores the maximum speed
    // This is used in the function used in the timer
    max_speed = max_sp;
    accel = max_acc;

    // Checks if the initial speed is lower than the minimum
    // Also sets the speed value
    if(init_sp < MIN_SPEED){
        init_speed = MIN_SPEED;
    }else{
        init_speed = init_sp;
    }
    // Checks if the target is lower than the minimum speed
    if(tar_sp < MIN_SPEED){
        tar_sp = MIN_SPEED;
    }
    // Checks if the initial speed is bigger than the target
    if(init_sp < tar_sp){
        min_speed = MIN_SPEED;
    }else{
        min_speed = tar_sp;
    }

    // The travelling distance to reach the maximum speed (at the beginning of the length)
    float ref_dist_inc = 0.5 * accel * ((max_speed - init_speed) / accel)*((max_speed - init_speed) / accel);
    // The travelling distance to reach the target speed (towards the end of the length)
    float ref_dist_dec = 0.5 * accel * ((max_speed - min_speed) / accel)*((max_speed - min_speed) / accel);


    // This is when the speed is increasing
    goal_speed = max_speed;
    while((0.5 * (st_left_enc_data.travel_dist + st_right_enc_data.travel_dist)) < ref_dist_inc);

    // This is when the speed is consistant
    accel = 0.0;
    while((0.5 * (st_left_enc_data.travel_dist + st_right_enc_data.travel_dist)) < (length - ref_dist_dec));
    
    // This is when the speed is decreasing
    goal_speed = min_speed;
    accel = (-1.0) * max_acc;
    while((0.5 * (st_left_enc_data.travel_dist + st_right_enc_data.travel_dist)) < length);

    // DEBUG
    // printf("Calculated travel distance : %4.2f \n\r",
    //         0.5 * (st_left_enc_data.travel_dist + st_right_enc_data.travel_dist)); // ok
}

void turn(float length, float max_acc, float init_sp, float max_sp, float tar_sp){

}

void rotate(enNEXT_DIRECTION n_dir, int rot_num){
    // Initiate values
    motor_encode_init();
    speed_val_init();

    // Sets the motor direction
    RUN_MODE = MODE_ROTATE;
    NEXT_DIR = n_dir;

    // Sets the rotation speed and accel
    max_speed = ROT_SPEED;
    accel = ROT_ACCEL;

    // Calculates the length (1/4 circle * rot_num)
    // float r_length = TREAD_WIDTH * PI * 0.25 * (float)rot_num;
    // THERE'S STILL A BUG! GIVING A SMALLER VAL
    float r_length = 0.25 * TREAD_WIDTH * PI * 0.25 * (float)rot_num;

    // The travelling distance to reach the maximum / stopping speed
    // At the beginning and end of the route
    float ref_dist = 0.5 * accel * (max_speed / accel)*(max_speed / accel);

    // This is when the speed is increasing
    goal_speed = max_speed;
    while((0.5 * ((st_left_enc_data.travel_dist) * (st_left_enc_data.travel_dist)
                     + (st_right_enc_data.travel_dist) * (st_left_enc_data.travel_dist)))
             < (ref_dist * ref_dist));

    // This is when the speed is consistant
    accel = 0.0;
    while((0.5 * ((st_left_enc_data.travel_dist) * (st_left_enc_data.travel_dist)
                     + (st_right_enc_data.travel_dist) * (st_left_enc_data.travel_dist)))
            < ((r_length - ref_dist) * (r_length - ref_dist)));
    
    // This is when the speed is decreasing
    goal_speed = 0.0;
    accel = (-1.0) * ROT_ACCEL;
    while((0.5 * ((st_left_enc_data.travel_dist) * (st_left_enc_data.travel_dist)
                     + (st_right_enc_data.travel_dist) * (st_left_enc_data.travel_dist)))
            < (r_length * r_length));    
}

void back(float length, float max_acc, float init_sp, float max_sp, float tar_sp){
    // Reseting the encoder
    motor_encode_init();
    // Reseting the speed variables
    speed_val_init();
    // Sets RUN MODE
    RUN_MODE = MODE_REAR;
    MOTORL_BACK; MOTORL_BACK;

    // Stores the maximum speed
    // This is used in the function used in the timer
    max_speed = max_sp;
    accel = max_acc;

    // Checks if the initial speed is lower than the minimum
    // Also sets the speed value
    if(init_sp < MIN_SPEED){
        init_speed = MIN_SPEED;
    }else{
        init_speed = init_sp;
    }
    // Checks if the target is lower than the minimum speed
    if(tar_sp < MIN_SPEED){
        tar_sp = MIN_SPEED;
    }
    // Checks if the initial speed is bigger than the target
    if(init_sp < tar_sp){
        min_speed = MIN_SPEED;
    }else{
        min_speed = tar_sp;
    }

    // The travelling distance to reach the maximum speed (at the beginning of the length)
    float ref_dist_inc = 0.5 * accel * ((max_speed - init_speed) / accel)*((max_speed - init_speed) / accel);
    // The travelling distance to reach the target speed (towards the end of the length)
    float ref_dist_dec = 0.5 * accel * ((max_speed - min_speed) / accel)*((max_speed - min_speed) / accel);


    // This is when the speed is increasing
    goal_speed = max_speed;
    while((-1.0 * 0.5 *(st_left_enc_data.travel_dist + st_right_enc_data.travel_dist))
            < ref_dist_inc);

    // This is when the speed is consistant
    accel = 0.0;
    while((-1.0 * 0.5 * (st_left_enc_data.travel_dist + st_right_enc_data.travel_dist))
            < (length - ref_dist_dec));
    
    // This is when the speed is decreasing
    goal_speed = min_speed;
    accel = (-1.0) * max_acc;
    while((-1.0 * 0.5 * (st_left_enc_data.travel_dist + st_right_enc_data.travel_dist))
            < length);
}