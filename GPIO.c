/**
* @file GPIO.c
* 
* @brief Source file for GPIO.
*/

// PORT B: For LED connections for our Studio/Party Modes
// PB0: Studio White Lights
// PB1: Party RED Light
// PB2: Party YELLOW Light
// PB3: Party BLUE light
// PB4: Party GREEN light
// PB5-PB0: 0x1F

// PE3: Used for 
#include "GPIO.h"

// INITIALIZATION OF PORT B
void GPIO_PortB_Init(void)
{
  SYSCTL -> RCGCGPIO |= 0x02; // Port B clock on
  GPIOB->DIR   |=  0x1F; // Output Pins
  GPIOB->AFSEL &= ~0x1F; // GPIO function
  GPIOB->AMSEL &= ~0x1F;
  GPIOB->DEN   |=  0x1F; // Digital enable
  GPIOB->DATA  &= ~0x1F; // Intially off

}
