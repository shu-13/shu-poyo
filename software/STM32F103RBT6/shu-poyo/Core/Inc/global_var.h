// Global values for shu-poyo
#ifndef __GLOBAL_VAR_H
#define __GLOBAL_VAR_H

#include "typedef.h"
#include <stdio.h>

/* Sensor values */
enum enDIST_SEN_ID{
    DIST_SEN_R = 0,
    DIST_SEN_L,
    DIST_SEN_FR,
    DIST_SEN_FL,
    DIST_SEN_NUM,
};
stDIST_SEN st_sen[DIST_SEN_NUM];

/* Battery value */
uint16_t batt_val;

/* Direction */
enum enMAP_HEAD_DIR{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
    MAP_HEAD_DIR_MAX,
};

/* Speed and accelerations */
double duty_rate;   // in %
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