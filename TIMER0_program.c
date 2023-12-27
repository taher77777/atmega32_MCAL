#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "TIMER0_register.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void) {
	/*choose TIMER0 MODE*/
#if TIMER0_MODE==NORMAL

	/*choose normal mode*/
	CLR_BIT(TCCR0, TCCR0_WGW00);
	CLR_BIT(TCCR0, TCCR0_WGW01);

	/*output normal interrupt enable*/
	SET_BIT(TIMSK, TIMSK_TOIE0);

	/*choose pwm phase correct mode*/
#elif TIMER0_MODE==PWM_Phase_Correct
	SET_BIT(TCCR0,TCCR0_WGW00); CLR_BIT(TCCR0,TCCR0_WGW01);

	/*set OC0 output*/
#if TIMER0_PWM_PH_MODE_OC0 ==TIMER0_PWM_PHASE_MODE_OC0_DISCONECTED
	/*oc0 disconected*/
	CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);
	/*Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.*/
#elif TIMER0_PWM_F_MODE_OC0 ==TIMER0_PWM_PHASE_MODE_OC0_C_AT_C_UP_S_AT_C_DOWN
	CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);
	/*Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting*/
#elif TIMER0_PWM_F_MODE_OC0 ==TIMER0_PWM_PHASE_MODE_OC0_S_AT_C_UP_C_AT_C_DOWN
	SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);
#endif

	/*choose ctc mode*/
#elif TIMER0_MODE==CTC
	CLR_BIT(TCCR0,TCCR0_WGW00); SET_BIT(TCCR0,TCCR0_WGW01);
	/*output compare match interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*set oc0 value */
#if TIMER0_CTC_OC0==TIMER0_CTC_OC0_DISCONECTED

	/*oc0 disconected*/
	CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);
	/*oc0 toggle*/
#elif TIMER0_CTC_OC0==TIMER0_CTC_OC0_TOGGLE
	SET_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);
	/*oc0 clear*/
#elif TIMER0_CTC_OC0==TIMER0_CTC_OC0_CLEAR
	CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);
	/*oc0 set*/
#elif TIMER0_CTC_OC0==TIMER0_CTC_OC0_SET
	SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);
#endif

	/*choose pwm fast mode*/
#elif TIMER0_MODE==PWM_FAST_MODE
	SET_BIT(TCCR0, TCCR0_WGW00);
	SET_BIT(TCCR0, TCCR0_WGW01);

	/*set OC0 output*/
#if TIMER0_PWM_F_MODE_OC0==TIMER0_PWM_F_MODE_OC0_DISCONECTED
	/*oc0 disconected*/
	CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);
	/*Clear OC0 on compare match, set OC0 at TOP*/
#elif TIMER0_PWM_F_MODE_OC0==TIMER0_PWM_F_MODE_OC0_C_AT_C_S_AT_T
	CLR_BIT(TCCR0, TCCR0_COM00);SET_BIT(TCCR0, TCCR0_COM01);
	/*Set OC0 on compare match, clear OC0 at TOP*/
#elif TIMER0_PWM_F_MODE_OC0==TIMER0_PWM_F_MODE_OC0_S_AT_C_C_AT_T
	SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);
#endif

#endif

}

u8 TIMER0_u8SetCallback(void (*Copy_pvCallBackFunc)(void)) {
	u8 Local_u8ErrorStatus = OK;
	if (Copy_pvCallBackFunc != NULL) {
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	} else {
		Local_u8ErrorStatus = NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

/*set preload value*/
void TIMER0_voidSetPreLoadValue(u32 TIMER0_u32PreValue) {
	TCNT0 = TIMER0_u32PreValue;
}
u8 TIMER0_u8GetRgisterValue(void) {
	return TCNT0;
}

void TIMER0_voidStart(void) {
	/*prescaler*/

#if TIMER0_CLK_PRE==CLK_NOSOURSE
	/*no source*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
#elif TIMER0_CLK_PRE==CLK_DIF_BY_1
	/*df1*/
	SET_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
#elif TIMER0_CLK_PRE==CLK_DIF_BY_8
	/*df8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
#elif TIMER0_CLK_PRE==CLK_DIF_BY_64
	/*df64*/
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
#elif TIMER0_CLK_PRE==CLK_DIF_BY_256
	/*df256*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);
#elif TIMER0_CLK_PRE==CLK_DIF_BY_1024
	/*df1024*/
	SET_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);
#elif TIMER0_CLK_PRE==CLK_E_S_T0_F_E
	/*External clock source on T0 pin. Clock on falling edge*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);
#elif TIMER0_CLK_PRE==CLK_DIF_E_S_T0_R_E
	/*External clock source on T0 pin. Clock on raising edge*/
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);
#endif
}
void TIMER0_voidStop(void) {
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);CLR_BIT(TCCR0, TCCR0_CS02);
} /*SET OCR0 Value*/
void TIMER0_voidSetOCR0Value(u32 TIMER0_u32OCR0Value) {
	/*compare match value ocr0*/
	OCR0 = TIMER0_u32OCR0Value;
}

