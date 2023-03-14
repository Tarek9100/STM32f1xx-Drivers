/*
 * stm32f103xx.h
 *
 *  Created on: May 8, 2022
 *      Author: ENG TAREK
 */

#ifndef STM_ADDRESSES_H
#define STM_ADDRESSES_H

#include "STD_TYPES.h"
/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR						0x08000000U
#define SRAM1_BASEADDR						0x20000000U
#define SRAM2_BASEADDR						0x2001C000U
#define ROM_BASEADDR						0x1FFF0000U
#define SRAM 								SRAM1_BASEADDR


/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHB1PERIPH_BASEADDR						0x40020000U
#define AHB2PERIPH_BASEADDR						0x50000000U



#define GPIOA_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x2000)

#define RCC_BASEADDR                    (AHB1PERIPH_BASEADDR + 0x1000) /**/
#define EXTI_BASEADDR					(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)

#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR					(APB2PERIPH_BASEADDR + 0x3400)

#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR					(APB1PERIPH_BASEADDR + 0x5C00)

#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0x1000)
#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR					(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR					(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR					(APB1PERIPH_BASEADDR + 0x5000)
#define USART6_BASEADDR					(APB2PERIPH_BASEADDR + 0x1400)
/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
 */

 typedef struct
{
	volatile u32 MODER;                        /*!< GPIO port mode register,      Address offset: 0x00      */
	volatile u32 OTYPER;                       /*!<     						  Address offset: 0x04      */
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFR[2];					 /*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
}GPIO_RegDef_t;

typedef struct
{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;
}SPI_RegDef_t;

typedef struct
{
	volatile u32 CR;					//RCC clock control register																	Address offset: 0x00
	volatile u32 CFGR;					//RCC clock configuration register																Address offset: 0x04
	volatile u32 CIR;					//RCC clock u32errupt register																	Address offset: 0x08
	volatile u32 APB2RSTR;				//RCC APB2 peripheral reset register															Address offset: 0x0C
	volatile u32 APB1RSTR;				//RCC APB1 peripheral reset register															Address offset: 0x10
	volatile u32 AHBENR;				//RCC AHB peripheral clock enable register														Address offset: 0x14
	volatile u32 APB2ENR;				//RCC APB2 peripheral clock enable register 													Address offset: 0x18
	volatile u32 APB1ENR;				//RCC APB1 peripheral clock enable register														Address offset: 0x1C
	volatile u32 BDCR;					//RCC Backup domain control register 															Address offset: 0x20
	volatile u32 CSR;					//RCC clock control & status register															Address offset: 0x24

}RCC_RegDef_t; /**/

#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  				((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  				((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)
#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1				 ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2                 ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3                 ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4                 ((SPI_RegDef_t*)SPI4_BASEADDR)

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |=(1<<4))
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |=(1<<7))


/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<7))

/* Clock Enable/Disable for SPIx peripherals */

#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1<<12))
#define SPI1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<12))

#define SPI2_PCLK_EN()			(RCC->APB1ENR |= (1<<14))
#define SPI2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<14))

#define SPI3_PCLK_EN()			(RCC->APB1ENR |= (1<<15))
#define SPI3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<15))

#define SPI4_PCLK_EN()			(RCC->APB2ENR |= (1<<13))
#define SPI4_PCLK_DI()			(RCC->APB2ENR &= ~(1<<13))

/* Clock Enable/Disable for USARTx peripherals */

#define USART1_PCLK_EN()			(RCC->APB2ENR |= (1<<4))
#define USART1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<4))

#define USART2_PCLK_EN()			(RCC->APB1ENR |= (1<<17))
#define USART2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<17))

#define USART3_PCLK_EN()			(RCC->APB1ENR |= (1<<18))
#define USART3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<18))

#define USART6_PCLK_EN()			(RCC->APB1ENR |= (1<<5))
#define USART6_PCLK_DI()			(RCC->APB1ENR &= ~(1<<5))

/* Clock Enable/Disable for UARTx peripherals */

#define UART4_PCLK_EN()			(RCC->APB1ENR |= (1<<19))
#define UART4_PCLK_DI()			(RCC->APB1ENR &= ~(1<<19))

#define UART5_PCLK_EN()			(RCC->APB1ENR |= (1<<20))
#define UART5_PCLK_DI()			(RCC->APB1ENR &= ~(1<<20))

/* Clock Enable/Disable for I2Cx peripherals */

#define I2C1_PCLK_EN()			(RCC->APB1ENR |= (1<<21))
#define I2C1_PCLK_DI()			(RCC->APB1ENR &= ~(1<<21))

#define I2C2_PCLK_EN()			(RCC->APB1ENR |= (1<<22))
#define I2C2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<22))

#define I2C3_PCLK_EN()			(RCC->APB1ENR |= (1<<23))
#define I2C3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<23))


#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI10			40


#endif
