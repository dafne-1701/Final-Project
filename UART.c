/**
* @file UART.c
* 
* @brief Source file for UART0 and UART1 driver.
*
*
*/

#include "UART.h"

void UART0_Init(void)
{
	SYSCTL -> RCGCUART |= 0x01;
	SYSCTL -> RCGCGPIO |= 0x01;
	GPIOA -> AFSEL |= 0x03;
	GPIOA -> PCTL &= ~0x00000FF;
	GPIOA -> PCTL |= 0x00000001;
	GPIOA -> PCTL |= 0x00000010;
	GPIOA -> DEN |= 0x03;
	UART0 -> CTL &= ~0x0001;
	UART0 -> CTL &= ~0020;
	UART0 -> IBRD = 8;							// BRD = UARTSysClk (= 16 MHz) / (16*115200)
	UART0 -> FBRD = 44;							// integer( BRDF (= 0.680556) * 64 + 0.5)
	UART0 -> LCRH |= 0x70;
	UART0 -> CTL |= 0x0001;
	
}

void UART3_Init(void)
{
	SYSCTL -> RCGCUART |= 0x08;
	SYSCTL -> RCGCGPIO |= 0x04;
	GPIOC -> AFSEL |= 0xC0;
	GPIOC -> PCTL &= ~0x00000FF;
	GPIOC -> PCTL |= 0x00000001;
	GPIOC -> PCTL |= 0x00000010;
	GPIOC -> DEN |= 0xC0;
	UART3 -> CTL &= ~0x0001;
	UART3 -> CTL &= ~0020;
	UART3 -> IBRD = 104;							// BRD = UARTSysClk (= 16 MHz) / (16*9600)
	UART3 -> FBRD = 11; 							// integer( BRDF (= 0.166667) * 64 + 0.5)
	UART3 -> LCRH |= 0x70;
	UART3 -> CTL |= 0x0001;
}

void UART_Send_Data(uint8_t data)
{
	
}

char UART_Receive_Data(void)
{
	
} 

void UART3_Print(char picture[])
{
	
}