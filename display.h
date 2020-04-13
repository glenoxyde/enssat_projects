/**
 * @file display.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Gestion affichage
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "sprites.h"

/**
*@brief initialise l'ecran au debut de la partie avec un simple ecran noir
*
*/
void init_display(void);




/**
*@brief met a jour l'affichage du jeu, (tous les elements susceptibles de changer d'etat) : 
* 
*@param[in] les structures des elements du jeu: les joueurs, le compteur de points et la balle
*/
void refresh_display(SPRITE player1, SPRITE player2, POINTS counter, BALL ball);

