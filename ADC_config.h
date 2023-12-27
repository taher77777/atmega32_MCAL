/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 5-9-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define ADC_u32TIMEOUT		50000

/*
Left adjust
           1-Enable
		   2-Disable
                    */
#define Left_adjust Enable

/*
reference voltage
			1-ADC_AREF_REF
			2-ADC_AVCC_REF
			3-ADC_Internal_REF
*/
#define ADC_u8RefVolt     ADC_AVCC_REF

/*
Prescaler 
		1-DF2
		2-DF4
		3-DF8
		4-DF16
		5-DF32
		6-DF64
		7-DF128
*/
#define ADC_u8Prescaler  DF128

#endif
