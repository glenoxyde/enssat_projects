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

//structures definissant les items du jeu.


/**
*@brief structure representant une instance du jeu
*		qu'il s'agisse d'un joueur, de la balle, ou d'un point de compteur
*		elabore a partir des arguments de dessiner_rectangle
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
*@brief structure representant la balle du jeu
*		elle est constituee d'elements graphiques (grph)
*		et d'elements "logiciels" (dir_x/y) 
* On definit ainsi entierement la balle (toutes ses caracteristiques)
*
*/
struct ball{
	int dir_x;
	int dir_y;
	SPRITE grph; //element graphique de l'element ball
};

typedef struct ball BALL;
	
	
	
	
/**
*@brief structure representant le compteur de points
*	elle est constituee de 6 sprites
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

