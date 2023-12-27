#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "TIMER2_register.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"

static void (*TIMER2_pvCallBackFunc)(void)=NULL;

void TIMER2_voidInit(void)
{
	/*choose TIMER2 MODE*/ 
#if TIMER2_MODE==NORMAL
		/*choose normal mode*/
		 CLR_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21);
		/*output normal interrupt enable*/
		SET_BIT(TIMSK,TIMSK_TOIE2);

		/*choose pwm phase correct mode*/
#elif TIMER2_MODE==PWM_Phase_Correct
		SET_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21);
			/*set OC2 output*/
#if TIMER2_PWM_PH_MODE_OC2==TIMER2_PWM_PHASE_MODE_OC2_DISCONECTED
			/*OC2 disconected*/
			CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);
			/*Clear OC2 on compare match when up-counting. Set OC2 on compare match when downcounting.*/
#elif TIMER2_PWM_PH_MODE_OC2==TIMER2_PWM_PHASE_MODE_OC2_C_AT_C_UP_S_AT_C_DOWN
			CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);
			/*Set OC2 on compare match when up-counting. Clear OC2 on compare match when downcounting*/
#elif TIMER2_PWM_PH_MODE_OC2==TIMER2_PWM_PHASE_MODE_OC2_S_AT_C_UP_C_AT_C_DOWN
			SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);

#endif
		
		/*choose ctc mode*/
#elif TIMER2_MODE==CTC
		CLR_BIT(TCCR2,TCCR2_WGM20); SET_BIT(TCCR2,TCCR2_WGM21);
		/*output compare match interrupt enable*/
		SET_BIT(TIMSK,TIMSK_OCIE2);
		/*set OC2 value */
#if TIMER2_CTC_OC2==TIMER2_CTC_OC2_DISCONECTED
		/*OC2 disconected*/
		CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);
		/*OC2 toggle*/
#elif TIMER2_CTC_OC2==TIMER2_CTC_OC2_TOGGLE
		SET_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);
		/*OC2 clear*/
#elif TIMER2_CTC_OC2==TIMER2_CTC_OC2_CLEAR
		CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);
		/*OC2 set*/
#elif TIMER2_CTC_OC2==TIMER2_CTC_OC2_SET
		SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);
#endif
				
				
		/*choose pwm fast mode*/
#elif TIMER2_MODE==PWM_FAST_MODE
		 SET_BIT(TCCR2,TCCR2_WGM20); SET_BIT(TCCR2,TCCR2_WGM21);
		/*set OC2 output*/
#if TIMER2_PWM_F_MODE_OC2==TIMER2_PWM_F_MODE_OC2_DISCONECTED
		/*OC2 disconected*/
		 CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);
		/*Clear OC2 on compare match, set OC2 at TOP*/
#elif TIMER2_PWM_F_MODE_OC2==TIMER2_PWM_F_MODE_OC2_C_AT_C_S_AT_T
		 CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);
		/*Set OC2 on compare match, clear OC2 at TOP*/
#elif TIMER2_PWM_F_MODE_OC2==TIMER2_PWM_F_MODE_OC2_C_AT_C_S_AT_T
		 SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);
#endif
		
#endif

}

u8 TIMER2_u8SetCallback(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvCallBackFunc!=NULL)
	{
		TIMER2_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else 
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	
	return Local_u8ErrorStatus;
}

		/*set preload value*/
void TIMER2_voidSetPreLoadValue (u32 TIMER2_u32PreValue)
{
	TCNT2=TIMER2_u32PreValue;
}
u8 TIMER2_u8GetRgisterValue(void)
{
	return TCNT2;
}
void TIMER2_voidDisable()
{
	CLR_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);
}
		/*SET OCR2 Value*/
void TIMER2_voidSetOCR2Value(u32 TIMER2_u32OCR2Value)
{
		/*compare match value ocr0*/
	OCR2=TIMER2_u32OCR2Value;
}

void TIMER2_voidStart(void)
{
	/*prescaler*/
#if TIMER2_CLK_PRE==CLK_NOSOURSE
		/*no source*/
		CLR_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);
		/*df1*/
#elif TIMER2_CLK_PRE==CLK_DIF_BY_1
		SET_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);
		/*df8*/
