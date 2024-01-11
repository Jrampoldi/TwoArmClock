/*
 * tim_handler.h
 *
 *  Created on: Jan 10, 2024
 *      Author: jourdanrampoldi
 */

#ifndef TIM_HANDLER_H_
#define TIM_HANDLER_H_

#include "stm32f411xe.h"

/* Update Interrupt Flag */
#define SR_UIF				(1U<<0)

void tim3_1hz_init(void);

#endif /* TIM_HANDLER_H_ */
