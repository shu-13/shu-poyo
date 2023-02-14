// Motor related funtions for shu-poyo

#include "main.h"
#include "parameters.h"
#include "global_var.h"

// From the main.c
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

// Structures
stENCODER_DATA st_left_enc_data;
stENCODER_DATA st_right_enc_data;

// Proto types
void clear_encoder(TIM_HandleTypeDef);

/* INIT FUNCTION */
void motor_encode_init(void){
    duty_rate = 0.0;

    st_left_enc_data.e_cur = 0.0;
    st_left_enc_data.e_prev = 0.0;
    st_left_enc_data.dist_buff = 0.0;
    st_left_enc_data.travel_dist = 0.0;
    st_right_enc_data.e_cur = 0.0;
    st_right_enc_data.e_prev = 0.0;
    st_right_enc_data.dist_buff = 0.0;
    st_right_enc_data.travel_dist = 0.0;

    clear_encoder(htim2); clear_encoder(htim3);
}


/* MOTOR RELATED FUNCTIONS */
void stop_motors(void){
    // Stops PWM output
    HAL_TIM_PWM_Stop(&htim1, MOTORL_CH2);    
    HAL_TIM_PWM_Stop(&htim1, MOTORR_CH2);    
}

void start_motors(void){
    // Starts PWM output
    HAL_TIM_PWM_Start(&htim1, MOTORL_CH2);
    HAL_TIM_PWM_Start(&htim1, MOTORR_CH2);
}

float calc_pulse(double duty){
    // Calculates the pulse value from the duty ratio.
    // The PWF frequency and prescalers are set beforehand.
    duty_rate = duty;
    return (duty_rate * MOTOR_COUNTER_PERIOD) / 100.0;
}

void speed_update(void){
    // 1ms割り込みで実行
    // goal_speed is the target speed
    goal_speed += accel * 0.001; // Updates speed every 1ms
    
    // the difference between the goal and current speed
    err_speed = goal_speed - enc_speed;
    err_sum += err_speed;

    v_PID = err_speed*K_P + err_sum*K_I + (prev_speed - err_speed)*K_D; 
    
    // Update the prev_speed
    prev_speed = err_speed;

    duty_rate = FF_GAIN + v_PID;

    // if(RUN_MODE == straight){
        MOTORR_FORWARD; MOTORL_FORWARD;
        
        __HAL_TIM_SET_COMPARE(&htim1, MOTORL_CH2, MOTOR_COUNTER_PERIOD*duty_rate*0.01);
        __HAL_TIM_SET_COMPARE(&htim1, MOTORR_CH2, MOTOR_COUNTER_PERIOD*duty_rate*0.01);
    // }
} 

/* ENCODER RELATED FUNCTIONS */
void clear_encoder(TIM_HandleTypeDef htim){
    htim.Instance->CNT = 0;
}

uint16_t read_left_encoder(void){
    // Do you need to clear the count???
    uint16_t enc_buff = htim2.Instance->CNT;
    // htim2.Instance->CNT = 0;
    return enc_buff;
}

uint16_t read_right_encoder(void){
    // Do you need to clear the count???
    uint16_t enc_buff = htim3.Instance->CNT;
    // htim3.Instance->CNT = 0;
    return enc_buff;
}

float calc_dist(uint16_t cur, uint16_t prev){
    // Calculates the distance in mm
    float dist = 0.0;
    uint16_t diff = 0;
    
    // Gets the number of rotation
    diff = cur - prev;

    // Calculates the distance
    dist = diff * GEAR_RATIO * WHEEL_DIAMETER * PI;
    return dist;
}

void encoder_update(void){
    // Updates the encoder structure value
    st_left_enc_data.e_cur = read_left_encoder();
    st_right_enc_data.e_cur = read_right_encoder();

    // Calculates the travelled distance in 1ms
    st_left_enc_data.dist_buff = calc_dist(st_left_enc_data.e_cur, st_left_enc_data.e_prev);    
    st_right_enc_data.dist_buff = calc_dist(st_right_enc_data.e_cur, st_right_enc_data.e_prev);
    // Calculates the speed based off of the encoder value
    enc_speed = st_left_enc_data.dist_buff * 0.001; // in mm/s

    // Sums up the travelled distance
    st_left_enc_data.travel_dist += st_left_enc_data.dist_buff;
    st_right_enc_data.travel_dist += st_right_enc_data.dist_buff;

    // Saves the current data
    st_left_enc_data.e_prev = st_left_enc_data.e_cur;
    st_right_enc_data.e_prev = st_right_enc_data.e_cur;
}