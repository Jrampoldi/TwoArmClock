/*
 * pmw_handler.c
 *
 *  Created on: Dec 25, 2023
 *      Author: jourdanrampoldi
 */
#include "pwm_handler.h"

//pins A1-A3 config to ch 2, 3, & 4

/*GPIO DEFINITIONS*/
#define GPIOAEN				(1U<<0)
#define MODER_PIN_1_AF			(1U<<3)
#define MODER_PIN_2_AF			(1U<<5)
#define MODER_PIN_3_AF			(1U<<7)
#define AFR_PIN_1			(1U<<4)
#define AFR_PIN_2			(1U<<8)
#define AFR_PIN_3			(1U<<12)
#define PIN1_HIGHSPEED			(1U<<3 | 1U<<2)
#define PIN2_HIGHSPEED			(1U<<5 | 1U<<4)
#define PIN3_HIGHSPEED			(1U<<7 | 1U<<6)

/*TIM2 DEFINITIONS*/
#define TIM2EN				(1U<<0)
#define CR1_CEN				(1U<<0)
#define CCER_CC2E			(1U<<4)
#define CCER_CC3E			(1U<<8)
#define CCER_CC4E			(1U<<12)
#define PSC_VALUE			(320 - 1)
#define ARR_VALUE			(1000 - 1)
#define CH2_PWM_MODE_ONE		(1U<<14 | 1U<<13)
#define CH3_PWM_MODE_ONE		(1U<<6 | 1U<<5)
#define CH4_PWM_MODE_ONE		(1U<<14 | 1U<<13)

/* Servo specific definitions */
#define MAX_SERVO_VALUE			100
#define MIN_SERVO_VALUE			50
#define MAX_DEGREE_RANGE		180
#define MIN_DEGREE_RANGE		0

void pwm_tim2_init(void){


	//configure gpioa pins 1, 2, 3
	RCC->AHB1ENR |= GPIOAEN;
	RCC->APB1ENR |= TIM2EN;

	/* CONFIG PORT A PINS 1-3*/
	GPIOA->MODER &= ~(0x000000FC);
	GPIOA->MODER |= (MODER_PIN_1_AF | MODER_PIN_2_AF | MODER_PIN_3_AF);
	GPIOA->MODER &= ~(0x0000FFF0);
	GPIOA->AFR[0] |= (AFR_PIN_3 | AFR_PIN_2 | AFR_PIN_1);
	GPIOA->OSPEEDR &= ~(PIN1_HIGHSPEED | PIN2_HIGHSPEED | PIN3_HIGHSPEED);
	GPIOA->OSPEEDR |= (PIN3_HIGHSPEED | PIN2_HIGHSPEED | PIN3_HIGHSPEED);


	// systemclock at 16MHz
	/* Set for 20 ms */
	TIM2->PSC = PSC_VALUE;
	TIM2->ARR = ARR_VALUE;
	TIM2->CNT = 0; // restart counter


	//enable pwm mode for ch 2, 3, & 4
	TIM2->CCMR1 |= CH2_PWM_MODE_ONE;
	TIM2->CCMR2 |= (CH3_PWM_MODE_ONE | CH4_PWM_MODE_ONE);

	// init duty cycle
	TIM2->CCR2 = 100;
	TIM2->CCR3 = 100;
	TIM2->CCR4 = 100;

	TIM2->CCER |= (CCER_CC4E | CCER_CC3E | CCER_CC2E); //enable capture/compare of tim2ch2
	TIM2->CR1 |= CR1_CEN;

}

double map_to_servo(double value){
	double slope = 1.0 * (MAX_SERVO_VALUE - MIN_SERVO_VALUE) / (MAX_DEGREE_RANGE - MIN_DEGREE_RANGE);
	return (double)(MIN_SERVO_VALUE + slope * (value - MIN_DEGREE_RANGE));

}
void move_servo(double base_degrees, double arm_degrees, double x_value){
	//write algo to change CCR values using 
	//the mapped values given and the x
	//value for left arm or right arm servo
}
