/*
 * RCC_Program.c
 *
 *  Created on: Jul 9, 2022
 *      Author: ENG TAREK
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC.h"

u32 Prescalar_Arr[8] = {2,4,8,16,64,128,256,512};
u32 RCC_GetPCLK1Value(void){
	u32 pclk1 = 16000000,SystemClock = 16000000;
	u8 clksrc,temp,ahb=1,apb1=1;
	clksrc = ((RCC->CFGR>>2) & 0x3);
	switch(clksrc){
	case 0:SystemClock = 16000000;break; //HSI
	case 1:SystemClock = 8000000;break;  //HSE
	case 2:temp = ((RCC->CFGR>>4) & 0xF);
	if(temp<8){
	ahb=1;
	}
	else{
	ahb=Prescalar_Arr[temp-8];
	}
	temp = ((RCC->CFGR>>10) & 0x7);
		if(temp<4){
		apb1=1;
		}
		else{
		apb1=Prescalar_Arr[temp-4];
		}
	}

pclk1 = (SystemClock/ahb)/apb1;
return pclk1;}
u32 RCC_GetPCLK2Value(void){
	u32 pclk2 = 16000000,SystemClock = 16000000;
	u8 clksrc,temp,ahb=1,apb2=1;
	clksrc = ((RCC->CFGR>>2) & 0x3);
	switch(clksrc){
	case 0:SystemClock = 16000000;break; //HSI
	case 1:SystemClock = 8000000;break;  //HSE
	case 2:temp = ((RCC->CFGR>>4) & 0xF);
	if(temp<8){
	ahb=1;
	}
	else{
	ahb=Prescalar_Arr[temp-8];
	}
	temp = ((RCC->CFGR>>13) & 0x7);
		if(temp<4){
		apb2=1;
		}
		else{
		apb2=Prescalar_Arr[temp-4];
		}
	}

pclk2 = (SystemClock/ahb)/apb2;
return pclk2;}


