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
float speed;    // the robot's speed in mm/s
float min_speed, max_speed; // min and max speed in mm/s
float accel, r_accel;   // acceleration and rotation acceleration in mm/s/s

#endif /* __GLOBAL__VAR_H */