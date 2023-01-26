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

void sensors_init(void){
    // hoge
}

void read_sensor_R(void){

    st_sen[DIST_SEN_R].s_prev = st_sen[DIST_SEN_R].s_cur;

    // Read sensor value (LED OFF)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1000);
    st_sen[DIST_SEN_R].s_offset = HAL_ADC_GetValue(&hadc1);

    // Turn LED on and wait a little
    SENSOR_OUT_R_ON;
    for (int i=0; i<1000; i++);

    // Read sensor value (LED ON)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1000);
    // Compare the two values and overwrite it into the structure
    st_sen[DIST_SEN_R].s_cur = HAL_ADC_GetValue(&hadc1) - st_sen[DIST_SEN_R].s_offset;

    SENSOR_OUT_R_OFF;
}
