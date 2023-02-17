// Adjust functions for shu-poyo
#include "run.h"
#include "sensors.h"
#include "parameters.h"
#include "global_var.h"

extern stDIST_SEN st_sen[DIST_SEN_NUM];

void run_to_wall(float max_acc, float init_sp, float max_sp){
    max_speed = max_sp;
    accel = max_acc;

    // Move half section
    straight(HALF_SECTION, accel, 0.0, max_speed, max_speed);

    while(1){
        get_sensor_values();
        // See if there's a front wall
        if((st_sen[DIST_SEN_L].s_cur < st_sen[DIST_SEN_L].s_ref)
            || (st_sen[DIST_SEN_R].s_cur < st_sen[DIST_SEN_R].s_ref)){
            // If there's no wall, move half section
            straight(SECTION_LEN, accel, max_speed, max_speed, max_speed);
        }else{
            // If there's a wall, move a little and stop
            straight(HALF_SECTION*0.6, accel, max_speed, max_speed, 0.0);
            break;
        }
        printf("\x1B[2J"); // Clears the terminal
        printf("\x1B[0;0H"); // Moves the cursor to the top
    }
}