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
*   PB4 - RGB Yellow LED
*/

// RED 0x02 0000 0010
// GREEN 0x04 0000 0100
// BLUE 0x08 0000 1000
// YELLOW 0x10 0001 0000

#define WHITE 0x01
#define RED 0x02
#define GREEN 0x04
#define BLUE 0x08
#define YELLOW 0x10

#include "Lighting_System.h"
#include "SysTick_Delay.h"

void Lighting_Off(void)
{
  GPIOB -> DATA &= ~0x1F;
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

void Lighting_Countdown(void)
{
  for (int i = 0; i < 3; i++)
    {
      GPIOB -> DATA |= YELLOW;
      SysTick_Delay1ms(600); // Yellow LED on

      GPIOB -> DATA &= ~YELLOW; // Yellow LED off
      SysTick_Delay1ms(400);
}
		}
  
