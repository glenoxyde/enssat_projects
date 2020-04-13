/**
 * @file constantes.h
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Constantes globales
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

//segment o� peut �voluer un joueur
//du fait de la taille de l'�cran vis � vis de celle des rectangles des joueurs
#define UP_PLAYER_LIM 180
#define DOWN_PLAYER_LIM 0


//rectagle o� peut �voluer la ball
#define UP_BALL_LIM 236
#define DOWN_BALL_LIM 0
#define RIGHT_BALL_LIM 312
#define LEFT_BALL_LIM 0

//adresses m�moires et longueurs des mots.
#define P1WIN "P1 WINS"
#define AD_P1WIN 1
#define LEN_P1WIN 8

#define P2WIN "P2 WINS"
#define AD_P2WIN 10
#define LEN_P2WIN 8

//adresse de sauvegrade de la derni�re victoire
#define SAVE_WIN 0

//adresse et taille de la sauvegrade de l'�tat du jeu
#define SAVE_P_LEN 12
#define SAVE_P_ADD 100

