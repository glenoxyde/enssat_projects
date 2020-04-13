/**
 * @file i2c.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Configurations et procédures de communication avec la mémoire/utilisant la mémoire 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include <stdio.h>
#include "lpc17xx_pinsel.h"
#include "lpc17xx_libcfg_default.h"
#include "LPC17xx.h"
#include "lpc17xx_i2c.h"
#include "i2c.h"
#include "globaldec.h"
#include "constantes.h"
#define MEM_ADDR (0xA0 >> 1)
#define WSIZE 2 //adresse + 1 data

void mem_init(void){

	PINSEL_CFG_Type PINSEL1_MEM_I2C;
	PINSEL_CFG_Type PINSEL2_MEM_I2C;
		
	PINSEL1_MEM_I2C.Portnum = PINSEL_PORT_0;
	PINSEL1_MEM_I2C.Pinnum = PINSEL_PIN_27;
	PINSEL1_MEM_I2C.Funcnum = PINSEL_FUNC_1;
	PINSEL1_MEM_I2C.OpenDrain = 0;
	PINSEL2_MEM_I2C.Portnum = PINSEL_PORT_0;
	PINSEL2_MEM_I2C.Pinnum = PINSEL_PIN_28;
	PINSEL2_MEM_I2C.Funcnum = PINSEL_FUNC_1;
	PINSEL2_MEM_I2C.OpenDrain = 0;
	
	PINSEL_ConfigPin(&PINSEL1_MEM_I2C);
	PINSEL_ConfigPin(&PINSEL2_MEM_I2C);
	
	I2C_Init(LPC_I2C0, 100000);
	I2C_Cmd(LPC_I2C0, ENABLE);
}


void store_word(uint8_t word, uint16_t address){
	
	I2C_M_SETUP_Type data_tx_cfg;
	
	uint8_t page = ((address & 0x700)>>8); //masque de recuperation de la page (adresse haute)
	uint8_t w_address = address & 0xff; //masque de recuperation de l'adresse basse
	
	uint8_t SL_ADDR = MEM_ADDR | page; //on cree le premier octet envoye (adresse haute)
	
	uint8_t NewData[WSIZE]; 
	NewData[0] = w_address; //l'adresse basse est stockee dansles donnees a transmettre
	NewData[1] = word;

	data_tx_cfg.sl_addr7bit = SL_ADDR; //adresse "physique" + adresse haute (page)
	data_tx_cfg.tx_data = NewData; 
	data_tx_cfg.tx_length = WSIZE; //adresse basse + data

	//on utilise pas la r�ception
	data_tx_cfg.rx_data = NULL; 
	data_tx_cfg.rx_length = 0; 
	data_tx_cfg.retransmissions_max = 0;
	
	I2C_MasterTransferData(LPC_I2C0, &data_tx_cfg, I2C_TRANSFER_POLLING);

}


void store_data(uint8_t * data, uint8_t data_len, uint8_t address){
	
	int k;
	for (k=0 ; k<data_len; ++k){
		store_word(data[k], address);
		address++;
	}
}




void fetch_data(uint8_t * data, uint8_t len, uint16_t address){


	I2C_M_SETUP_Type data_rx_cfg;
	uint8_t pointeur[1];
	uint8_t page = ((address & 0x700)>>8); //masque de recuperation de la page (adresse haute)
	uint8_t w_address = address & 0xff; //masque de recuperation de l'adresse basse
	
	uint8_t SL_ADDR = MEM_ADDR | page;
	pointeur[0]=w_address;	
	
	data_rx_cfg.sl_addr7bit = SL_ADDR;
	data_rx_cfg.tx_data = pointeur; 
	data_rx_cfg.tx_length = 1; 
	
	data_rx_cfg.rx_data = data; 
	data_rx_cfg.rx_length = len; 
	data_rx_cfg.retransmissions_max = 0;
	
	I2C_MasterTransferData(LPC_I2C0, &data_rx_cfg, I2C_TRANSFER_POLLING);
}



void save_who_wins(void){

	mem_init();
	if (LOST1 == true)store_word(2, SAVE_WIN);
	if (LOST2 == true)store_word(1, SAVE_WIN);
	
	LOST1 = false;
	LOST2 = false;

}


void who_won_last_time(void){
	uint8_t T[1];
	mem_init();
	fetch_data(T, 1, SAVE_WIN);
	BALL0.dir_x = 0;
	if (T[0] == 1){
		BALL0.dir_y = -1;
	} else {
		if (T[0] == 2){
			BALL0.dir_y = 1;
		} else {
			BALL0.dir_x = 1;
			BALL0.dir_y = 1;
		}
	}
}

void wipe_save(void){
	uint8_t k;
	mem_init();
	for (k=0 ; k<SAVE_P_LEN ; k++){
		store_word(NULL, SAVE_P_ADD + k);
	}
}

void resume(void){
	
	uint8_t SAVED_DATA[SAVE_P_LEN];
	mem_init();
	
	fetch_data(SAVED_DATA, SAVE_P_LEN, SAVE_P_ADD);
	//gameinit();
	PLAYER_1.x = SAVED_DATA[0];
	PLAYER_2.x = SAVED_DATA[1];
	BALL0.dir_x = SAVED_DATA[2];
	BALL0.dir_y = SAVED_DATA[3];
	BALL0.grph.x = SAVED_DATA[4];
	BALL0.grph.y = SAVED_DATA[5];
	COUNTER.L1.plein = SAVED_DATA[6];
	COUNTER.L2.plein = SAVED_DATA[7];
	COUNTER.L3.plein = SAVED_DATA[8];
	COUNTER.R1.plein = SAVED_DATA[9];
	COUNTER.R2.plein = SAVED_DATA[10];
	COUNTER.R3.plein = SAVED_DATA[11]; 

}

void save_state(void){
	uint8_t save[SAVE_P_LEN];
	mem_init();
	save[0] = PLAYER_1.x;	
	save[1] = PLAYER_2.x;
	save[2] = BALL0.dir_x;
	save[3] = BALL0.dir_y;
	save[4] = BALL0.grph.x; 
	save[5] = BALL0.grph.y;
	save[6] = COUNTER.L1.plein; 
	save[7] = COUNTER.L2.plein; 
	save[8] = COUNTER.L3.plein; 
	save[9] = COUNTER.R1.plein; 
	save[10] = COUNTER.R2.plein; 
	save[11] = COUNTER.R3.plein;
	//saving game
	store_data(save, SAVE_P_LEN, SAVE_P_ADD);	
}

