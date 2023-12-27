/*****************************************************************/
/*****************************************************************/
/********************		Author: Taher Mohamed	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 5-9-2020			**************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"

static u8* ADC_pu8Reading= NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;

u8 ADC_u8BusyState= IDLE;

void ADC_voidInit(void)
{
	/* reference voltage*/
	switch (ADC_u8RefVolt)
	{
		case ADC_AREF_REF:CLR_BIT(ADMUX,ADMUX_REFS0);CLR_BIT(ADMUX,ADMUX_REFS1);break;
		case ADC_AVCC_REF:SET_BIT(ADMUX,ADMUX_REFS0);CLR_BIT(ADMUX,ADMUX_REFS1);break;
		case ADC_Internal_REF:SET_BIT(ADMUX,ADMUX_REFS1);SET_BIT(ADMUX,ADMUX_REFS0);break;
	}
	

	/*Left adjust result*/
	if (Left_adjust==Enable)
	{
		SET_BIT(ADMUX,ADMUX_ADLAR);
	}
	else 
	{
		CLR_BIT(ADMUX,ADMUX_ADLAR);
	}

	/*Set Prescaler to */
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	ADCSRA|=ADC_u8Prescaler;

	/*Enable peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=OK;
	if (ADC_u8BusyState == IDLE)
	{
		/*ADC is now busy*/
		ADC_u8BusyState= BUSY;

		/*Clear the MUX bits in ADMUX register*/
		ADMUX &= 0b11100000;

		/*Set the required channel into the MUX bits*/
		ADMUX|= Copy_u8Channel;

		/*Start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set or counter reaching timeout value*/
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0)  && (Local_u32Counter != ADC_u32TIMEOUT ) )
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter== ADC_u32TIMEOUT)
		{
			/*Loop is broken because the timeout is reached*/
			Local_u8ErrorState=NOK;
		}
		else
		{
			/* Loop is broken because flag is raised */
			/*clear the conversion complete flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			/*Return the reading*/
			*Copy_pu8Reading=ADCH;

			/*ADC is finished, return it to IDLE*/
			ADC_u8BusyState= IDLE;
		}
	}
		else
		{
			Local_u8ErrorState= BUSY_FUNC;
		}

	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_uErrorState=OK;
	if(ADC_u8BusyState== IDLE)
	{
		if((Copy_pu8Reading ==NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_uErrorState= NULL_POINTER;
		}
		else
		{
			/*make ADC busy in order not to work until being idle*/
			ADC_u8BusyState= BUSY;

			/*Initialize the reading variable globally*/
			ADC_pu8Reading = Copy_pu8Reading;

			/*Initialize the callback notification function globally*/
			ADC_pvCallBackNotificationFunc= Copy_pvNotificationFunc;

			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= 0b11100000;

			/*Set the required channel into the MUX bits*/
			ADMUX|= Copy_u8Channel;

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		Local_uErrorState= BUSY_FUNC;
	}

	return Local_uErrorState;
}

void ADC_Lm35(u8 Copy_u8Channel,u8* Copy_pu8Reading)
{
	u16 milivolt;
	 ADC_u8StartConversionSynch(Copy_u8Channel,&Copy_pu8Reading);
	 milivolt=(u16)((u32)*Copy_pu8Reading*5000UL)/256UL;
	 *Copy_pu8Reading=(milivolt/10);
}
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	/*Read ADC result*/
	*ADC_pu8Reading= ADCH;

	/*Make ADC state be IDLE because it finished*/
	ADC_u8BusyState=IDLE;

	/*Invoke the callback notification function*/
	ADC_pvCallBackNotificationFunc();

	/*Disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}


