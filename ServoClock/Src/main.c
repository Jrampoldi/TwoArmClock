#include "stm32f411xe.h"
#include "pwm_handler.h"

int main(){

	pwm_tim2_init();
	while(1){
		TIM2->CCR2 = 100;
		TIM2->CCR3 = 100;
		TIM2->CCR4 = 100;
		for(int i = 0; i < 100000; i++);
		TIM2->CCR2 = 200;
		TIM2->CCR3 = 200;
		TIM2->CCR4 = 200;
		for(int i = 0; i < 100000; i++);
		TIM2->CCR2 = 150;
		TIM2->CCR3 = 150;
		TIM2->CCR4 = 150;
		for(int i = 0; i < 100000; i++);
	}
}
