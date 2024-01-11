#include "stm32f411xe.h"
#include "pwm_handler.h"
#include "tim_handler.h"
#include "coordinate_handler.h"

/* Function Declarations */
void tim3_callback();

/* Global variables */
volatile int seconds = 0;

int main(){
	/* Initialization functions */
	pwm_tim2_init();
	tim3_1hz_init();

	while(1){
		
	}
}

void tim3_callback(){
	seconds++;
	if (seconds >= 60){
		seconds = 0;
		//define clock call
	}
}

void TIM3_IRQHandler(){
	//interrupt pending
	if (TIM3->SR & SR_UIF){
		// reset interrupt flag
		TIM3->SR &= ~(SR_UIF);
		tim3_callback();
	}
}
