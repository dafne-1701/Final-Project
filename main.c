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

#define LIGHT_BUTTON 0x04
#define PHOTO_BUTTON 0x08

int main(void)
{
  uint8_t mode = 0;

GPIO_PortB_Init();
GPIO_PortE_Init();
Lighting_Off();

while(1)
{
  // Lighting Button is pressed
  if ((GPIOE -> DATA & LIGHT_BUTTON) == 0)
{
  
