#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include <string.h>

void initLEDS();

int main(void)
{
	initUSART2(USART2_BAUDRATE_921600);
	enIrqUSART2();
	initADC1Temp();
	initADC3();
	initLEDS();

	printUSART2("**************************************************************\n");
	printUSART2("\n");
	printUSART2("				App start \n");
	printUSART2("\n");
	printUSART2("**************************************************************\n");

	while (1)
	{
		// printUSART2("Main in progress \n");
		//   data = getcharUSART2();
		//   printUSART2("Enter je unesen");
		//   putcharUSART2(data);
#ifndef USART_ECHO
		chkRxBuffUSART2();
#endif
	}
}

void initLEDS()
{
	// enable LEDS
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; //
	GPIOD->MODER |= 0x55000000;			 //
	GPIOD->OTYPER |= 0x00000000;		 //
	GPIOD->OSPEEDR |= 0xFF000000;		 //
	GPIOD->ODR = 0xf000;
}