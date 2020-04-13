//===========================================================//
// Projet Micro - INFO1 - ENSSAT - S2 2018							 //
//===========================================================//
// File                : Programme final : bon � rendre
// Hardware Environment: Open1768	
// Build Environment   : Keil �Vision
//===========================================================//

/**
 * @file main.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Le jeu de tennis de table des années 70. 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_libcfg_default.h"
#include "lpc17xx_timer.h"
#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"
#include "affichagelcd.h"
#include "touch\touch_panel.h"
#include "blt.h"
#include "lpc17xx_i2c.h"
#include "globaldec.h" // fichier contenant toutes les d�clarations de variables globales
#include "constantes.h"
#include "i2c.h" 
#include "gameinit.h"
#include "display.h"
#include "game.h"
#include "timer.h"
#include "sounds.h"
#include <stdio.h>
#include <stdbool.h>

//===========================================================//
// Function: Main
//===========================================================//
int main(void){	  
		
		//vitesse du jeu  /*EXPERIMENTAL*/
		int speed_mult = 1;
		
	
//================INITIALISATIONS================//
	
		init_blt();									//communications bluetooth
		lcd_Initializtion();					//affichage LCD (bas niveau)
		init_display();							//initialise l'affichage (haut niveau)
		gameinit();									//initialise les instances du jeu
		init_timer();								//pr�pare les timers 
		init_sound();								//pr�pare le pinsel vers le haut parleur
		touch_init();								//interactions tactiles
		mem_init();									//initialise la m�moire
	
//================FIN INITIALISATIONS================//
	
	
	
//================TEST MEMOIRE================//
	
		store_data((uint8_t *)P1WIN, LEN_P1WIN, AD_P1WIN);
		store_data((uint8_t *)P2WIN, LEN_P2WIN, AD_P2WIN);
		//on n'est pas oblig� de r��crire ceci syst�matiquement, c'est juste un test
		
//================FIN TEST MEMOIRE==============//	

		


	while (GAME == true){
		who_won_last_time();
		
		//==============================REPLAY LOOP============================//
		if (REPLAY == true){
			
			while(1){
				
				if (!PLAY_START) menu();
				if (PLAY_START == true){
					
					//====================JEU==================//	
					
					pause();
					if (PAUSE == false){
						dir_ball(&BALL0, PLAYER_1, PLAYER_2, speed_mult);
						move_ball(&BALL0);
						move_ai(&PLAYER_2, BALL0);
						
						if (DEMO){ 
							move_ai(&PLAYER_1, BALL0);
						} else {
							
							if (PLAYER_INPUT == true) {
								move_player1(&PLAYER_1, RXBUFFER);
								RXBUFFER[0]=NULL;
								PLAYER_INPUT = false;				
							}
							
						}
						
						refresh_display(PLAYER_1, PLAYER_2, COUNTER, BALL0);
						
					} else {
						pause();
						save_state();
						menu();
					}
					count_points(&COUNTER);
					
					if (FIN == true) {
						dessiner_rect(0,0,240,320,0,1,Black,Black);
						endscreen();
						FIN = false;
						PLAY_START = false;
						reset_counter();
						break;
					}
					//====================JEU================//
				}
				
			}
		}
		//==============================REPLAY LOOP============================//
		
	replay();
	save_who_wins();
	}

}
//fini



//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif

