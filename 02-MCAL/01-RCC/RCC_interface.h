/**********************************************************
******************Author : TAREK WAEL**********************
******************Component : RCC	 **********************
******************Version : 01       **********************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_HSE_CRYSTAL 	0
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_PLL				3


#define RCC_AHB				0
#define RCC_APB1			1
#define RCC_APB2		`	2

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock( u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock( u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif