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

#define LIGHT_BUTTON 0x04
#define PHOTO_BUTTON 0x08

int main(void)
{
  uint8_t mode = 0;

GPIO_PortB_Init();
GPIO_PortE_Init();
Lighting_Off();
SysTick_Delay_Init();

while(1)
{
  // LIGHTING MODES FOR LIGHT_BUTTON
  if ((GPIOE -> DATA & LIGHT_BUTTON) == 0) // Button is Pressed
{
  SysTick_Delay1ms(20);
while ((GPIOE -> DATA & LIGHT_BUTTON) == 0);

mode++; // Cycles forward to OFF, STUDIO, PARTY

if (mode > 2)
{
mode = 0;   // Default is set as Lighting OFF
}

if (mode == 0)
{
  Lighting_Off(); // 0 = LIGHTING OFF when not pressed
}
    else if (mode == 1)
    {
    Lighting_Studio_Mode(); // When Pressed, Studio Mode is turned on
  }
}

if (mode == 2)
{
  Lighting_Party_Mode();
  SysTick_Delay1ms(300);
    }
  }
  // PHOTO BUTTON TRIGGERING PHOTO
  // UART INSERTION HERE
  // FOR LIGHT SYNCING WITH PHOTO
  if ((GPIOE -> DATA & PHOTO_BUTTON) == 0)
  {
    SysTick_Delay1ms(20);
    while ((GPIOE->DATA & PHOTO_BUTTON) == 0);

    Lighting_Countdown(); // Countdown Sequence
    Lighting_Studio_Mode(); // Imitates a Flash
    SysTick_Delay1ms(1000);
    Lighting_Off();
}
