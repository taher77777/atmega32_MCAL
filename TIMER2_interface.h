/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER2				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

void TIMER2_voidInit(void);
u8 TIMER2_u8SetCallBack(void (*copy_pvCallBackFunc)(void));
void TIMER2_voidSetPreLoadValue (u32 TIMER2_u32PreValue);
u8 TIMER2_u8GetRgisterValue(void);
void TIMER2_voidDisable();
void TIMER2_voidSetOCR2Value(u32 TIMER2_u32OCR2Value);

void TIMER2_voidStart(void);
void TIMER2_voidStop(void);
u32 TIMER2_void_Delay_ms_CTCMode(u32 Timer0_u32Count);
void TIMER2_voidSetDyty(u8 Dyty);

#endif
