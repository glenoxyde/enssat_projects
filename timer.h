/**
 * @file timer.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Interruptions des timers + initialisation des timers 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "globaldec.h"

/**
*@brief initialise les timers 1 et 2
*	le timer 1 donne la frequence de base du son a produire
*	le timer 2 donne la duree du son a produire.
* le timer 3 pourra etre utilise pour rythmer la musique 
* 
*/
void init_timer(void);
