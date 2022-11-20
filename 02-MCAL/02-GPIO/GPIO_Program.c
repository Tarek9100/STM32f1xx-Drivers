/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	GPIO                                       */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "RCC.h"
void GPIO_PerClockControl(GPIO_RegDef_t *pGPIO_x,u8 EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIO_x == GPIOA){
			GPIOA_PCLK_EN();
		}else if(pGPIO_x == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIO_x == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIO_x == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIO_x == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
	}else{

		if(pGPIO_x == GPIOA){
					GPIOA_PCLK_DI();
				}else if(pGPIO_x == GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if(pGPIO_x == GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if(pGPIO_x == GPIOD)
				{
					GPIOD_PCLK_DI();
				}
				else if(pGPIO_x == GPIOD)
				{
					GPIOE_PCLK_DI();
				}
		}
}

/*void GPIO_All_Init(void){

}
*/
void GPIO_Initialize(GPIO_Handler * pGPIO_Handle){
	if((pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)/8){
	pGPIO_Handle-> pGPIO_x->CR[1] &= ~( 0x8 << ( 4 * (pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)-8)); // Clearing pre-set Mode bits before changing configuration
	pGPIO_Handle->pGPIO_x->CR[1] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)-8)));// x4 as each pin takes 2 bit-fields
	pGPIO_Handle->pGPIO_x->CR[1] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_PIN_Speed <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)-8)));// x4 as each pin takes 2 bit-fields
}
else{
	pGPIO_Handle-> pGPIO_x->CR[0] &= ~( 0x8 << ( 4 * pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)); // Clearing pre-set Mode bits before changing configuration
	pGPIO_Handle->pGPIO_x->CR[0] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode <<(4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));// x4 as each pin takes 2 bit-fields
	pGPIO_Handle->pGPIO_x->CR[0] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_PIN_Speed <<((4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)));// x2 as each pin takes 2 bit-fields
	}
if(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode == GPIO_IP_Pull){
	switch (pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL){
	case GPIO_PIN_PD: //CLR_BIT(pGPIO_Handle->pGPIO_x->ODR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
	pGPIO_Handle->pGPIO_x->BRR = (1<<pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);break;
	case GPIO_PIN_PU: //SET_BIT(pGPIO_Handle->pGPIO_x->ODR,pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
	pGPIO_Handle->pGPIO_x->BSRR = (1<<pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);break;
	default : break;
	}
}
}
void GPIO_Deinit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA){
			GPIOA_REG_RESET();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}
}


u8 GPIO_ReadPin(GPIO_RegDef_t  * pGPIO_x,u8 Pin_Number)
{
	return  ((u8)GET_BIT(pGPIO_x ->IDR,Pin_Number));
}

void GPIO_WritePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number,u8 Value)
{
	if (Value != LOW)
	{
	//Write 1 to the output data register at the bit
	//SET_BIT(pGPIO_x->ODR,Pin_Number);
	pGPIO_x->BSRR = (1<<Pin_Number);
	}
	else
	{
	//CLR_BIT(pGPIO_x->ODR,Pin_Number);
	pGPIO_x->BRR = (1<<Pin_Number);
	}

}
u16 GPIO_ReadPort(GPIO_RegDef_t  * pGPIO_x)
{
	return ((u16) pGPIO_x->IDR);
}


void GPIO_WritePort(GPIO_RegDef_t  *pGPIO_x,u16 Value)
{

	pGPIO_x->ODR = Value;

}

void GPIO_TogglePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number){
	TOG_BIT(pGPIO_x->ODR,Pin_Number);
}


