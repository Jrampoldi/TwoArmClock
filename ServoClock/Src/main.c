#include "stm32f411xe.h"
#include "tim_driver.h"
#include "pwm_handler.h"
#include "coordinate_handler.h"
#include "UART_handler.h"
#include "time_handler.h"
#include "plot_values.h"


/* Function Declarations */
void SystemInit(void);
void tim3_callback(void);
void tim4_callback(void);

/* Global variables */
volatile int seconds = 0;


int main(){
	/* Initialization functions */
	SystemInit();
	uart_tx_init();
	pwm_tim2_init();
	tim3_1hz_init();
	tim4_init();
	while(1){
	}

}

void tim3_callback(void){
    seconds++;
    if (seconds >= 60){
        //update clock
    	update_clock();
        seconds = 0;
    }
}

void tim4_callback(void){
	// update CCR values of servos
	update_servos();
}

void TIM3_IRQHandler(){
	//interrupt pending
	if (TIM3->SR & SR_UIF){
		// reset interrupt flag
		TIM3->SR &= ~(SR_UIF);
		tim3_callback();
	}
}

void TIM4_IRQHandler(){
	//interrupt pending
	if (TIM4->SR & SR_UIF){
		//reset interrupt flag
		TIM4->SR &= ~(SR_UIF);
		tim4_callback();
	}
}
void SystemInit(void)
{
	/* Set floating point coprosessor access mode. */
	SCB->CPACR |= ((3UL << 10*2) | /* set CP10 Full Access */
			(3UL << 11*2) ); /* set CP11 Full Access */
}
