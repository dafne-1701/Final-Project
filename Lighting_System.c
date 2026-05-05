/**
* @file Lighting_System.c
* 
* @brief Source file for Lighting System driver
*
* Pins Used for Lights:
*   PB0 - White LED lights
*   PB1 - RGB Red LED
*   PB2 = PGB Green LED
*   PB3 - RGB Blue LED
*/

#include "Lighting_System.h"

void Lighting_Studio_mode(void)
{
  // RGB turned off in case it is on beforehand
  GPIOB -> DATA &= ~0x0E;

  // Turn on White LED lights
  GPIOB -> DATA |= 0x01;
}
