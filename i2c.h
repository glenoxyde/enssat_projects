/**
 * @file i2c.h
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Configurations et procédures de communication avec la mémoire/utilisant la mémoire 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "lpc17xx_libcfg_default.h"

/**
*@brief configure le pinsel pour l'utilisation du module i2c
*
*/
void mem_init(void);




/**
*@brief permet de stocker un seul octet dans la m�moire
*
*@param[in] l'entier (mot) � stocker, et son adresse
*/
void store_word(uint8_t word, uint16_t address);




/**
*@brief simple r�p�tition de store_word pour chaque �l�ment d'un tableau
*
*@param[in] tableau contenant les donn�es � stocker, longueur du tableau, et adressse du stockage
*/
void store_data(uint8_t * data, uint8_t len, uint8_t address);




/**
*@brief permet de r�cup�rer un ou pluseurs mots dans un buffer
*
*@param[in] nombre de donn�es contingentes � r�cup�rer, et adresse des donn�es
*@param[out] tableau qui va contenir les donn�es lues dans la m�moire
*/
void fetch_data(uint8_t * data, uint8_t len, uint16_t address);




/**
*@brief sauvegarde dans la m�moire quel joueur a gagn� lors de la pr�c�dente partie
*
*/
void save_who_wins(void);




/**
*@brief restitue de la m�moire quel joueur a gagn� lors de la pr�c�dente partie
*
*/
void who_won_last_time(void);




/**
*@brief sauvegarde dans la m�moirel'�tat actuel du jeu :
*		position en X des joueurs
*		position en X Y de la balle
*		direction en X Y de la balle
*		�tat du compteur
*
*/
void save_state(void);




/**
*@brief restitue dans les structures ad�quates les donn�es sauvegard�es dans save_state
*
*/
void resume(void);




/**
*@brief efface (remplis de z�ros) l'espace m�morie utilis� pour sauvegarder l'�tat du jeu
*
*/
void wipe_save(void);

