/**
 * @file globaldec.h
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Declarations globales
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "lpc17xx_i2c.h"
#include "sprites.h"

#ifndef G_DEC_H
#define G_DEC_H

/**
* Pour la description des d�clarations globales, voir :
*				globaldec.C
*/ 


extern char chaine[30]; 
extern uint16_t touch_x, touch_y ;


extern bool PLAYER_INPUT; 
extern bool REPLAY; 
extern bool GAME; 
extern bool PLAY_START; 


extern bool SETTINGS;
extern bool SOUND;
extern bool DEMO;
extern bool PAUSE;


extern bool LOST1;
extern bool LOST2;
extern bool FIN;


extern uint8_t RXBUFFER[1]; 
extern uint8_t INPUT_BUF_LEN; 
extern uint8_t OUTPUT_BUF_LEN; 


extern SPRITE PLAYER_1;
extern SPRITE PLAYER_2;
extern BALL BALL0;
extern POINTS COUNTER;

#endif

