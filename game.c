/**
 * @file game.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Procédures du jeu en lui même
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "sprites.h"

#include "affichagelcd.h"
#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"
#include "touch\touch_panel.h"
#include "lpc17xx_uart.h"
#include "stdint.h"
#include "constantes.h"
#include "globaldec.h"
#include "game.h"
#include "gameinit.h"
#include "i2c.h"
#include "sounds.h"
#include <stdbool.h>
#include <stdio.h>


void move_ball(BALL * ball){
	
	(*ball).grph.x += (*ball).dir_x;
	(*ball).grph.y += (*ball).dir_y;
	
}




void move_player1(SPRITE * player1, uint8_t * r_dir){

	if (r_dir[0]==97){
		if ((*player1).x < UP_PLAYER_LIM-1){
			(*player1).x+=10;
		}
	}
	if (r_dir[0]==100){
		if ((*player1).x > DOWN_PLAYER_LIM){
			(*player1).x-=10;
		}
	}
}




void move_ai(SPRITE * ai, BALL ball){
	int middle_ai = (*ai).x+30-10;
	int middle_ball= ball.grph.x+2;
	
	if (middle_ball> middle_ai){
		if ((*ai).x < UP_PLAYER_LIM-2){
			(*ai).x+=2;
		}
	} else {
			if(middle_ball< middle_ai)
				if ((*ai).x > DOWN_PLAYER_LIM){
					(*ai).x-=2;
		}
	}
}




void dir_ball(BALL * ball, SPRITE player1, SPRITE player2, int speed){
	
		if ((*ball).grph.x==DOWN_BALL_LIM){ //si la balla atteint une limite, elle change de direction
			(*ball).dir_x = 1*speed;
			if (SOUND) bip_low(); //selon le reglage du son, on emet les bips ou non
		}
		if ((*ball).grph.x==UP_BALL_LIM-5){
			(*ball).dir_x = -1*speed;
			if (SOUND) bip_low();
		}
		
		//implementation des interactions avec les joueurs
		//joueur1
		if ((*ball).grph.y==player1.y+5 && ((*ball).grph.x>=player1.x && (*ball).grph.x<=player1.x+30)){
			if ((*ball).dir_x>0){
				(*ball).dir_x=1*speed;
				(*ball).dir_y=1*speed;
				if (SOUND) bip_high();
			} else {
				(*ball).dir_x=-1*speed;
				(*ball).dir_y=1*speed;
				if (SOUND) bip_high();
			}
		}
		
		if ((*ball).grph.y==player1.y+5 && ((*ball).grph.x>=player1.x+31 && (*ball).grph.x<=player1.x+60)){
			if ((*ball).dir_x>0){
				(*ball).dir_x=-1*speed;
				(*ball).dir_y=1*speed;
				if (SOUND) bip_high();
			} else {
				(*ball).dir_x=1*speed;
				(*ball).dir_y=1*speed;
				if (SOUND) bip_high();
			}
		}	
		
		//joueur2 (IA) 
		if ((*ball).grph.y==player2.y-8 && ((*ball).grph.x>=player2.x && (*ball).grph.x<=player2.x+30)){
			if ((*ball).dir_x>0){
				(*ball).dir_x=1*speed;
				(*ball).dir_y=-1*speed;
				if (SOUND) bip_high();
			} else {
				(*ball).dir_x=-1*speed;
				(*ball).dir_y=-1*speed;
				if (SOUND) bip_high();
			}
		}
		
		if ((*ball).grph.y==player2.y-8 && ((*ball).grph.x>=player2.x+31 && (*ball).grph.x<=player2.x+60)){
			if ((*ball).dir_x<0){
				(*ball).dir_x=-1*speed;
				(*ball).dir_y=-1*speed;
				if (SOUND) bip_high();
			} else {
				(*ball).dir_x=1*speed;
				(*ball).dir_y=-1*speed;
				if (SOUND) bip_high();
			}
		}	
		
		//perdu !
		if ((*ball).grph.y==RIGHT_BALL_LIM){
			dessiner_rect((*ball).grph.x, (*ball).grph.y, (*ball).grph.lng, (*ball).grph.lrg, (*ball).grph.e,(*ball).grph.plein, Black, Black); 
			(*ball).grph.x = 115;
			(*ball).grph.y = 156;
			(*ball).dir_x = 0;
			(*ball).dir_y = -1;
			LOST2=true;
			
		}
		if ((*ball).grph.y==LEFT_BALL_LIM){
			dessiner_rect((*ball).grph.x, (*ball).grph.y, (*ball).grph.lng, (*ball).grph.lrg, (*ball).grph.e,(*ball).grph.plein, Black, Black); 
			(*ball).grph.x = 115;
			(*ball).grph.y = 156;
			(*ball).dir_x = 0;
			(*ball).dir_y = 1;
			LOST1=true;
			
		}
}




void count_points(POINTS *counter){
	
	if (LOST1 == true|| LOST2 == true){
		if (LOST1==true){
			if ((*counter).R1.plein==1 && (*counter).R2.plein==1 && (*counter).R3.plein==1){
				FIN=true;
			}
			if ((*counter).R1.plein==1 && (*counter).R2.plein==1 && (*counter).R3.plein==0){
				(*counter).R3.plein=1;
			}
			if ((*counter).R1.plein==1 && (*counter).R2.plein==0 && (*counter).R3.plein==0){
				(*counter).R2.plein=1;
			}
			if ((*counter).R1.plein==0 && (*counter).R2.plein==0 && (*counter).R3.plein==0){
				(*counter).R1.plein=1;
			}
		}
		if (LOST2==true){
			if ((*counter).L1.plein==1 && (*counter).L2.plein==1 && (*counter).L3.plein==1){
				FIN=true;
			}
			if ((*counter).L1.plein==1 && (*counter).L2.plein==1 && (*counter).L3.plein==0){
				(*counter).L3.plein=1;
			}
			if ((*counter).L1.plein==1 && (*counter).L2.plein==0 && (*counter).L3.plein==0){
				(*counter).L2.plein=1;
			}
			if ((*counter).L1.plein==0 && (*counter).L2.plein==0 && (*counter).L3.plein==0){
				(*counter).L1.plein=1;
			}
		}
		if (FIN == false){ //si c'est la fin du jeu, on a besoin de conserver les flags LOST pour une sauvegarde !
			LOST1 = false;
			LOST2 = false;
		}
	}
}




void endscreen(void){
	char perdu[30];
	mem_init();
	if(LOST1 == true){
		fetch_data((uint8_t*)perdu, LEN_P2WIN, AD_P2WIN);
		LCD_write_english_string (90,40,perdu,White,Black);
		UART_Send(LPC_UART0,(uint8_t*)perdu, OUTPUT_BUF_LEN, NONE_BLOCKING);
	}
	
	if (LOST2 == true){
		fetch_data((uint8_t*)perdu, LEN_P1WIN, AD_P1WIN);
		LCD_write_english_string (90,40,perdu,White,Black);
		UART_Send(LPC_UART0,(uint8_t*)perdu, OUTPUT_BUF_LEN, NONE_BLOCKING);
		}
	wipe_save();
}




void pause(void){
	char str[6];
	if (PAUSE == true && RXBUFFER[0] == ' '){
		PAUSE = false;
		dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
		RXBUFFER[0]=NULL;
	} else {
		if (PAUSE == false && RXBUFFER[0] == ' '){
			PAUSE = true;
			save_state();
			dessiner_rect(0,0,240,320,0,1,Black,Black);
			sprintf(str, "PAUSE");
			LCD_write_english_string (100,40,str,White,Black);
			UART_Send(LPC_UART0,(uint8_t*)str, OUTPUT_BUF_LEN, NONE_BLOCKING);
			RXBUFFER[0]=NULL;
			
		}
	}
}




void menu(void){
	
	/*
	*	Pour tout ce qui converne les menus, il aurait ete de bon gout de developper 
	*	une veritable interface : une nouvelle structure BOUTON faisant figurer des champs 
	*	texte, coordonnees etc ...
	*	Ici, j'ai tout fait e la main directement dans la procedure
	*/
	
	touch_y = 0;
	touch_x = 0;
	mem_init();
	
	if (SETTINGS == false){
		sprintf(chaine, "TOUCH HERE TO START");
		LCD_write_english_string (40,80,chaine,White,Black);
		sprintf(chaine, "Settings");
		LCD_write_english_string (92,180,chaine,White,Black);
			
		
		if (!PAUSE){
			sprintf(chaine, "Resume");
			LCD_write_english_string (101,130,chaine,White,Black);
		}		
		
		touch_read();
		if (touch_y < 1200 && touch_y > 1000) { //start game
			if (PAUSE){
				PAUSE = !PAUSE;
				dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
			} else {
					PLAY_START = true;
					wipe_save();
					gameinit();
					who_won_last_time();
					dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
			}
		}
		
		if (!PAUSE){
			if (touch_y < 1850 && touch_y > 1700) { //resume
				gameinit();
				resume();
				PLAY_START=true;
				dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
			}
		}
		if (touch_y < 2350 && touch_y > 2100) { //settings
			SETTINGS = true;
			dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
		}
		if (PAUSE){
			sprintf(chaine, "Quit");
			LCD_write_english_string (109,220,chaine,White,Black);
			if (touch_y < 2800 && touch_y > 2700){ //quit
				PLAY_START = false;
				PAUSE = false;	
				dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
				}
			}
	}
	
	if (SETTINGS == true){
			
			sprintf(chaine, "Back");
			LCD_write_english_string (110,220,chaine,White,Black);
			
			if (SOUND){
				sprintf(chaine, "Sound : On");
				LCD_write_english_string (70,80,chaine,White,Black);
			} else {
				sprintf(chaine, "Sound : Off");
				LCD_write_english_string (70,80,chaine,White,Black);
			}
			
			if (DEMO){
				sprintf(chaine, "Demo : On");
				LCD_write_english_string (70,140,chaine,White,Black);
			} else {
				sprintf(chaine, "Demo : Off");
				LCD_write_english_string (70,140,chaine,White,Black);
			}
			touch_read();
			if (touch_y < 1200 && touch_y > 1000){
				SOUND = !SOUND;
				dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
			}
			if (touch_y < 1800 && touch_y > 1700){
				DEMO = !DEMO;
				dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
			}
			if (touch_y < 2800 && touch_y > 2700){ //back
				SETTINGS = false;
				dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
			}
	}
}




