// Run header for shu-poyo
#ifndef __RUN_H
#define __RUN_H

#include "stm32f1xx_hal.h"
#include "typedef.h"

// Init function
void speed_val_init(void);

// TEST functions
void test_run_forward(TIM_HandleTypeDef *htim);

// Run functions
void straight(float length, float max_acc, float init_sp, float max_sp, float tar_sp);
void back(float length, float max_acc, float init_sp, float max_sp, float tar_sp);
void turn(float length, float max_acc, float init_sp, float max_sp, float tar_sp);
void rotate(enNEXT_DIRECTION n_dir, int rot_num);

#endif /* __RUN_H */