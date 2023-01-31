// Sensors function for shu-poyo

#include "sensors.h"
#include "parameters.h"
#include "global_var.h"

extern ADC_HandleTypeDef hadc1;

typedef struct{
    uint16_t s_offset;      // The sensor value (LED OFF)
    uint16_t s_cur;         // The current sensor value (LED ON)
    uint16_t s_prev;        // The previous sensor value (LED ON)
    uint16_t s_limit;       // The sensors limit, AKA the value when its near the wall
    uint16_t s_ref;         // The sensors reference value
    uint16_t s_ctrl;        // Toggle for sensor control
    uint16_t s_noctrl;      // Toggle for non-sensor control
}stDIST_SEN;

stDIST_SEN st_sen[DIST_SEN_NUM];

void get_sensor_values(void){
    printf("R: %4d \n\r", st_sen[DIST_SEN_R].s_cur);
    printf("FR: %4d \n\r", st_sen[DIST_SEN_FR].s_cur);
    printf("FL: %4d \n\r", st_sen[DIST_SEN_FL].s_cur);
    printf("L: %4d \n\r", st_sen[DIST_SEN_L].s_cur);
    printf("========== \n\r");
}

void sensors_init(void){
    st_sen[DIST_SEN_R].s_ref = SEN_REF_R;
    st_sen[DIST_SEN_FR].s_ref = SEN_REF_FR;
    st_sen[DIST_SEN_FL].s_ref = SEN_REF_FL;
    st_sen[DIST_SEN_L].s_ref = SEN_REF_L;
    
    printf("Initiated sensor params... \n\r");
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
