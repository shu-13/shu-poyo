// Battery ADC for shu-poyo
#ifndef __ADC_BATT_H
#define __ADC_BATT_H

#include <stdio.h>

uint16_t BATT_LEVEL;
void check_batt(void);
void get_batt_level(void);

#endif /* __ADC_BATT_H */