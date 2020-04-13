/**
 * @file blt.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Gestion bluetooth
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include <stdio.h>
#include "lpc17xx_uart.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_libcfg_default.h"

#include "LPC17xx.h"
#include "blt.h"


#include "globaldec.h"

void init_blt(void){
		
		PINSEL_CFG_Type PINSEL_BLT_TX;
		PINSEL_CFG_Type PINSEL_BLT_RX;
		
		UART_CFG_Type UART_CFG;
		
		PINSEL_BLT_TX.Portnum = PINSEL_PORT_0;
		PINSEL_BLT_RX.Portnum = PINSEL_PORT_0;
		PINSEL_BLT_TX.Pinnum = PINSEL_PIN_2;
		PINSEL_BLT_RX.Pinnum = PINSEL_PIN_3;
		PINSEL_BLT_TX.Funcnum = PINSEL_FUNC_1;
		PINSEL_BLT_RX.Funcnum = PINSEL_FUNC_1;
		PINSEL_BLT_TX.Pinmode = PINSEL_PINMODE_NORMAL;
		PINSEL_BLT_RX.Pinmode = PINSEL_PINMODE_NORMAL;
			
		UART_CFG.Baud_rate = 38400;
		UART_CFG.Parity = UART_PARITY_NONE;
		UART_CFG.Databits = UART_DATABIT_8;
		UART_CFG.Stopbits = UART_STOPBIT_1;
		
		PINSEL_ConfigPin(&PINSEL_BLT_RX);
		PINSEL_ConfigPin(&PINSEL_BLT_TX);
		
		UART_Init(LPC_UART0, &UART_CFG);
		UART_TxCmd(LPC_UART0, ENABLE);
	
		NVIC_EnableIRQ(UART0_IRQn);
		UART_IntConfig(LPC_UART0, UART_INTCFG_RBR, ENABLE); 
	
}



//===========================================================//
// Interruption Bluetooth
//===========================================================//

/**
*@brief dans cette interruption (UART0) on met le flag PLAYER_INPUT a true
*
*/
void UART0_IRQHandler(){
	UART_Receive(LPC_UART0, RXBUFFER, INPUT_BUF_LEN, NONE_BLOCKING);
	PLAYER_INPUT = true;
	//gestion des actions du joueur par interrupt
}

