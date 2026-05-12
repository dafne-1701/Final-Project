/**
* @file UART.h
* 
* @brief Header file for UART0 driver.
*				UART0 Pins to interface Raspberry Pi:
*					- PA0 -> U0RX 
*					- PA1 -> U0TX
*
*/

#include "TM4C123GH6PM.h"

#define FIFO_Receive_Empty 0x10
#define FIFO_Transmit_Full 0x20

/**
 * @brief The characters for backspace, new line,and carriage return were defined
 * 				based on their ASCII character code.
 */
#define UART_Backspace 0x08
#define UART_Carriage_Return 0x0D
#define UART_Line_Feed 0x0A

/**
 * @brief This function initializes UART0 to configure a serial communication with 
 *				the Raspberry Pi.
 * @param None.
 * @return None.
 */
void UART0_Init(void);

/**
 * @brief This function reads a character from the serial terminal and will return the character.
 * @param None.
 * @return char.
 */
char UART0_Input_Char(void);

/**
 * @brief This function outputs a character to the terminal using DR register.
 * @param char data.
 * @return char.
 */
void UART0_Output_Char(char data);

/**
 * @brief This function will read several characters.
 * @param char *data_pointer, uint8_t  data_size.
 * @return None.
 */
void UART0_Input_String(char *data_pointer, uint8_t  data_size);

/**
 * @brief This function will transmit characters from the string pointer.
 * @param char *data_string.
 * @return None.
 */
void UART0_Output_String(const char *data_string);
