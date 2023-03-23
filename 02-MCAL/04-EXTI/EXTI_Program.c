/*
 * EXTI_Program.c
 *
 *  Created on: Jul 11, 2022
 *      Author: ENG TAREK
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f103xx.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"



void EXTI_Init(u8 Copy_u8Line, AFPortMap Copy_u8PortMap, u8 Copy_u8Mode ){
u8 Local_u8RegID = 0;
switch(Copy_u8Mode){
case CHANGE: SET_BIT(EXTI->FTSR,Copy_u8Line);SET_BIT(EXTI->RTSR,Copy_u8Line);break;
case RISING: SET_BIT(EXTI->RTSR,Copy_u8Line);break;
case FALLING: SET_BIT(EXTI->FTSR,Copy_u8Line);break;
}
SET_BIT(EXTI->IMR,Copy_u8Line);//Enables the desired line

Local_u8RegID = Copy_u8Line/4;
Copy_u8Line %=4;
AFIO->EXTICR[Local_u8RegID] &= ~((0b1111) << (Copy_u8Line*4));
AFIO->EXTICR[Local_u8RegID] |= ((Copy_u8PortMap) << (Copy_u8Line*4)); //Choosing the desired pin in activated line
}

void EXTI_Disable(u8 Copy_u8Line){
	CLR_BIT(EXTI->IMR,Copy_u8Line);
}
void EXTI_SWTrigger(u8 Copy_u8Line){
	SET_BIT(EXTI->SWIER,Copy_u8Line);
}
