// Type definitions for shu-poyo
#ifndef __TYPEDEF_H
#define __TYPEDEF_H

/* structure for the sensor values */
typedef struct{
    uint16_t s_offset;      // The sensor value (LED OFF)
    uint16_t s_cur;         // The current sensor value (LED ON)
    uint16_t s_prev;        // The previous sensor value (LED ON)
    uint16_t s_limit;       // The sensors limit, AKA the value when its near the wall
    uint16_t s_ref;         // The sensors reference value
    uint16_t s_th;          // The sensors threshold value
    uint16_t s_ctrl;        // Toggle for sensor control, Yes: 1, No: 0
    uint16_t s_wall;        // Toggle if there's a wall, Yes: 1, No: 0
}stDIST_SEN;

/* enum for each sensor id */
enum enDIST_SEN_ID{
    DIST_SEN_R = 0,
    DIST_SEN_L,
    DIST_SEN_FR,
    DIST_SEN_FL,
    DIST_SEN_NUM,
};

/* Structure for the encoder values */
typedef struct{
    uint16_t e_cur;         // The current encoder value
    uint16_t e_prev;        // The previous encoder value
    volatile float dist_buff;        // The distance travelled every 1ms in mm
    volatile float travel_dist;      // The distance travelled in mm
}stENCODER_DATA;

/* enum for the robot's run mode*/
typedef enum{
    MODE_FORWARD = 0,
    MODE_REAR,
    MODE_STOP,
    MODE_TURN,
    MODE_ROTATE,
}enRUN_MODE;

/* Structure for the robot's wall control */
typedef struct{
    int enable;         // 0 for disable, 1 for enable
    float control;      // Control amount
    float error;        // Deflecting amount
    float prev_error;   // Previous error
}stCON_WALL;

/* enum for the robot's next direction */
typedef enum{
    NEXT_FRONT = 0,
    NEXT_RIGHT,
    NEXT_REAR,
    NEXT_LEFT,
    NEXT_UNKNOWN,
}enNEXT_DIRECTION;

/* Direction */
typedef enum{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
    MAP_HEAD_DIR_MAX,
}enMAP_HEAD_DIR;

/* The structure for the robot's position 
// And it's facing direction */
typedef struct{
    short x;
    short y;
    enMAP_HEAD_DIR m_dir;  // The facing direction
}stPOSITION;


#endif /* __TYPEDEF_H */