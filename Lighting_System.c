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

// RED 0x02 0010
// GREEN 0x04 0100
// BLUE 0x08 1000
#include "Lighting_System.h"

static uint8_t current_mode = 0;

void Lighting_Off(void)
{
  GPIOB -> DATA &= ~0x0F;
}

void Lighting_Studio_Mode(void)
{
  Lighting_Off();
  GPIOB -> DATA |= WHITE;
}

void Lighting_Party_Mode(void)
{
  static uint8_t color = RED;
  Lighting_Off();
  GPIOB -> DATA |= color; // Starts at Red Color

  color *= 2; // goes from RED -> GREEN -> BLUE

  if (color > BLUE)
{
  color = RED;
 }
}
  
