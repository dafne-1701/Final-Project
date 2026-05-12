/**
 * @file main.c
 *
 * @brief Main source code for Photo Booth Final Project
 *
 * This file contains the main functions and definitions 
 *
*/

#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "Lighting_System.h"
#include "Timing.h"
#include "SysTick_Delay.h"
#include "UART.h"

#define LIGHT_BUTTON 0x04
#define PHOTO_BUTTON 0x08

int main(void)
{
	uint8_t mode = 0;

  GPIO_PortB_Init();
  GPIO_PortE_Init();
  Lighting_Off();
  SysTick_Delay_Init();
	UART0_Init();
	

while(1)
{
  // LIGHTING BUTTON
  if ((GPIOE->DATA & LIGHT_BUTTON) == 0)
  {
    SysTick_Delay1ms(20);
    while ((GPIOE->DATA & LIGHT_BUTTON) == 0);

    mode++;

    if (mode > 2)
    {
      mode = 0;
    }

    if (mode == 0)
    {
      Lighting_Off();
    }
    else if (mode == 1)
    {
      Lighting_Studio_Mode();
    }
  }

  // PARTY MODE
  if (mode == 2)
  {
    Lighting_Party_Mode();
    SysTick_Delay1ms(200);
  }

  // PHOTO BUTTON
  if ((GPIOE->DATA & PHOTO_BUTTON) == 0)     // Checks for button status
  {
		GPIOB -> DATA |= YELLOW;
		
		UART0_Output_String("SNAP\n");
    SysTick_Delay1ms(250);
		
		GPIOB -> DATA &= ~YELLOW;
		
    while ((GPIOE->DATA & PHOTO_BUTTON) == 0);

		}
		else
		{
			Lighting_Countdown();
			Lighting_Studio_Mode();

      SysTick_Delay1ms(100);
		
    if (mode == 0)
    {
      Lighting_Off();
    }
    else if (mode == 1)
    {
      Lighting_Studio_Mode();
    }
    // if mode == 2, party continues automatically
	//}
		//}
				
	}		
  }
}