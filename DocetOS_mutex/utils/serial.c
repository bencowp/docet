#include "../serial.h"
#include "stm32f4xx.h"

/* This function initialises the USART2 transmitter at 38400 baud (if the clock settings
   for the device are unchanged).  This is connected to the FTDI adapter on the dev board. */
void serial_init(void) {
	// Enable GPIO port A for the serial TX and RX pins
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	// Enable USART2 Clock
  RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	// Set TX pin (GPIOA pin 2) to 'Alternate Function' (AF) and select USART2
	GPIOA->MODER &= ~GPIO_MODER_MODER2;
  GPIOA->MODER |=  GPIO_MODER_MODER2_1;
  GPIOA->AFR[0] |= (7 << (4*2));

	// Enable USART
	USART2->CR1 |= USART_CR1_UE;

	// Set baud rate: 38400 baud from 42MHz clock (see pages 755-764)
	USART2->BRR = 0x446;
	
	// Enable USART TX
  USART2->CR1 |= USART_CR1_TE;
}