/*delay with CTC mode*/
u32 TIMER0_void_Delay_ms_CTCMode(u32 Timer0_u32Count) {
	u32 LocalCounter = 0;
	/*prescaler*/
	switch (TIMER0_CLK_PRE) {
	/*no source*/
	case 0:
		LocalCounter = 0;
		break;
		/*df1*/
	case 1:
		LocalCounter =
				(((f32) Timer0_u32Count)
						/ ((f32) ((f32) OCR0 + (f32) 1)
								* (f32) ((f32) 1 / (f32) CLK_K)));
		break;
		/*df8*/
	case 2:
		LocalCounter =
				(((f32) Timer0_u32Count)
						/ ((f32) ((f32) OCR0 + (f32) 1)
								* (f32) ((f32) 8 / (f32) CLK_K)));
		break;
		/*df64*/
	case 3:
		LocalCounter =
				(((f32) Timer0_u32Count)
						/ ((f32) ((f32) OCR0 + (f32) 1)
								* (f32) ((f32) 64 / (f32) CLK_K)));
		break;
		/*df256*/
	case 4:
		LocalCounter = (((f32) Timer0_u32Count)
				/ ((f32) ((f32) OCR0 + (f32) 1)
						* (f32) ((f32) 256 / (f32) CLK_K)));
		break;
		/*df1024*/
	case 5:
		LocalCounter = (((f32) Timer0_u32Count)
				/ ((f32) ((f32) OCR0 + (f32) 1)
						* (f32) ((f32) 1024 / (f32) CLK_K)));
		break;
		/*no source*/
	default:
		break;
	}
	return LocalCounter;
}

void TIMER0_voidSetDyty(u8 Dyty) {
	if (Dyty <= 100) {
#if TIMER0_MODE==PWM_FAST_MODE
#if TIMER0_PWM_F_MODE_OC0 == TIMER0_PWM_F_MODE_OC0_C_AT_C_S_AT_T
		OCR0 = (((u16) Dyty * 256) / 100) - 1;
#elif TIMER0_PWM_F_MODE_OC0 == TIMER0_PWM_F_MODE_OC0_S_AT_C_C_AT_T
		Dyty = 100 - Dyty;
		OCR0 = (((u16)Dyty*256)/100)-1;
#endif
#elif TIMER0_MODE==PWM_Phase_Correct
#if TIMER0_PWM_PH_MODE_OC0 == TIMER0_PWM_PHASE_MODE_OC0_C_AT_C_UP_S_AT_C_DOWN
		OCR0 = (((u16)Dyty*256)/100)-1;
#elif TIMER0_PWM_PH_MODE_OC0 == TIMER0_PWM_PHASE_MODE_OC0_S_AT_C_UP_C_AT_C_DOWN
		Dyty = 100 - Dyty;
		OCR0 = (((u16)Dyty*256)/100)-1;
#endif
#endif

	} else {
		return;
	}
}

/*ISR OVERflow MODE*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void) {
	if (TIMER0_pvCallBackFunc != NULL) {
		TIMER0_pvCallBackFunc();
	}

}
/*ISR CTC MODE*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void) {
	if (TIMER0_pvCallBackFunc != NULL) {
		TIMER0_pvCallBackFunc();
	}

}
