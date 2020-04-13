/**
 * @file globaldec.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Declarations globales (et affectations)
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "lpc17xx_i2c.h"
#include "sprites.h"
#include "globaldec.h"

char chaine[30]; // buffer pour l'affichage sur le LCD
uint16_t touch_x, touch_y ;

bool PLAYER_INPUT; //bool�en de d�tection d'input
bool REPLAY = true; //rejouer
bool GAME = true; //jeu allum� ou non
bool PLAY_START = false; //commencer � jouer


bool SETTINGS = false; //affichage des settings
bool SOUND = true; //true = allum�
bool DEMO = true; //true = jeu automatique
bool PAUSE = false; //pause du jeu


bool LOST1 = false; //true = joueur 1 a perdu
bool LOST2 = false; //idem joueur 2
bool FIN = false; //fin du round


uint8_t RXBUFFER[1]; //tableau contenant l'input du joueur par bluetooth 
uint8_t INPUT_BUF_LEN = 1; //longueur du buffer d'input
uint8_t OUTPUT_BUF_LEN =30; //longueur du buffer d'output


/**
* variables d'items accessibles par toutes les fonctions du jeu
* les types SPRITE BALL et POINTS sont d�clar�s dans sprite.h
*	il s'agit d'une instanciation des �l�ments du jeu
*/
SPRITE PLAYER_1;
SPRITE PLAYER_2;
BALL BALL0;
POINTS COUNTER;

