/**
 * @file sprites.h
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Déclarations des structures de base du jeu. 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */


#ifndef SPRITES_H
#define SPRITES_H

//structures d�finissant les items du jeu.


/**
*@brief structure repr�sentant une instance du jeu
*		qu'il s'agisse d'un joueur, de la balle, ou d'un point de compteur
*		�labor� � partir des arguments de dessiner_rectangle
*/
struct sprite{
		unsigned int x;
		unsigned int y;
		unsigned int lng;
		unsigned int lrg;
		unsigned int e;
		unsigned short plein;
		unsigned short e_color;
		unsigned short bg_color;
	};

typedef struct sprite SPRITE;

	
	
	
/**
*@brief structure repr�sentant la balle du jeu
*		elle est constitu�e d'�l�ments graphiques (grph)
*		et d'�l�ments "logiciels" (dir_x/y) 
* On d�finit ainsi enti�rement la balle (toutes ses caract�ristiques)
*
*/
struct ball{
	int dir_x;
	int dir_y;
	SPRITE grph;//�l�ment graphique de l'�l�ment ball
};

typedef struct ball BALL;
	
	
	
	
/**
*@brief structure repr�sentant le compteur de points
*	elle est constitu�e de 6 sprites
*
*/
struct points{
	SPRITE L1;
	SPRITE L2;
	SPRITE L3;
	SPRITE R1;
	SPRITE R2;
	SPRITE R3;
} ;

typedef struct points POINTS;
	
#endif