void GPIO_USART1_Init(){
	GPIO_Handler RX1,TX1;
		RX1.pGPIO_x= GPIOA;
		RX1.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
		RX1.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_IP_Floating;
		RX1.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		RX1.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_9;
		TX1.pGPIO_x= GPIOA;
		TX1.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
		TX1.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_OP_GP_PP;
		TX1.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		TX1.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_10;
		GPIO_PerClockControl(GPIOA,ENABLE);
		GPIO_Initialize(&RX1);
		GPIO_Initialize(&TX1);
}
void GPIO_USART2_Init(){
	GPIO_Handler RX2,TX2;
		RX2.pGPIO_x= GPIOA;
		RX2.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
		RX2.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_IP_Floating;
		RX2.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		RX2.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_3;
		TX2.pGPIO_x= GPIOA;
		TX2.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
		TX2.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_OP_GP_PP;
		TX2.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		TX2.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_2;
		GPIO_PerClockControl(GPIOA,ENABLE);
		GPIO_Initialize(&RX2);
		GPIO_Initialize(&TX2);
}
void GPIO_USART3_Init(){
	GPIO_Handler RX3,TX3;
		RX3.pGPIO_x= GPIOB;
		RX3.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
		RX3.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_IP_Floating;
		RX3.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		RX3.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_11;
		TX3.pGPIO_x= GPIOB;
		TX3.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
		TX3.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_OP_GP_PP;
		TX3.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		TX3.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_10;
		GPIO_PerClockControl(GPIOB,ENABLE);
		GPIO_Initialize(&RX3);
		GPIO_Initialize(&TX3);
}

void GPIO_PWM_Write( u8 Copy_u8_Channel, u16 Copy_u16_DutyCycle){

TIM2_PCLK_EN();
GPIOA->CR[0] &=~(0xF<< 4*Copy_u8_Channel);
GPIOA->CR[0]|= (0xB<< 4*Copy_u8_Channel); //A0 -> A4 output 10 MHz
TIM2->CCER |= (1<<4*Copy_u8_Channel);//CCxE = 1 ,CCxP = 0

if(Copy_u8_Channel< 2){

TIM2->CCMR[0]&=~(0xFF<<8*Copy_u8_Channel);
TIM2->CCMR[0]|= (0x68<<16*Copy_u8_Channel);  /* OCxM=PWM1, OCxPE=1 */
}
else if(Copy_u8_Channel< 4){

Copy_u8_Channel-=2;
TIM2->CCMR[1]&=~(0xFF<<8*Copy_u8_Channel);
TIM2->CCMR[1]|= (0x68<<16*Copy_u8_Channel);  /* OCxM=PWM1, OCxPE=1 */
}

SET_BIT(TIM2->CR[0],7); /* Auto reload preload enable*/

TIM2->PSC = PSC_TIM2;
TIM2->ARR = ARR_TIM2;

SET_BIT(TIM2->EGR,0); /* UG = 1 (generate update) */
SET_BIT(TIM2->CR[0],0); /* timer enable (CEN = 1) */

TIM2->CCR[Copy_u8_Channel] = Copy_u16_DutyCycle;
}
void GPIO_ADC_Config(void){//a6 & a7
	GPIO_Handler ADC1,ADC2;
	ADC1.pGPIO_x= GPIOA;
	ADC1.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
	ADC1.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_IP_Analog;
	ADC1.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
	ADC1.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_6;
	ADC2.pGPIO_x= GPIOA;
	ADC2.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_50;
	ADC2.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_IP_Analog;
	ADC2.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
	ADC2.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_7;
	GPIO_PerClockControl(GPIOB,ENABLE);
	GPIO_Initialize(&ADC1);
	GPIO_Initialize(&ADC2);
}

void GPIO_R1_Init(void){
	GPIO_Handler R1_CS,R1_INC,R1_UOD,ADC_VB,ADC_YLD;
		R1_CS.pGPIO_x= GPIOB;
		R1_CS.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_4;
		R1_CS.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_2;
		R1_CS.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_OP_GP_PP;
		R1_CS.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		GPIO_PerClockControl(GPIOB,ENABLE);
		GPIO_Initialize(&R1_CS);

		R1_UOD.pGPIO_x= GPIOB;
		R1_UOD.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_5;
		R1_UOD.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_2;
		R1_UOD.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_OP_GP_PP;
		R1_UOD.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		GPIO_PerClockControl(GPIOB,ENABLE);
	    GPIO_Initialize(&R1_UOD);

		R1_INC.pGPIO_x= GPIOB;
		R1_INC.GPIO_PinConfig.GPIO_Pin_Number = GPIO_PIN_NO_6;
		R1_INC.GPIO_PinConfig.GPIO_PIN_Speed= GPIO_SPEED_2;
		R1_INC.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_OP_GP_PP;
		R1_INC.GPIO_PinConfig.GPIO_Pin_Pu_PdCTRL = GPIO_NO_PUPD;
		GPIO_PerClockControl(GPIOB,ENABLE);
		GPIO_Initialize(&R1_INC);
}

