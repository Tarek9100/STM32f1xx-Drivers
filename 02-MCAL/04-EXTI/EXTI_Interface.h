/*
 * EXTI_Interface.h
 *
 *  Created on: Jul 11, 2022
 *      Author: ENG TAREK
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



void EXTI_Init(u8 Copy_u8Line, AFPortMap Copy_u8PortMap, u8 Copy_u8Mode );
void EXTI_Disable(u8 Copy_u8Line);
void EXTI_SWTrigger(u8 Copy_u8Line);


#endif /* EXTI_INTERFACE_H_ */
