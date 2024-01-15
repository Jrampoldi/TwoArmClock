#include "UART_handler.h"

/* Frequency Definitions */
#define SYS_FREQ                16000000
#define APB2CLK                 SYS_FREQ
#define baud                    115200

/* GPIO Definitions */
#define GPIOAEN                 (1U<<0)
#define PIN9_MODE               (1U<<19) //af mode
#define AF07                    (0x7<<4) 

/* USART Definitions */
#define USART1EN                (1U<<4)
#define CR1_UE                  (1U<<13)
#define CR1_TE                  (1U<<3)
#define SR_TXE                  (1U<<7)


/* Function Declarations */
void uart_set_brr(uint32_t periphCLK, uint32_t baudrate);
// Description: calculates appropriate BRR register value
// using uartdiv / 16 << 4 | uartdiv % 16
void uart_write(int ch);
// Description: writes character data in DR
// once empty

/* Function Definitions */
void uart_tx_init(){
    /* Enable clocks */
    RCC->AHB1ENR |= GPIOAEN;
    RCC->APB2ENR |= USART1EN;

    /* Configure GPIOA Pin 9 */
    GPIOA->MODER |= PIN9_MODE;
    GPIOA->AFR[1] |= AF07;

    /* Configure USART */
    USART1->CR1 &= ~(CR1_UE); //disable uart
    USART1->CR1 |= CR1_TE;
    uart_set_brr(APB2CLK, baud); 
    USART1->CR1 |= CR1_UE;
}

int __io_putchar(int ch){
    /* Overwrite printf for debug */
    uart_write(ch); // send char through tx
    return ch;
}

void uart_set_brr(uint32_t periphCLK, uint32_t baudrate){
    uint16_t uartdiv = periphCLK / baudrate;
    USART1->BRR = (((uartdiv / 16) << 4) | (uartdiv % 16));
}

void uart_write(int ch){
    while(!(USART1->SR & SR_TXE));
    USART1->DR = (0xFF & ch);
}
