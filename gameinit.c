/**
 * @file gameinit.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Initialisation des instances du jeu
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */



#ifndef INITGAME_H
#define INITGAME_H
#include "sprites.h"
#include "globaldec.h"
#include "gameinit.h"
#include "touch\ili_lcd_general.h"

#define LNG 60
#define LRG 3


void gameinit(void){

		//variables d�finisssant la position des joueurs
		int PLAYER_1_x = 90;
		int player2_x = 90;

		//affecte des valeurs � chacun des �l�ments joueurs ci-dessus
		PLAYER_1.x = PLAYER_1_x; 
		PLAYER_2.x = player2_x;
		PLAYER_1.y = 0;
		PLAYER_2.y = 316;
		PLAYER_1.lng = LNG;
		PLAYER_2.lng = LNG;
		PLAYER_1.lrg = LRG;
		PLAYER_2.lrg = LRG;
		PLAYER_1.e = 0;
		PLAYER_2.e = 0;
		PLAYER_1.plein = 1;
		PLAYER_2.plein = 1;
		PLAYER_1.e_color = White;
		PLAYER_2.e_color = White;
		PLAYER_1.bg_color = White;
		PLAYER_2.bg_color = White;
		

		//affecte des valeurs � l'�l�ment balle
		//�l�ments logiciels
		BALL0.dir_x = 0;
		BALL0.dir_y = 0;
		//�l�ments graphiques
		BALL0.grph.x = 115;
		BALL0.grph.y = 156;
		BALL0.grph.lng = 8;
		BALL0.grph.lrg = 8;
		BALL0.grph.e = 1;
		BALL0.grph.plein = 1;
		BALL0.grph.e_color = White;
		BALL0.grph.bg_color = White;
		
		COUNTER.L1.x = 225;
		COUNTER.L2.x = 225;
		COUNTER.L3.x = 225;
		COUNTER.R1.x = 225;
		COUNTER.R2.x = 225;
		COUNTER.R3.x = 225;
		
		COUNTER.L1.y = 145;
		COUNTER.L2.y = 131;
		COUNTER.L3.y = 117;
		COUNTER.R1.y = 168;
		COUNTER.R2.y = 182;
		COUNTER.R3.y = 196;
		
		COUNTER.L1.lng = 8;
		COUNTER.L2.lng = 8;
		COUNTER.L3.lng = 8;
		COUNTER.L1.lrg = 8;
		COUNTER.L2.lrg = 8;
		COUNTER.L3.lrg = 8;
		COUNTER.R1.lng = 8;
		COUNTER.R2.lng = 8;
		COUNTER.R3.lng = 8;
		COUNTER.R1.lrg = 8;
		COUNTER.R2.lrg = 8;
		COUNTER.R3.lrg = 8;

		COUNTER.L1.e = 1;
		COUNTER.L2.e = 1;
		COUNTER.L3.e = 1;
		COUNTER.R1.e = 1;
		COUNTER.R2.e = 1;
		COUNTER.R3.e = 1;
		
		COUNTER.L1.plein = 0;
		COUNTER.L2.plein = 0;
		COUNTER.L3.plein = 0;
		COUNTER.R1.plein = 0;
		COUNTER.R2.plein = 0;
		COUNTER.R3.plein = 0;

		COUNTER.L1.e_color = White;
		COUNTER.L2.e_color = White;
		COUNTER.L3.e_color = White;
		COUNTER.R1.e_color = White;
		COUNTER.R2.e_color = White;
		COUNTER.R3.e_color = White;
		
		COUNTER.L1.bg_color = White;
		COUNTER.L2.bg_color = White;
		COUNTER.L3.bg_color = White;
		COUNTER.R1.bg_color = White;
		COUNTER.R2.bg_color = White;
		COUNTER.R3.bg_color = White;
		
}

#endif

