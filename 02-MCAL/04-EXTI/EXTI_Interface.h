/*
 * EXTI_Interface.h
 *
 *  Created on: Jul 11, 2022
 *      Author: ENG TAREK
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
}Alt_FunctionL;

typedef enum
{
	A,B,C,D,E
}AFPortMap;

void EXTI_Init(u8 Copy_u8Line, AFPortMap Copy_u8PortMap, u8 Copy_u8Mode );

void EXTI_SWTrigger(u8 Copy_u8Line);


#endif /* EXTI_INTERFACE_H_ */
