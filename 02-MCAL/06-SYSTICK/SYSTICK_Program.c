/*
 * SYSTICK.c
 *
 *  Created on: Jul 12, 2022
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_Interface.h"
#include "SYSTICK_Private.h"
#include "SYSTICK_Config.h"




void STK_Delay_MicroSeconds(u32 Copy_u32MicroSecond){
CLR_BIT(SYSTICK->CTRL,STK_CLKSOURCE); // Setting Clk = AHB/8 -> 1MHz
u32 Local_u32Load = (Copy_u32MicroSecond & 0xFFFFFF); // Making sure the passed value doesn't exceed the range of 24 bits
SYSTICK->LOAD = Local_u32Load;
SET_BIT(SYSTICK->CTRL,STK_ENABLE); // ENABLE Systick
while(!(GET_BIT(SYSTICK->CTRL,STK_COUNTFLAG))); // Busy waiting until count flag = 1
}

void STK_Count_MicroSeconds(u32 Copy_u32MicroSecond, void (*ptr)(void)){
u32 Local_u32Load = (Copy_u32MicroSecond & 0xFFFFFF); // Making sure the passed value doesn't exceed the range of 24 bits
SYSTICK->LOAD = Local_u32Load;

	CallBack = ptr;
}

void STK_Handler(){
	CallBack();
}
