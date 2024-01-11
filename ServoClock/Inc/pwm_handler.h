/*
 * pwm_handler.h
 *
 *  Created on: Dec 25, 2023
 *      Author: jourdanrampoldi
 */

#ifndef PWM_HANDLER_H_
#define PWM_HANDLER_H_

#include "stm32f411xe.h"

/* Function Declarations*/
void pwm_tim2_init(void);
// Description: initializes tim2 to output a pwm signal to 
// channel 2, 3, & 4, which are configured to pins 
// 1, 2, & 3.

double map_to_servo(double min_range, double max_range, double value);
// Description: Takes min_range, max_range, and a value, then returns mapped value
// to relative servo range. Servo range definitions in pwm_handler.c.

#endif /* PWM_HANDLER_H_ */
