/*
 * tim_handler.c
 *
 *  Created on: Jan 10, 2024
 *      Author: jourdanrampoldi
 */
#include "tim_driver.h"

/*TIM DEFINITIONS*/
#define TIM3EN				(1U<<1)
#define TIM4EN				(1U<<2)
#define DIER_UIE			(1U<<0)
#define CR1_CEN				(1U<<0)

void tim3_1hz_init(void){
	/* Configure TIM3 interrupt at 1hz */

	/* Enable clock for timer 3 & DMA1*/
	RCC->APB1ENR |= TIM3EN;

	/*Timer configured to 1Hz*/
	TIM3->PSC = 1600 - 1;
	TIM3->ARR = 10000 - 1;
	TIM3->CNT = 0; //reset counter

	/* Enable interrupt */
	TIM3->DIER |= DIER_UIE;

	/* Enable in NVIC */
	NVIC_EnableIRQ(TIM3_IRQn);

	/* Start Clock */
	TIM3->CR1 |= CR1_CEN;
}

void tim4_init(void){

	/* Configure timer to interrupt every 10 ms */
	/* Enable Clock Access */
	RCC->APB1ENR |= TIM4EN;

	/* Timer configured to 2Hz */
	TIM4->PSC = 1600;
	TIM4->ARR = 5000;
	TIM4->CNT = 0;


	TIM4->CR1 |= CR1_CEN;
}
