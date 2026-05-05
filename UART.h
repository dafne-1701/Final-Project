/**
* @file UART.h
* 
* @brief Header file for UART driver.
*
*/

#include "TM4C123GH6PM.h"

#define FIFO_Receive_Empty_1
#define FIFO_Transmit_Full_1

#define FIFO_Receive_Empty_2
#define FIFO_Transmit_Full_2

/**
 * @brief This function initializes UART0 to configure a serial connection with 
 *				the Raspberry Pi.
 * @param None.
 * @return None.
 */
void UART0_Init(void);

/**
 * @brief This function initializes UART3 to configure a serial connection with 
 *				the thermal printer.
 * @param None.
 * @return None.
 */
void UART3_Init(void);

/**
 * @brief This function transmits data using polling.
 * @param uint8_t data.
 * @return None.
 */
void UART_Send_Data(uint8_t data);

/**
 * @brief This function receives data.
 * @param None.
 * @return char.
 */
char UART_Receive_Data(void);

/**
 * @brief This function transmits data to the printer using an array depending on the 
 *				number of pictures taken per photo strip. Based on the number of  
 * @param char *string.
 * @return None.
 */
void UART3_Print(char pictures[]);