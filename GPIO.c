/**
* @file GPIO.c
* 
* @brief Source file for GPIO.
*/

// PORT B: For LED connections for our Studio/Party Modes
// PB0: Studio White Lights
// PB1: Party RED Light
// PB2: Party GREEN Light
// PB3: Party BLUE Light
// PB4: COUNTDOWN YELLOW Light
// PB4-0: 0x1F
// PORT E: For Button Handling
// PE2: Lighting Selection Button
// PE3: "Take Photo" Button

#define WHITE 0x01
#define RED 0x02
#define GREEN 0x04
#define BLUE 0x08
#define YELLOW 0x10

// PE3: Used for 
#include "GPIO.h"

// Initialization for Port B - LEDs
void GPIO_PortB_Init(void)
{
  SYSCTL -> RCGCGPIO |= 0x02; // Port B Clock Enabled
  GPIOB->DIR   |=  0x1F; // Output Pins
  GPIOB->AFSEL &= ~0x1F; // GPIO function
  GPIOB->AMSEL &= ~0x1F;
  GPIOB->DEN   |=  0x1F; // Digital enable
  GPIOB->DATA  &= ~0x1F; // Intially off

}

// Initialization of Port E (Buttons)
  void GPIO_PortE_Init(void)
{
  SYSCTL -> RCGCGPIO |= 0x10; // Port E Clock Enabled
  GPIOE -> DIR &= ~0x0C; // PE3:2 Input Buttons
  GPIOE -> AFSEL &= ~0x0C; // GPIO function
  GPIOE -> AMSEL &= ~0x0C; // Analog Func Disabled
  GPIOE -> DEN |= 0x0C; // Digital Enable Functionality
  GPIOE -> PUR |= 0x0C; // Pull-Up Resistors Enabled
}	