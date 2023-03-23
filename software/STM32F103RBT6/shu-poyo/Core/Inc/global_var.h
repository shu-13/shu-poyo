// Global values for shu-poyo
#ifndef __GLOBAL_VAR_H
#define __GLOBAL_VAR_H

#include "typedef.h"

/* Sensor values */
stDIST_SEN st_sen[DIST_SEN_NUM];

/* Battery value */
uint16_t batt_val;

/* Running stuff */
enRUN_MODE RUN_MODE;
enNEXT_DIRECTION NEXT_DIR;
stPOSITION ROBOT_POSITION;

/* Speed and accelerations */
float duty_rate;       // in %
float init_speed;       // the robot's speed when it starts to run in mm/s
float enc_speed;        // the robot's speed based on the encoder value
float prev_speed;       // the robot's previous speed (at -1ms)
float min_speed, max_speed; // min and max speed while running in mm/s
float goal_speed;       // the robot's target speed
float accel, r_accel;   // acceleration and rotation acceleration in mm/s/s
float err_speed;        // the diff of the goal speed and the enc_speed
float err_sum;          // the sum of the error
float v_PID;            // the PID value

#endif /* __GLOBAL__VAR_H */