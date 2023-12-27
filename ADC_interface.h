/*****************************************************************/
/*****************************************************************/
/********************		Author: TAHER MOHAMED   **************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 5-9-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading);

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void));

void ADC_Lm35(u8 Copy_u8Channel,u8* Copy_pu8Reading);

#define ADC_A0        0
#define ADC_A1        1
#define ADC_A2        2
#define ADC_A3        3
#define ADC_A4        4
#define ADC_A5        5
#define ADC_A6        6
#define ADC_A7        7

#endif