#elif TIMER2_CLK_PRE==CLK_DIF_BY_8
		CLR_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);
		/*df64*/
#elif TIMER2_CLK_PRE==CLK_DIF_BY_64
		SET_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);
		/*df256*/
#elif TIMER2_CLK_PRE==CLK_DIF_BY_256
		CLR_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);
		/*df1024*/
#elif TIMER2_CLK_PRE==CLK_DIF_BY_1024
		SET_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);
		/*External clock source on T0 pin. Clock on falling edge*/
#elif TIMER2_CLK_PRE==CLK_E_S_T0_F_E
		CLR_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);
		/*External clock source on T0 pin. Clock on raising edge*/
#elif TIMER2_CLK_PRE==CLK_DIF_E_S_T0_R_E
		SET_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);
#endif

}
void TIMER2_voidStop(void)
{
	CLR_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);
}
		
void TIMER2_voidSetDyty(u8 Dyty)
{
	if (Dyty <= 100) {
#if TIMER2_MODE==PWM_FAST_MODE
#if TIMER2_PWM_F_MODE_OC2 == TIMER2_PWM_F_MODE_OC2_C_AT_C_S_AT_T
		OCR2 = (((u16) Dyty * 256) / 100) - 1;
#elif TIMER2_PWM_F_MODE_OC2 == TIMER2_PWM_F_MODE_OC2_S_AT_C_C_AT_T
		Dyty = 100 - Dyty;
		OCR2 = (((u16)Dyty*256)/100)-1;
#endif
#elif TIMER2_MODE==PWM_Phase_Correct
#if TIMER2_PWM_PH_MODE_OC2 == TIMER2_PWM_PHASE_MODE_OC2_C_AT_C_UP_S_AT_C_DOWN
		OCR2 = (((u16)Dyty*256)/100)-1;
#elif TIMER2_PWM_PH_MODE_OC2 == TIMER2_PWM_PHASE_MODE_OC2_S_AT_C_UP_C_AT_C_DOWN
		Dyty = 100 - Dyty;
		OCR2 = (((u16)Dyty*256)/100)-1;
#endif
#endif

	} else {
		return;
	}
}

u32 TIMER2_void_Delay_ms_CTCMode(u32 Timer2_u32Count)
{
	u32 LocalCounter = 0;
	/*prescaler*/
	switch (TIMER2_CLK_PRE) {
	/*no source*/
	case 0:
		LocalCounter = 0;
		break;
		/*df1*/
	case 1:
		LocalCounter =
				(((f32) Timer2_u32Count)
						/ ((f32) ((f32) OCR2 + (f32) 1)
								* (f32) ((f32) 1 / (f32) CLK_K)));
		break;
		/*df8*/
	case 2:
		LocalCounter =
				(((f32) Timer2_u32Count)
						/ ((f32) ((f32) OCR2 + (f32) 1)
								* (f32) ((f32) 8 / (f32) CLK_K)));
		break;
		/*df64*/
	case 3:
		LocalCounter =
				(((f32) Timer2_u32Count)
						/ ((f32) ((f32) OCR2 + (f32) 1)
								* (f32) ((f32) 64 / (f32) CLK_K)));
		break;
		/*df256*/
	case 4:
		LocalCounter = (((f32) Timer2_u32Count)
				/ ((f32) ((f32) OCR2 + (f32) 1)
						* (f32) ((f32) 256 / (f32) CLK_K)));
		break;
		/*df1024*/
	case 5:
		LocalCounter = (((f32) Timer2_u32Count)
				/ ((f32) ((f32) OCR2 + (f32) 1)
						* (f32) ((f32) 1024 / (f32) CLK_K)));
		break;
		/*no source*/
	default:
		break;
	}
	return LocalCounter;
}


/*ISR OVERflow MODE*/
void __vector_5(void) __attribute__((signal));
void __vector_5(void) 
{
	if (TIMER2_pvCallBackFunc!=NULL)
	{
		TIMER2_pvCallBackFunc();
	}

}
/*ISR CTC MODE*/
void __vector_4(void) __attribute__((signal));
void __vector_4(void) 
{
	if (TIMER2_pvCallBackFunc!=NULL)
	{
		TIMER2_pvCallBackFunc();
	}

}
