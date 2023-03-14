/**********************************************************
******************Author : TAREK WAEL**********************
******************Component : RCC	 **********************
******************Version : 01       **********************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock( u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock( u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidInitPBusClock(void);

#endif