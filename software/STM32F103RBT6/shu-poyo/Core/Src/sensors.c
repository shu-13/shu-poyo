// Sensors function for shu-poyo

#include "sensors.h"
#include "parameters.h"
#include "global_var.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc1;
extern stDIST_SEN st_sen[DIST_SEN_NUM];

void get_sensor_values(void){
    printf("========== \n\r");
    printf("R: %4d \n\r", st_sen[DIST_SEN_R].s_cur);
    printf("FR: %4d \n\r", st_sen[DIST_SEN_FR].s_cur);
    printf("FL: %4d \n\r", st_sen[DIST_SEN_FL].s_cur);
    printf("L: %4d \n\r", st_sen[DIST_SEN_L].s_cur);
    printf("========== \n\r");
}

void sensors_init(void){
    // Turn off the sensor
    SENSOR_OUT_R_OFF;
    SENSOR_OUT_FR_OFF; 
    SENSOR_OUT_FL_OFF;
    SENSOR_OUT_L_OFF;

    st_sen[DIST_SEN_R].s_ref = SEN_REF_R;
    st_sen[DIST_SEN_L].s_ref = SEN_REF_L;

    st_sen[DIST_SEN_R].s_th = SEN_TH_R;
    st_sen[DIST_SEN_FR].s_th = SEN_TH_FR;
    st_sen[DIST_SEN_FL].s_th = SEN_TH_FL;
    st_sen[DIST_SEN_L].s_th = SEN_TH_L;

    st_sen[DIST_SEN_R].s_limit = SEN_MAX;
    st_sen[DIST_SEN_FR].s_limit = SEN_MAX;
    st_sen[DIST_SEN_FL].s_limit = SEN_MAX;
    st_sen[DIST_SEN_L].s_limit = SEN_MAX;

    // printf("Initiated sensor params... \n\r");
}

void sensor_controls_update(void){
    // Determines if there's a wall
    if(st_sen[DIST_SEN_R].s_cur > st_sen[DIST_SEN_R].s_th){
        st_sen[DIST_SEN_R].s_wall = 1;
    }else{
        st_sen[DIST_SEN_R].s_wall = 0;
    }
    if(st_sen[DIST_SEN_L].s_cur > st_sen[DIST_SEN_L].s_th){
        st_sen[DIST_SEN_L].s_wall = 1;
    }else{
        st_sen[DIST_SEN_L].s_wall = 0;
    }

    // Determines if the robot needs wall control
    if(st_sen[DIST_SEN_FR].s_cur > st_sen[DIST_SEN_FR].s_th){
        st_sen[DIST_SEN_FR].s_ctrl = 1;
    }else{
        st_sen[DIST_SEN_FR].s_ctrl = 0;
    }
    if(st_sen[DIST_SEN_FL].s_cur > st_sen[DIST_SEN_FL].s_th){
        st_sen[DIST_SEN_FL].s_ctrl = 1;
    }else{
        st_sen[DIST_SEN_FL].s_ctrl = 0;
    }
}

void read_sensor_R(void){

    st_sen[DIST_SEN_R].s_prev = st_sen[DIST_SEN_R].s_cur;

    // Read sensor value (LED OFF)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    st_sen[DIST_SEN_R].s_offset = HAL_ADC_GetValue(&hadc1);

    // Turn LED on and wait a little
    SENSOR_OUT_R_ON;
    for (int i=0; i<30; i++);

    // Read sensor value (LED ON)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    // Compare the two values and overwrite it into the structure
    st_sen[DIST_SEN_R].s_cur = HAL_ADC_GetValue(&hadc1) - st_sen[DIST_SEN_R].s_offset;

    SENSOR_OUT_R_OFF;
}

void read_sensor_L(void){

    st_sen[DIST_SEN_L].s_prev = st_sen[DIST_SEN_L].s_cur;

    // Read sensor value (LED OFF)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    st_sen[DIST_SEN_L].s_offset = HAL_ADC_GetValue(&hadc1);

    // Turn LED on and wait a little
    SENSOR_OUT_L_ON;
    for (int i=0; i<30; i++);

    // Read sensor value (LED ON)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    // Compare the two values and overwrite it into the structure
    st_sen[DIST_SEN_L].s_cur = HAL_ADC_GetValue(&hadc1) - st_sen[DIST_SEN_L].s_offset;

    SENSOR_OUT_L_OFF;
}

void read_sensor_FR(void){

    st_sen[DIST_SEN_FR].s_prev = st_sen[DIST_SEN_FR].s_cur;

    // Read sensor value (LED OFF)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    st_sen[DIST_SEN_FR].s_offset = HAL_ADC_GetValue(&hadc1);

    // Turn LED on and wait a little
    SENSOR_OUT_FR_ON;
    for (int i=0; i<30; i++);

    // Read sensor value (LED ON)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    // Compare the two values and overwrite it into the structure
    st_sen[DIST_SEN_FR].s_cur = HAL_ADC_GetValue(&hadc1) - st_sen[DIST_SEN_FR].s_offset;

    SENSOR_OUT_FR_OFF;
}

void read_sensor_FL(void){

    st_sen[DIST_SEN_FL].s_prev = st_sen[DIST_SEN_FL].s_cur;

    // Read sensor value (LED OFF)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    st_sen[DIST_SEN_FL].s_offset = HAL_ADC_GetValue(&hadc1);

    // Turn LED on and wait a little
    SENSOR_OUT_FL_ON;
    for (int i=0; i<30; i++);

    // Read sensor value (LED ON)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1);
    // Compare the two values and overwrite it into the structure
    st_sen[DIST_SEN_FL].s_cur = HAL_ADC_GetValue(&hadc1) - st_sen[DIST_SEN_FL].s_offset;

    SENSOR_OUT_FL_OFF;
}
