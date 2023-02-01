// Type definitions for shu-poyo
#ifndef __TYPEDEF_H
#define __TYPEDEF_H

typedef struct{
    uint16_t s_offset;      // The sensor value (LED OFF)
    uint16_t s_cur;         // The current sensor value (LED ON)
    uint16_t s_prev;        // The previous sensor value (LED ON)
    uint16_t s_limit;       // The sensors limit, AKA the value when its near the wall
    uint16_t s_ref;         // The sensors reference value
    uint16_t s_ctrl;        // Toggle for sensor control
    uint16_t s_noctrl;      // Toggle for non-sensor control
}stDIST_SEN;


#endif /* __TYPEDEF_H */