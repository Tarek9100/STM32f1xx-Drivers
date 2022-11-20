#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H


#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHBPERIPH_BASEADDR						0x40018000U


#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)
#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR					(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR					(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR					(APB1PERIPH_BASEADDR + 0x5000)


#define USART1               ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2               ((USART_RegDef_t*)USART2_BASEADDR)
#define USART3               ((USART_RegDef_t*)USART3_BASEADDR)
#define UART4              	 ((USART_RegDef_t*)UART4_BASEADDR)
#define UART5              	 ((USART_RegDef_t*)UART5_BASEADDR)

#define USART_FLAG_TXE			7
#define USART_FLAG_TC			6
#define USART_FLAG_RXNE			5
#define USART_CR1_OVER8			15

typedef struct{
	volatile u32 USART_SR;
	volatile u32 USART_DR;
	volatile u32 USART_BRR;
	volatile u32 USART_CR[3];
	volatile u32 USART_GTPR;

}USART_RegDef_t;

typedef struct
{
	u8 USART_Mode;
	u32 USART_Baud;
	u8 USART_NoOfStopBits;
	u8 USART_WordLength;
	u8 USART_ParityControl;
	u8 USART_HWFlowControl;

}USART_Pin_Config_t;





#define USART_FLAG_TXE			7
#define USART_FLAG_TC			6
#define USART_FLAG_RXNE			5
#define USART_CR1_OVER8			15

/*
 *@USART_Mode
 *Possible options for USART_Mode
 */
#define USART_MODE_ONLY_TX 0
#define USART_MODE_ONLY_RX 1
#define USART_MODE_TXRX  2

/*
 *@USART_Baud
 *Possible options for USART_Baud
 */
#define USART_STD_BAUD_1200					1200
#define USART_STD_BAUD_2400					2400
#define USART_STD_BAUD_9600					9600
#define USART_STD_BAUD_19200 				19200
#define USART_STD_BAUD_38400 				38400
#define USART_STD_BAUD_57600 				57600
#define USART_STD_BAUD_115200 				115200
#define USART_STD_BAUD_230400 				230400
#define USART_STD_BAUD_460800 				460800
#define USART_STD_BAUD_921600 				921600
#define USART_STD_BAUD_2M 					2000000
#define SUART_STD_BAUD_3M 					3000000


/*
 *@USART_ParityControl
 *Possible options for USART_ParityControl
 */
#define USART_PARITY_EN_ODD   2
#define USART_PARITY_EN_EVEN  1
#define USART_PARITY_DISABLE   0

/*
 *@USART_WordLength
 *Possible options for USART_WordLength
 */
#define USART_WORDLEN_8BITS  0
#define USART_WORDLEN_9BITS  1

/*
 *@USART_NoOfStopBits
 *Possible options for USART_NoOfStopBits
 */
#define USART_STOPBITS_1     0
#define USART_STOPBITS_0_5   1
#define USART_STOPBITS_2     2
#define USART_STOPBITS_1_5   3

/*
 *@USART_HWFlowControl
 *Possible options for USART_HWFlowControl
 */
#define USART_HW_FLOW_CTRL_NONE    	0
#define USART_HW_FLOW_CTRL_CTS    	1
#define USART_HW_FLOW_CTRL_RTS    	2
#define USART_HW_FLOW_CTRL_CTS_RTS	3



#define ENABLE		1
#define DISABLE 	0

#endif
