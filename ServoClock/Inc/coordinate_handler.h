/*
 * coordinate_handler.h
 *
 *  Created on: Jan 8, 2024
 *      Author: jourdanrampoldi
 */

#ifndef COORDINATE_HANDLER_H_
#define COORDINATE_HANDLER_H_

/* include headers */
#include <stdlib.h>
#include <math.h>
#include "pwm_handler.h"

/* Function Declarations */
void move_arm(double x, double y);
// Description: takes in a coordinate value, converts coordinate 
// to degrees in radians, converts radians to degrees, then 
// sends a move_servo request with mapped values.

#endif /* COORDINATE_HANDLER_H_ */
