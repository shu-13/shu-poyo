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
void set_encoder(TIM_HandleTypeDef, uint16_t);

/* INIT FUNCTION */
void motor_encode_init(void){
    enc_speed = 0.0;

    st_left_enc_data.e_cur = 0.0;
    st_left_enc_data.e_prev = 0.0;
    st_left_enc_data.dist_buff = 0.0;
    st_left_enc_data.travel_dist = 0.0;
    st_right_enc_data.e_cur = 0.0;
    st_right_enc_data.e_prev = 0.0;
    st_right_enc_data.dist_buff = 0.0;
    st_right_enc_data.travel_dist = 0.0;

    clear_encoder(htim2); clear_encoder(htim3);
    set_encoder(htim2, 32767); set_encoder(htim3, 32767);
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
    if (duty_rate > 90.0){
        duty_rate = 90.0;
    }

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

void set_encoder(TIM_HandleTypeDef htim, uint16_t cnt){
    htim.Instance->CNT = cnt;
}

void get_encoder_val(void){
    // printf("Encoder Left raw (e_cur) : %5d \n\r", st_left_enc_data.e_cur);
    // printf("Encoder Right raw (e_cur) : %5d \n\r", st_right_enc_data.e_cur);
    printf("Encoder Left (travel_dist) : %4.2f \n\r", st_left_enc_data.travel_dist);
    printf("Encoder Right (travel_dist) : %4.2f \n\r", st_right_enc_data.travel_dist);
}

uint16_t read_left_encoder(void){
    uint16_t enc_buff = htim2.Instance->CNT;
    return enc_buff;
}

uint16_t read_right_encoder(void){
    uint16_t enc_buff = htim3.Instance->CNT;
    return enc_buff;
}

float calc_dist(uint16_t cur, uint16_t prev){
    // Calculates the distance in mm
    float dist = 0.0;
    float diff = 0.0;
    int16_t enc_diff = (int16_t)cur - (int16_t)prev;

    // Gets the number of rotation
    diff = (float)enc_diff / ((PULSES_PER_ROTATE * 2.0) - 1.0) ;

    // Calculates the distance
    dist = diff * GEAR_RATIO * WHEEL_DIAMETER * PI;
    return dist;
}

void encoder_update(void){
    // Updates the encoder structure value
    st_left_enc_data.e_cur = read_left_encoder();
    st_right_enc_data.e_cur = read_right_encoder();
    // Set the encoder value to half of 65535
    set_encoder(htim2, 32767); set_encoder(htim3, 32767);

    // Calculates the travelled distance in 1ms
    // The left encoder is faced the opposite from the right
    st_left_enc_data.dist_buff = (-1.0) * calc_dist(st_left_enc_data.e_cur, 32767);    
    st_right_enc_data.dist_buff = calc_dist(st_right_enc_data.e_cur, 32767);
    // Calculates the speed based off of the encoder value
    enc_speed = st_left_enc_data.dist_buff * 0.001; // in mm/s

    // Sums up the travelled distance
    st_left_enc_data.travel_dist += st_left_enc_data.dist_buff;
    st_right_enc_data.travel_dist += st_right_enc_data.dist_buff;

    // Saves the current data
    st_left_enc_data.e_prev = st_left_enc_data.e_cur;
    st_right_enc_data.e_prev = st_right_enc_data.e_cur;
}