/**
 * @file sounds.h
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Procédures générant du son + initialisation du HP 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "globaldec.h"
#include <stdbool.h>

/**
*@brief configure le pinsel(sortie) vers le haut parleur
*
*/
void init_sound(void);

/**
*@brief produit un son haut ou bas
*
*/
void bip_high(void);
void bip_low(void);

