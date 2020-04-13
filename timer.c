/**
 * @file timer.c
 * @author Bolou Glenan (gbolou@enssat.fr)
 * @brief Interruptions des timers + initialisation des timers 
 * @version 0.1
 * @date 2020-04-13
 *
 *
 */

#include "timer.h"
#include "sounds.h"
#include "globaldec.h"
#include "LPC17xx_timer.h"
#include "LPC17xx_gpio.h"
#include "LPC17xx.h"
//initialisation, d�marrage, interrtupts

void init_timer(void){
	TIM_TIMERCFG_Type TIMER_CFG;
	TIM_MATCHCFG_Type MATCH_CFG;
	
	
	//config timer 1 : pour la note
	TIMER_CFG.PrescaleOption = TIM_PRESCALE_TICKVAL;
	TIMER_CFG.PrescaleValue = 25000;
	
	MATCH_CFG.MatchChannel = 0;
	MATCH_CFG.MatchValue = 1;
	MATCH_CFG.ResetOnMatch = ENABLE;
	MATCH_CFG.IntOnMatch = ENABLE;
	MATCH_CFG.ExtMatchOutputType= TIM_EXTMATCH_TOGGLE;
	
	TIM_Init(LPC_TIM0, TIM_TIMER_MODE, &TIMER_CFG);
	TIM_ConfigMatch(LPC_TIM0, &MATCH_CFG);
	
	NVIC_EnableIRQ(TIMER0_IRQn);
	
	
	//config timer 2 : pour la dur�e de la note
	TIMER_CFG.PrescaleOption = TIM_PRESCALE_TICKVAL;
	TIMER_CFG.PrescaleValue = 500;
	
	MATCH_CFG.MatchChannel = 1;
	MATCH_CFG.MatchValue = 4000;
	MATCH_CFG.StopOnMatch = ENABLE;
	MATCH_CFG.IntOnMatch = ENABLE;
	MATCH_CFG.ExtMatchOutputType= TIM_EXTMATCH_TOGGLE;
	
	TIM_Init(LPC_TIM1, TIM_TIMER_MODE, &TIMER_CFG);
	TIM_ConfigMatch(LPC_TIM1, &MATCH_CFG);
	
	NVIC_EnableIRQ(TIMER1_IRQn);
	
	//config timer 3 : pour le rythme des notes 
	//PAS UTILISE
	/*
	TIMER_CFG.PrescaleOption = TIM_PRESCALE_TICKVAL;
	TIMER_CFG.PrescaleValue = 500;
	
	MATCH_CFG.MatchChannel = 2;
	MATCH_CFG.MatchValue = 20000;
	MATCH_CFG.StopOnMatch = DISABLE;
	MATCH_CFG.ResetOnMatch = ENABLE;
	MATCH_CFG.IntOnMatch = ENABLE;
	MATCH_CFG.ExtMatchOutputType= TIM_EXTMATCH_TOGGLE;
	
	TIM_Init(LPC_TIM2, TIM_TIMER_MODE, &TIMER_CFG);
	TIM_ConfigMatch(LPC_TIM2, &MATCH_CFG);
	
	NVIC_EnableIRQ(TIMER2_IRQn);
	*/
	
}


/**
*@brief dans cette interruption(TIM0) on produit le son� proprement parler
*
*/
void TIMER0_IRQHandler(void){
	GPIO_SetValue(1, (1<<9));
	GPIO_ClearValue(1, (1<<9));
	TIM_ClearIntPending(LPC_TIM0, TIM_MR0_INT);
}

/**
*@brief dans cette interruption  (TIM1) on �teint le timer 0 (fin du son) 
*
*/
void TIMER1_IRQHandler(void){
	TIM_Cmd(LPC_TIM0, DISABLE);
	TIM_ClearIntPending(LPC_TIM1, TIM_MR1_INT);
}

