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

//� appeler � la fin du while(1) du main

/**
*@brief initialise l'�cran au d�but de la partie avec un simple �cran noir
*
*/
void init_display(void);




/**
*@brief met � jour l'affichage du jeu, (tous les �l�ments susceptibles de changer d'�tat) : 
* 
*@param[in] les structures des �l�ments du jeu: les joueurs, le compteur de points et la balle
*/
void refresh_display(SPRITE player1, SPRITE player2, POINTS counter, BALL ball);

