/*
 * EXTI_Private.h
 *
 *  Created on: Jul 11, 2022
 *      Author: ENG TAREK
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define APB2PERIPH_BASEADDR			0x40010000U

#define EXTI_BASEADDR		(APB2PERIPH_BASEADDR + 0x0400)
#define AFIO_BASEADDR		(APB2PERIPH_BASEADDR + 0x0000)

#define EXTI 				((EXTI_RegDef_t*)EXTI_BASEADDR)
#define AFIO 				((AFIO_RegDef_t*)AFIO_BASEADDR)

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_RegDef_t;

typedef struct{

	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_RegDef_t;


/*EXTI Lines*/
#define LINE0              0
#define LINE1              1
#define LINE2              2
#define LINE3              3
#define LINE4              4
#define LINE5              5
#define LINE6              6
#define LINE7              7
#define LINE8              8
#define LINE9              9
#define LINE10             10
#define LINE11             11
#define LINE12             12
#define LINE13             13
#define LINE14             14
#define LINE15             15

#define RISING				0
#define FALLING				1
#define CHANGE				2

/*
	this enum represents Alternative function in lower register
	AFRLy: Alternate function selection for port x bit y (y = 0..7)
	These bits are written by software to configure alternate function I/Os
	AFRLy selection:
	0000: AF0
	0001: AF1
	0010: AF2
	0011: AF3
	0100: AF4
	0110: AF6
	0111: AF7
	1000: AF8
	1001: AF9
	1010: AF10
	1011: AF11
	1100: AF12
	1101: AF13
	1110: AF14
	1111: AF15
*/

typedef enum
{
	AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
}Alt_FunctionL;

#endif /* EXTI_PRIVATE_H_ */
