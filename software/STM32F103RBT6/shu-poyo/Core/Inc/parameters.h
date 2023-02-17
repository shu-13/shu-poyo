// Dynamic parameters for shu-poyo
#ifndef __PARAMETERS_H

#include "static_parameters.h"

// Switch related
#define CHATTERING_WAIT (50)    // in ms

// wheel params
#define WHEEL_DIAMETER      (28.0)    // in mm
#define WHEEL_RADIUS        (WHEEL_DIAMETER / 2.0) // in mm
#define TREAD_WIDTH         (80.0)    // in mm


// Run parameters
#define SEARCH_SPEED (200)  // [mm/s]
#define SEARCH_ACCEL (1000) // [mm/s/s]

// PID control things
#define K_P     (0.1)
#define K_I     (0.001)
#define K_D     (0.0)
#define FF_GAIN (0.0)

// sensor ref values
#define SEN_REF_R   (500)
#define SEN_REF_FR  (500)
#define SEN_REF_FL  (500)
#define SEN_REF_L   (500)

#define __PARAMETERS_H

#endif /*_PARAMETERS_H*/