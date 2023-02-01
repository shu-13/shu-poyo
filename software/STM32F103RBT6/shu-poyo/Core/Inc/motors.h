// Motor functions for shu-poyo
#ifndef __MOTORS_H
#define __MOTORS_H

void stop_motors(void);
void start_motors(void);
void motor_control(void);
float calc_pulse(double duty);

#endif /* __MOTORS_H */