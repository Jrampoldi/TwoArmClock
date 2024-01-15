#include "stm32f411xe.h"
#include "pwm_handler.h"
#include "tim_handler.h"
#include "coordinate_handler.h"
#include "UART_handler.h"

/* Function Declarations */
void SystemInit(void);
void tim3_callback();

/* Global variables */
volatile int seconds = 0;

int main(){
	/* Initialization functions */
	SystemInit();
	uart_tx_init();
	pwm_tim2_init();
	tim3_1hz_init();

	while(1){
		move_arm(1.0, 1.0);
	}

}

void tim3_callback(){
}

void TIM3_IRQHandler(){
	//interrupt pending
	if (TIM3->SR & SR_UIF){
		// reset interrupt flag
		TIM3->SR &= ~(SR_UIF);
		tim3_callback();
	}
}

void SystemInit(void)
{
	/* Set floating point coprosessor access mode. */
	SCB->CPACR |= ((3UL << 10*2) | /* set CP10 Full Access */
			(3UL << 11*2) ); /* set CP11 Full Access */
}
