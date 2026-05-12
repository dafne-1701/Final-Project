/**
* @file UART.c
* 
* @brief Source file for UART0 driver.
*				UART0 Pins to interface Raspberry Pi:
*					- PA0 -> U0RX 
*					- PA1 -> U0TX
*
*/

#include "UART.h"
#include "SysTick_Delay.h"

void UART0_Init(void)
{
	SYSCTL -> RCGCUART |= 0x01;					// Enables UART 0
	SYSCTL -> RCGCGPIO |= 0x01;					// Enables Port A 
	
	UART0 -> CTL &= ~0x0001;						// Clears the CTL register
	UART0 -> CC = 0x05; 								// Sets the Precision Internal Oscillator (PIOSC), making the clock source 16MHz
	
	GPIOA -> AFSEL |= 0x03;							// Enables alternate function for pins PA0 and PA1
	GPIOA -> PCTL &= ~0x000000FF;
	GPIOA -> PCTL |= 0x00000001;
	GPIOA -> PCTL |= 0x00000010;
	GPIOA -> DEN |= 0x03;
	UART0 -> IBRD = 8;									// BRD = UARTSysClk (= 16 MHz) / (16*115200)
	UART0 -> FBRD = 44;									// integer( BRDF (= 0.680556) * 64 + 0.5)
	UART0 -> LCRH |= 0x70;
	UART0 -> CTL = 0x301;								// Enables UART0 and RX and TX 
	
}

char UART0_Input_Char(void)
{ 
	while((UART0 -> FR & FIFO_Receive_Empty) != 0);
	return (char)(UART0 -> DR & 0xFF);
}

void UART0_Output_Char(char data)
{
	while((UART0 -> FR & FIFO_Transmit_Full) != 0);
	UART0 -> DR = data;
	
}

void UART0_Input_String(char *data_pointer, uint8_t  data_size)
{
	int size = 0;
	char character = UART0_Input_Char();
	while(character != UART_Carriage_Return)
	{
		if(character == UART_Backspace)
		{
			if(size)
			{
				data_pointer--;
				size--;
				UART0_Output_Char(UART_Backspace);
			}
		}
		else if(size < data_size-1)
		{
		  *data_pointer = character;
			data_pointer++;
			size++;
			UART0_Output_Char(character);
		}
		character = UART0_Input_Char();
	}
	*data_pointer = 0;
}

void UART0_Output_String(const char *data_string)
{
	while(*data_string)
	{
		UART0_Output_Char(*data_string);
		data_string++;
		
		SysTick_Delay1ms(1);
	}
}