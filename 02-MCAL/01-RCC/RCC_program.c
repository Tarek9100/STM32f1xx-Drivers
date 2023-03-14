/**********************************************************
******************Author : TAREK WAEL**********************
******************Component : RCC	 **********************
******************Version : 01       **********************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f103xx.h"
#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"

void RCC_voidInitSysClock(void){
RCC->CFGR &= ~(0x3);	 
#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
RCC->CFGR |=0x00000001;
RCC->CR |= 0X00010000; /*Enable HSE_crystal*/

#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
RCC->CFGR |= 0x00000001;
RCC->CR |= 0X00050000; /*Enable HSE_RC*/

#elif	RCC_CLOCK_TYPE == RCC_HSI

RCC->CR |= 0x00000001; /*Enable HSI*/

#elif	RCC_CLOCK_TYPE == RCC_PLL
RCC->CFGR &= ~(0xF << 18);
RCC->CFGR |= ((RCC_PLL_MUL_VALUE - 2)<< 18);
SET_BIT(RCC->CFGR, 1);
 #if  	RCC_PLL_INPUT ==  RCC_PLL_HSI_DIV_2

CLR_BIT(RCC->CFGR,16);
RCC->CR |= 0x01000001;
#elif 	RCC_PLL_INPUT == RCC_PLL_HSE

SET_BIT(RCC->CFGR,16);
CLR_BIT(RCC->CFGR,17);
RCC->CR |= 0x01010000;
#elif 	RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2

SET_BIT(RCC->CFGR,16);
SET_BIT(RCC->CFGR,17);
RCC->CR |= 0x01010000;

#else 
	#error("Wrong PLL Clock Source!")
#endif
#else
	#error("Wrong Clock Type!")	
#endif	
}

void RCC_voidInitPBusClock(void){
	
//Set AHB Clock value	
RCC->CFGR &= ~(0xF << 4);
RCC->CFGR |= AHB_PRESCALAR<< 4;

//Set APB1 Clock value
RCC->CFGR &= ~(0x7 << 8);
RCC->CFGR |= APB1_PRESCALAR<< 8;

//Set APB2 Clock value
RCC->CFGR &= ~(0x7 << 11);
RCC->CFGR |= APB2_PRESCALAR<< 11;	
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