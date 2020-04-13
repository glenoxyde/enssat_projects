/**
 * @file display.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Gestion affichage
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "affichagelcd.h"
#include "display.h"
#include "sprites.h"
#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"


void init_display(void){
		dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
}


void refresh_display(SPRITE player1, SPRITE player2, POINTS counter, BALL ball){

		/*
		* ici un petit probleme : le rectangle des joueurs reste affiche lors du refresh
		* pour eviter cela, on affiche un rectangle noir par dessus a chaque refresh
		* peu elegant comme solution
		* meme probleme pour la balle
		*/
	
	dessiner_rect(0,0,240,player1.lrg,player1.e,1,Black,Black); //fond noir J1
	dessiner_rect(0,player2.y,240,player2.lrg,player2.e,1,Black,Black); //fond noir J2

	dessiner_ligne(0,160,240,1,'h',White); // ligne mediane

	
	//barre du joueur 1
	dessiner_rect(player1.x, player1.y, player1.lng, player1.lrg,
		player1.e, player1.plein, player1.e_color, player1.bg_color);
	
	//barre du joueur 2
	dessiner_rect(player2.x, player2.y, player2.lng, player2.lrg,
		player2.e, player2.plein, player2.e_color, player2.bg_color);


	// "ombre" de la balle, qui efface sa trace a chaque refresh(si on l'enleve la balle laisse une trainee blanche)
	dessiner_rect(ball.grph.x-ball.dir_x, ball.grph.y-ball.dir_y, ball.grph.lng, ball.grph.lrg,
		ball.grph.e, ball.grph.plein, Black, Black);

	//rectangle representant la balle
	dessiner_rect(ball.grph.x, ball.grph.y, ball.grph.lng, ball.grph.lrg,
		ball.grph.e, ball.grph.plein, ball.grph.e_color, ball.grph.bg_color);
	

	//rectangles representant le compteur de points
	dessiner_rect(counter.L1.x, counter.L1.y, counter.L1.lng, counter.L1.lrg, 
			counter.L1.e, counter.L1.plein, counter.L1.e_color, counter.L1.bg_color);
	
	dessiner_rect(counter.L2.x, counter.L2.y, counter.L2.lng, counter.L2.lrg,
			counter.L2.e, counter.L2.plein, counter.L2.e_color, counter.L2.bg_color);
	
	dessiner_rect(counter.L3.x, counter.L3.y, counter.L3.lng, counter.L3.lrg,
			counter.L3.e, counter.L3.plein, counter.L3.e_color, counter.L3.bg_color);
	
	dessiner_rect(counter.R1.x, counter.R1.y, counter.R1.lng, counter.R1.lrg,
			counter.R1.e, counter.R1.plein, counter.R1.e_color, counter.R1.bg_color);
			
	dessiner_rect(counter.R2.x, counter.R2.y, counter.R3.lng, counter.R2.lrg,
			counter.R2.e, counter.R2.plein, counter.R2.e_color, counter.R2.bg_color);
			
	dessiner_rect(counter.R3.x, counter.R3.y, counter.R2.lng, counter.R3.lrg,
			counter.R3.e, counter.R3.plein, counter.R3.e_color, counter.R3.bg_color);

}

