// Dynamic parameters for shu-poyo
#ifndef __PARAMETERS_H

#include "static_parameters.h"

// Switch related
#define CHATTERING_WAIT (50)    // in ms

// wheel params
#define WHEEL_DIAMETER      (26)    // in mm
#define WHEEL_RADIUS        (WHEEL_DIAMETER / 2.0) // in mm
#define TREAD_WIDTH         (77)    // in mm


// Run parameters
#define SEARCH_SPEED (100)  // This is pulse. MAX is 360
#define SEARCH_ACCEL (1.5)

// PID control things
#define K_P     (1.0)
#define K_I     (0.0)
#define K_D     (0.0)
#define FF_GAIN (0.0)

// sensor ref values
#define SEN_REF_R   (100)
#define SEN_REF_FR  (100)
#define SEN_REF_FL  (100)
#define SEN_REF_L   (100)

#define __PARAMETERS_H

#endif /*_PARAMETERS_H*/