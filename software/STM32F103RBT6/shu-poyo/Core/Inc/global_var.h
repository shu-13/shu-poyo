// Global values for shu-poyo
#ifndef __GLOBAL_VAR_H
#define __GLOBAL_VAR_H

#include <stdio.h>

/* Sensor values */
typedef enum{
    DIST_SEN_R = 0,
    DIST_SEN_L,
    DIST_SEN_FR,
    DIST_SEN_FL,
    DIST_SEN_NUM,
}enDIST_SEN_ID;

/* Direction */
typedef enum{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
    MAP_HEAD_DIR_MAX,
}enMAP_HEAD_DIR;

#endif /* __GLOBAL__VAR_H */