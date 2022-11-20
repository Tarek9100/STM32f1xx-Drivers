
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_Private.h"

typedef struct
{
	GPIO_RegDef_t  * pGPIO_x;
	GPIO_Pin_Config_t  GPIO_PinConfig;
}GPIO_Handler;


/* Configuration Struct */




/* Peripheral Clock setup*/
void GPIO_PerClockControl(GPIO_RegDef_t *pGPIOx,u8 EnorDi);

/*Initializing/De-initializing GPIO*/
void GPIO_All_Init(void); // User Initializing from config header file
void GPIO_Initialize(GPIO_Handler * pGPIO_Handle);
void GPIO_Deinit(GPIO_RegDef_t *pGPIOx);


u8 GPIO_ReadPin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number);
u16 GPIO_ReadPort(GPIO_RegDef_t  *pGPIO_x);
void GPIO_WritePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number,u8 Value);
void GPIO_WritePort(GPIO_RegDef_t  *pGPIO_x,u16 Value);
void GPIO_TogglePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number);


void GPIO_USART1_Init();
void GPIO_USART2_Init();
void GPIO_USART3_Init();

void GPIO_ADC_Config(void);
void GPIO_R1_Init(void);

#endif
