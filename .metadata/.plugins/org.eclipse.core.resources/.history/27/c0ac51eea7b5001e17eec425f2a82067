/*
 * pwm_handler.h
 *
 *  Created on: Dec 25, 2023
 *      Author: jourdanrampoldi
 */

#ifndef PWM_HANDLER_H_
#define PWM_HANDLER_H_

#include "stm32f411xe.h"
#include "uart_handler.h"

/* Function Declarations*/
void pwm_tim2_init(void);
// Description: initializes tim2 to output a pwm signal to 
// channel 2, 3, & 4, which are configured to pins 
// 1, 2, & 3.

float map_to_servo(float value);
// Description: Takes a value then returns mapped value
// to relative servo range. Servo range definitions in pwm_handler.c.

void move_servo(float base_degrees, float arm_degrees, float x_value);
// Description: Takes mapped values for base_degrees and arm_degrees, along with 
// the x-value for deciding right-arm servo motor or left-arm servo  motor.
// Will change values of servo global variables accordingly.

void update_servos(void);
// Description: if the CCR values of any servos are different than 
// the current value, the values will be incremented closer to that
// value;
#endif /* PWM_HANDLER_H_ */
