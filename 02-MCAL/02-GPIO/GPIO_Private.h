/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	GPIO                                       */
/***********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR						0x08000000U
#define SRAM_BASEADDR						0x20000000U
#define ROM_BASEADDR						0x1FFF0000U
#define SRAM 								SRAM1_BASEADDR


/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHBPERIPH_BASEADDR						0x40018000U




#define GPIOA_BASEADDR                  (APB2PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR                  (APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR 					(APB2PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR 					(APB2PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR 					(APB2PERIPH_BASEADDR + 0x1800)
#define GPIOF_BASEADDR 					(APB2PERIPH_BASEADDR + 0x1C00)
#define GPIOG_BASEADDR 					(APB2PERIPH_BASEADDR + 0x2000)



#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  				((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  				((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define TIM2_BASEADDR                  (APB1PERIPH_BASEADDR)


#define TIM2						((TIM_RegDef_t*)TIM2_BASEADDR)


/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
 */

 typedef struct
{
	volatile u32 CR[2];                        /*      Address offset: 0x00      */
	volatile u32 IDR;                      	   /*	   Address offset: 0x08		 */
	volatile u32 ODR;						   /*      Address offset: 0x0C      */
	volatile u32 BSRR;                         /*      Address offset: 0x10      */
	volatile u32 BRR;                          /*      Address offset: 0x14      */
	volatile u32 LCKR;                         /*      Address offset: 0x18      */
}GPIO_RegDef_t;
/**/
typedef struct
{
	u8 GPIO_Pin_Number;
	u8 GPIO_Pin_Mode;
	u8 GPIO_PIN_Speed;
	u8 GPIO_Pin_Pu_PdCTRL;

}GPIO_Pin_Config_t;

typedef struct{
volatile u32 CR[2];
volatile u32 SMCR;
volatile u32 DIER;
volatile u32 SR;
volatile u32 EGR;
volatile u32 CCMR[2];
volatile u32 CCER;
volatile u32 CNT;
volatile u32 PSC;
volatile u32 ARR;
volatile u32 Reserved1;
volatile u32 CCR[4];
volatile u32 Reserved2;
volatile u32 DCR;
volatile u32 DMAR;
}TIM_RegDef_t;


#define ENABLE						1
#define DISABLE						0

#define HIGH 						1
#define LOW							0

#define GPIO_PIN_NO_0					0
#define GPIO_PIN_NO_1					1
#define GPIO_PIN_NO_2					2
#define GPIO_PIN_NO_3					3
#define GPIO_PIN_NO_4					4
#define GPIO_PIN_NO_5					5
#define GPIO_PIN_NO_6					6
#define GPIO_PIN_NO_7					7
#define GPIO_PIN_NO_8					8
#define GPIO_PIN_NO_9					9
#define GPIO_PIN_NO_10					10
#define GPIO_PIN_NO_11					11
#define GPIO_PIN_NO_12					12
#define GPIO_PIN_NO_13					13
#define GPIO_PIN_NO_14					14
#define GPIO_PIN_NO_15					15

/*Macros for all pin config*/
#define GPIOC_INPUT_MODE 						0
#define GPIOC_OUTPUT_MODE						1


#define GPIOC_OP_GP								1 			//General Purpose Output Push-Pull
#define GPIOC_OP_AF								9			//General Purpose Output Push-Pull


/*
 * GPIO pin possible input types
 */
#define GPIO_IP_Analog			0			//Input Analog
#define GPIO_IP_Floating		4			//Input Floating
#define GPIO_IP_Pull			8			//Input Pull-resistor

/*
 * GPIO pin possible output types
 */
#define GPIO_OP_GP_PP			0			 //General Purpose Output Push-Pull
#define GPIO_OP_GP_OD			4  			 //General Purpose Output Open Drain
#define GPIO_OP_AF_PP			8			 //Alternate Function Output Push-Pull
#define GPIO_OP_AF_OD			12  		 //Alternate Function Output Open Drain

/*
 *  GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_2 				1	 //2 MHz
#define GPIO_SPEED_10				2	 //10 MHz
#define GPIO_SPEED_50 				3	 //50 MHz


/* GPIO pin pull up and pull down configuration macros*/
#define GPIO_PIN_PD					0
#define GPIO_PIN_PU					1
#define GPIO_NO_PUPD				2

/* Macros for PWM*/

#define PSC_TIM2 1
#define ARR_TIM2 65534


#define Tim1 1
#define Tim2 2
#define Tim3 3
#define Tim4 4

#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4




#endif
