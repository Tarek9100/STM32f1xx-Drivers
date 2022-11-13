/**********************************************************
******************Author : TAREK WAEL**********************
******************Component : RCC	 **********************
******************Version : 01       **********************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"

void RCC_voidInitSysClock(void){

#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
RCC->CR |= 0X0001000; /*Enable HSE_crystal*/
RCC->CFGR =0x00000001
#elif	RCC_CLOCK_TYPE == RCC_HSE_RC

RCC->CR |= 0X0005000; /*Enable HSE_RC*/
RCC->CFGR =0x00000001
#elif	RCC_CLOCK_TYPE == RCC_HSI

RCC->CR |= 0x00000001; /*Enable HSI*/
RCC->CFGR =0x00000001
#elif	RCC_CLOCK_TYPE == RCC_PLL
RCC->CR |= 0x00000001;
#else
	#error("Wrong Clock Type!")	
	
}

void RCC_voidEnableClock( u8 Copy_u8BusId, u8 Copy_u8PerId){

if(Copy_u8PerId < 32){
	
	switch(Copy_u8BusId)

	{
	case RCC_AHB: SET_BIT(RCC->AHBENR,Copy_u8PerId);break;
	case:RCC_APB1:SET_BIT(RCC->APB1ENR,Copy_u8PerId);break;
	case:RCC_APB2:SET_BIT(RCC->APB2ENR,Copy_u8PerId);break;	
	}
}
else{
	

}
}
void RCC_voidDisableClock( u8 Copy_u8BusId, u8 Copy_u8PerId){

if(Copy_u8PerId < 32){
	
	switch(Copy_u8BusId)

	{
		case RCC_AHB: CLR_BIT(RCC->AHBENR,Copy_u8PerId);break;
		case:RCC_APB1:CLR_BIT(RCC->APB1ENR,Copy_u8PerId);break;
		case:RCC_APB2:CLR_BIT(RCC->APB2ENR,Copy_u8PerId);break;	
	}
}
else{
	
/*Return Error*/
}
}	