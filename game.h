/**
 * @file game.h
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Procédures du jeu en lui même
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "sprites.h"
#include "stdint.h"
#include <stdbool.h>



/**
*@brief modifie les coordonnees de la balle selon la direction de son vecteur vitesse
*
*@param[in,out] un pointeur sur la structure BALL, la balle a faire bouger
*/ 
void move_ball(BALL *);




/**
*@brief permet de modifier les coordonnees du joueur 1
*
*@param[in] r_dir : le tableau de caracteres contenant la direction envoyee par bluetooth
*@param[in,out] un pointeur sur l'instance de la structure du joueur1 
*/
void move_player1(SPRITE * player1, uint8_t * r_dir);




/**
*@brief permet de modifier les coordonnees d'un joueur automatiquement en fonction de la position de la balle
*
*@param[in] la structure BALL qu'on veut suivre
*@param[in,out] un pointeur sur l'instance de la structure du joueur1 ou 2 à modifier
*/
void move_ai(SPRITE * ai, BALL ball);




/**
*@brief permet de modifier le vecteur vitesse le la balle selon son environnement
 met aussi les flags LOST1 et LOST2 a jour lorsqu'un des deux joueur perd. 
*
*@param[in] les structures donnant acces a la position des deux joueurs 
 et le multiplicateur de vitesse (ne fonctionne pas, doit rester a 1 pour le moment)
*@param[in,out] un pointeur sur la structure BALL dont on veut modifier le vecteur vitesse
*/
void dir_ball(BALL * ball, SPRITE player1, SPRITE player2, int speed);




/**
*@brief permet compter les points selon qui a gagne ou perdu le round, et de mettre a jour le flag FIN (fin de partie)
*
*@param[in,out] un pointeur sur la structure POINTS qu'on veut modifier 
*/
void count_points(POINTS *counter);




/**
*@brief a la fin de la partie, affiche (en envoie par bluetooth) le joueur gagnant, et efface la sauvegarde precedente
* 
*/
void endscreen(void);




/**
*@brief met le jeu en pause (mise a jour d'un flag), et affiche PAUSE sur l'ecran et le telephone
*
*/
void pause(void);




/**
*@brief menu principal du jeu : permet de : 
*		lancer le jeu
*		reprendre une partie precedente grace aux sauvegardes
*		modifier les reglages du jeu (son on/off, mode demo on/off)
*		 le tout est realise avec des flags
*		
* lorsque le jeu est en pause, le meme menu est appele, et permet en plus de quitter la partie 
*	pour revenir au menu principal
*/
void menu(void);




/**
*@brief lorsque la partie est fini (un joueur a gagne) permet de demander au joueur s'il veut rejouer
*	si oui, la sauvegarde est effacee de la memoire, et le jeu redemarre
*	si non, le jeu quitte definitivement
*/
void replay(void);



/**
*@brief remet le compteur de points a 0
*
*/
void reset_counter(void);





