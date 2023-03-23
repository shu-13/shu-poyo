// Dynamic parameters for shu-poyo
#ifndef __PARAMETERS_H

#include "static_parameters.h"

// Switch related
#define CHATTERING_WAIT (50)    // in ms

// wheel params
#define WHEEL_DIAMETER      (43.15)    // in mm
// #define WHEEL_DIAMETER      (27.15)    // in mm
#define WHEEL_RADIUS        (WHEEL_DIAMETER * 0.5) // in mm
#define TREAD_WIDTH         (80.0)    // in mm


// Run parameters
#define SEARCH_SPEED (50)  // [mm/s]
#define SEARCH_ACCEL (1000) // [mm/s/s]

#define ROT_SPEED (30)  // [mm/s]
#define ROT_ACCEL (1000) // [mm/s/s]

// PID control things
#define K_P     (0.15)
#define K_I     (0.001)
#define K_D     (0.0)
#define FF_GAIN (0.0)

// sensor ref values
// These are mostly for control
#define SEN_TH_R   (550)       // For the front wall, when the mouse is at the edge of the section
#define SEN_TH_FR  (250)       // For the right side, when the mouse is in the left corner
#define SEN_TH_FL  (250)       // For the left side, when the mouse is in the right corner
#define SEN_TH_L   (550)       // For the front wall, when the mouse is at the edge of the section

#define SEN_REF_R  (200)        // For the front wall, when the mouse is at the center of the section
#define SEN_REF_L  (200)        // For the front wall, when the mouse is at the center of the section

#define __PARAMETERS_H

#endif /*_PARAMETERS_H*/