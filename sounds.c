/**
 * @file sounds.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Procédures générant du son + initialisation du HP 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "timer.h"
#include "sounds.h"
#include "LPC17xx_pinsel.h"
#include "LPC17xx_gpio.h"
#include "LPC17xx_timer.h"
#include "globaldec.h"


void init_sound(void){
	PINSEL_CFG_Type SPEAKER_CFG;
	SPEAKER_CFG.Pinnum = PINSEL_PIN_9;
	SPEAKER_CFG.Portnum = PINSEL_PORT_1;
	SPEAKER_CFG.Funcnum = PINSEL_FUNC_0;
	PINSEL_ConfigPin(&SPEAKER_CFG);
	GPIO_SetDir(1,(1<<9),1);
}

//ces modules ont un probl�me : si deux sons se produisent en m�me temps, le son est coup�
//les timers s'arr�tent.

void bip_high(void){
	TIM_UpdateMatchValue(LPC_TIM0, 0, 1);
	TIM_Cmd(LPC_TIM1, ENABLE);
	TIM_Cmd(LPC_TIM0, ENABLE);
}


void bip_low(void){
	TIM_UpdateMatchValue(LPC_TIM0, 0, 4);
	TIM_Cmd(LPC_TIM1, ENABLE);
	TIM_Cmd(LPC_TIM0, ENABLE);
}

