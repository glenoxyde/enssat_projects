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
*@brief permet de stocker un seul octet dans la memoire
*
*@param[in] l'entier (mot) a stocker, et son adresse
*/
void store_word(uint8_t word, uint16_t address);




/**
*@brief simple repetition de store_word pour chaque element d'un tableau
*
*@param[in] tableau contenant les donnees a stocker, longueur du tableau, et adressse du stockage
*/
void store_data(uint8_t * data, uint8_t len, uint8_t address);




/**
*@brief permet de recuperer un ou pluseurs mots dans un buffer
*
*@param[in] nombre de donnees contingentes a recuperer, et adresse des donnees
*@param[out] tableau qui va contenir les donnees lues dans la memoire
*/
void fetch_data(uint8_t * data, uint8_t len, uint16_t address);




/**
*@brief sauvegarde dans la memoire quel joueur a gagne lors de la precedente partie
*
*/
void save_who_wins(void);




/**
*@brief restitue de la memoire quel joueur a gagne lors de la precedente partie
*
*/
void who_won_last_time(void);




/**
*@brief sauvegarde dans la memoirel'etat actuel du jeu :
*		position en X des joueurs
*		position en X Y de la balle
*		direction en X Y de la balle
*		�tat du compteur
*
*/
void save_state(void);




/**
*@brief restitue dans les structures adequates les donnees sauvegardees dans save_state
*
*/
void resume(void);




/**
*@brief efface (remplis de zeros) l'espace memorie utilise pour sauvegarder l'etat du jeu
*
*/
void wipe_save(void);

