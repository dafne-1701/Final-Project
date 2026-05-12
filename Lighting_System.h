/**
* @file Lighting_System.h
* 
* @brief Header file for Lighting System driver
*/

#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include <stdint.h>

#define WHITE 0x01
#define RED 0x02
#define GREEN 0x04
#define BLUE 0x08
#define YELLOW 0x10

/**
* @brief Used to turn all the LEDs off before going into Party or Studio mode. 
**/
void Lighting_Off(void);

/**
* @brief Used to activate steady white LEDs for a more "Professional" / Calm Mode
**/
void Lighting_Studio_Mode(void);

/**
* @brief Used to activate a sequence of RED, GREEN, BLUE Leds for a "Fun" Mode
**/
void Lighting_Party_Mode(void);

/**
* @brief Used to sync with the Countdown on when the photo will be taken
**/
void Lighting_Countdown(void);