void replay(void){
	REPLAY = false;
	sprintf(chaine, "Try again ?");
	LCD_write_english_string (80,85,chaine,White,Black);
	
	sprintf(chaine, "Yes");
	LCD_write_english_string (70,160,chaine,White,Black);
	
	dessiner_rect(58, 143, 50, 50, 1, 0, White, Black); //contour cosmetique
	sprintf(chaine, "No");
	LCD_write_english_string (160,160,chaine,White,Black);
	dessiner_rect(143, 143, 50, 50, 1, 0, White, Black); //contour cosmetique

	touch_y = 0;
	touch_x = 0;
	touch_read();
	if (touch_y < 2200 && touch_y > 1800 && touch_x < 1900 && touch_x > 1200){ //yes
		REPLAY = true;
		dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
	}
	
	if (touch_y < 2200 && touch_y > 1800 && touch_x < 3000 && touch_x > 2800){ //no
		GAME = false;
		dessiner_rect(0,0,240,320,0,1,Black,Black); //fond noir
		sprintf(chaine, "BYEBYE");
		LCD_write_english_string (80,85,chaine,White,Black);
	}
}




void reset_counter(void){
	COUNTER.L1.plein = 0;
	COUNTER.L2.plein = 0;
	COUNTER.L3.plein = 0;
	COUNTER.R1.plein = 0;
	COUNTER.R2.plein = 0;
	COUNTER.R3.plein = 0;
}
