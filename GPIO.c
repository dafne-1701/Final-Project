/**
* @file GPIO.c
* 
* @brief Source file for GPIO.
*/

// PORT B: For LED connections for our Studio/Party Modes
// PB0: Studio White Lights
// PB1: Party RED Light
// PB2: Party GREEN Light
// PB3: Party BLUE light
// PB3-0: 0x0F


// PE3: Used for 
#include "GPIO.h"

// INITIALIZATION OF PORT B
void GPIO_PortB_Init(void)
{
  SYSCTL -> RCGCGPIO |= 0x02; // Port B clock on
  GPIOB->DIR   |=  0x0F; // Output Pins
  GPIOB->AFSEL &= ~0x0F; // GPIO function
  GPIOB->AMSEL &= ~0x0F;
  GPIOB->DEN   |=  0x0F; // Digital enable
  GPIOB->DATA  &= ~0x0F; // Intially off

}
