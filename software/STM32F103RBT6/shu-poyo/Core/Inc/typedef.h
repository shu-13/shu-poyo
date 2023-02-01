// Type definitions for shu-poyo
#ifndef __TYPEDEF_H
#define __TYPEDEF_H

/* The structure for the sensor values */
typedef struct{
    uint16_t s_offset;      // The sensor value (LED OFF)
    uint16_t s_cur;         // The current sensor value (LED ON)
    uint16_t s_prev;        // The previous sensor value (LED ON)
    uint16_t s_limit;       // The sensors limit, AKA the value when its near the wall
    uint16_t s_ref;         // The sensors reference value
    uint16_t s_ctrl;        // Toggle for sensor control
    uint16_t s_noctrl;      // Toggle for non-sensor control
}stDIST_SEN;

/* The enum for the robot's direction */
typedef enum{
    FRONT=0,
    RIGHT,
    REAR,
    LEFT,
    UNKNOWN,
}enLOCAL_DIRECTION;

/* The structure for the robot's position 
// And it's facing direction */
typedef struct{
    short x;
    short y;
    enLOCAL_DIRECTION dir;
}stPOSITION;


#endif /* __TYPEDEF_H */