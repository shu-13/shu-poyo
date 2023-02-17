// Motor functions for shu-poyo
#ifndef __MOTORS_H
#define __MOTORS_H

void motor_encode_init(void);

/* Motor controls */
void stop_motors(void);
void start_motors(void);
void speed_update(void);
float calc_pulse(double duty);

/* Encoder controls */
void clear_encoder(TIM_HandleTypeDef htim);
void set_encoder(TIM_HandleTypeDef htim, uint16_t cnt);
void get_encoder_val(void);
uint16_t read_left_encoder(void);
uint16_t read_right_encoder(void);
float calc_dist(uint16_t cur, uint16_t prev);
void encoder_update(void);


#endif /* __MOTORS_H */