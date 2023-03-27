// Adjust functions for shu-poyo
#include "run.h"
#include "sensors.h"
#include "parameters.h"
#include "global_var.h"

extern stDIST_SEN st_sen[DIST_SEN_NUM];

void run_to_wall(float max_acc, float init_sp, float max_sp){
    max_speed = max_sp;
    accel = max_acc;

    NEXT_DIR = NEXT_FRONT;
    // Move half of half section
    straight(HALF_SECTION*0.45, accel, 0.0, max_speed, max_speed);

    while(1){
        // See if there's a front wall
        if((st_sen[DIST_SEN_L].s_cur < st_sen[DIST_SEN_L].s_ref)
            || (st_sen[DIST_SEN_R].s_cur < st_sen[DIST_SEN_R].s_ref)){
            // If there's no wall, move half section
            straight(HALF_SECTION, accel, max_speed, max_speed, max_speed);
        }else{
            // If there's a wall, move a little and stop
            straight(HALF_SECTION*0.1, accel, max_speed, max_speed, 0.0);
            RUN_MODE = MODE_STOP;
            break;
        }
    }
}

void test_left_hand(float max_acc, float init_sp, float max_sp){
    max_speed = max_sp;
    accel = max_acc;

    // Move half of half section
    straight(HALF_SECTION*0.45, accel, 0.0, max_speed, max_speed);

    while(1){
        // See if there's a front wall
        if((st_sen[DIST_SEN_L].s_cur < st_sen[DIST_SEN_L].s_ref)
            || (st_sen[DIST_SEN_R].s_cur < st_sen[DIST_SEN_R].s_ref)){
            // If there's no wall, move half section
            straight(HALF_SECTION, accel, max_speed, max_speed, max_speed);
        }else{
            // If there's a wall in front, move a little and stop
            HAL_Delay(100);
            rotate(NEXT_RIGHT, 1);
            HAL_Delay(100);
        } 
    }

}