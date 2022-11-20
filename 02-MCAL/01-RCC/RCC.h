/*
 * RCC.h
 *
 *  Created on: Jul 9, 2022
 *      Author: ENG TAREK
 */

#ifndef RCC_H_
#define RCC_H_

#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHBPERIPH_BASEADDR						0x40018000U

#define RCC_BASEADDR                    (AHBPERIPH_BASEADDR + 0x9000)
#define RCC 							((RCC_RegDef_t*)RCC_BASEADDR)

u32 RCC_GetPCLK1Value(void);
u32 RCC_GetPCLK2Value(void);
typedef struct
{
	volatile u32 CR;					//RCC clock control register
	volatile u32 CFGR;					//RCC clock configuration register
	volatile u32 CIR;					//RCC clock u32errupt register
	volatile u32 APB2RSTR;				//RCC APB2 peripheral reset register
	volatile u32 APB1RSTR;				//RCC APB1 peripheral reset register
	volatile u32 AHBENR;				//RCC AHB peripheral clock enable register
	volatile u32 APB2ENR;				//RCC APB2 peripheral clock enable register
	volatile u32 APB1ENR;				//RCC APB1 peripheral clock enable register
	volatile u32 BDCR;					//RCC Backup domain control register
	volatile u32 CSR;					//RCC clock control & status register
	volatile u32 AHBRSTR;				//RCC AHB peripheral reset register
	volatile u32 CFGR2;					//RCC clock configuration register

}RCC_RegDef_t;
/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()			(RCC->APB2ENR |=(1<<2))
#define GPIOB_PCLK_EN()			(RCC->APB2ENR |=(1<<3))
#define GPIOC_PCLK_EN()			(RCC->APB2ENR |=(1<<4))
#define GPIOD_PCLK_EN()			(RCC->APB2ENR |=(1<<5))
#define GPIOE_PCLK_EN()			(RCC->APB2ENR |=(1<<6))



/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()			(RCC->APB2ENR &= ~(1<<2))
#define GPIOB_PCLK_DI()			(RCC->APB2ENR &= ~(1<<3))
#define GPIOC_PCLK_DI()			(RCC->APB2ENR &= ~(1<<4))
#define GPIOD_PCLK_DI()			(RCC->APB2ENR &= ~(1<<5))
#define GPIOE_PCLK_DI()			(RCC->APB2ENR &= ~(1<<6))

/* Clock Enable/Disable for USARTx peripherals */

#define USART1_PCLK_EN()		(RCC->APB2ENR |= (1<<4))
#define USART1_PCLK_DI()		(RCC->APB2ENR &= ~(1<<4))

#define USART2_PCLK_EN()		(RCC->APB1ENR |= (1<<17))
#define USART2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<17))

#define USART3_PCLK_EN()		(RCC->APB1ENR |= (1<<18))
#define USART3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<18))

#define USART6_PCLK_EN()		(RCC->APB1ENR |= (1<<5))
#define USART6_PCLK_DI()		(RCC->APB1ENR &= ~(1<<5))

/* Clock Enable/Disable for UARTx peripherals */

#define UART4_PCLK_EN()			(RCC->APB1ENR |= (1<<19))
#define UART4_PCLK_DI()			(RCC->APB1ENR &= ~(1<<19))

#define UART5_PCLK_EN()			(RCC->APB1ENR |= (1<<20))
#define UART5_PCLK_DI()			(RCC->APB1ENR &= ~(1<<20))

/* Clock Enable/Disable for ADCx peripherals */

#define ADC1_PCLK_EN()		(RCC->APB2ENR |= (1<<9))
#define ADC1_PCLK_DI()		(RCC->APB2ENR &= ~(1<<9))

#define ADC2_PCLK_EN()		(RCC->APB1ENR |= (1<<10))
#define ADC2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<10))

/*Clock Enable/Disable for ADCx peripherals */

#define TIM2_PCLK_EN()		(RCC->APB1ENR |= (1<<0))
#define TIM2_PCLK_DI()		(RCC->APB1ENR &= ~(1<<0))

#define TIM3_PCLK_EN()		(RCC->APB1ENR |= (1<<1))
#define TIM3_PCLK_DI()		(RCC->APB1ENR &= ~(1<<1))

#define TIM4_PCLK_EN()		(RCC->APB1ENR |= (1<<2))
#define TIM4_PCLK_DI()		(RCC->APB1ENR &= ~(1<<2))

#define TIM5_PCLK_EN()		(RCC->APB1ENR |= (1<<3))
#define TIM5_PCLK_DI()		(RCC->APB1ENR &= ~(1<<3))


#define GPIOA_REG_RESET()					do{ (RCC->APB2RSTR |=(1<<2));	(RCC->APB2RSTR &=~(1<<2));} while(0)
#define GPIOB_REG_RESET()					do{ (RCC->APB2RSTR |=(1<<3));	(RCC->APB2RSTR &=~(1<<3));} while(0)
#define GPIOC_REG_RESET()					do{ (RCC->APB2RSTR |=(1<<4));	(RCC->APB2RSTR &=~(1<<4));} while(0)
#define GPIOD_REG_RESET()					do{ (RCC->APB2RSTR |=(1<<5));	(RCC->APB2RSTR &=~(1<<5));} while(0)
#define GPIOE_REG_RESET()					do{ (RCC->APB2RSTR |=(1<<6));	(RCC->APB2RSTR &=~(1<<6));} while(0)

/* do while is used to execute multiple statements in using only one micro */



#endif
/* RCC_H_ */
