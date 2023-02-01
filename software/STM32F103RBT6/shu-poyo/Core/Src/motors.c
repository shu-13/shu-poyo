// Motor related funtions for shu-poyo

#include "main.h"
#include "parameters.h"
#include "global_var.h"

extern TIM_HandleTypeDef htim1;

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

// Calculates the pulse value
// from the duty ratio.
// The PWF frequency and prescalers are
// set beforehand.
float calc_pulse(double duty){
    duty_rate = duty;
    return (duty_rate * MOTOR_COUNTER_PERIOD) / 100.0;
}

void motor_control(void){

}