/*****************************************************************/
/*****************************************************************/
/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: ADC				**************/
/********************		Version: 1.00			**************/
/********************		Date: 5-9-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define IDLE		0
#define BUSY		1

#define Enable      2
#define Disable     3

/*type of reference voltage */
#define ADC_AREF_REF        1
#define ADC_AVCC_REF        2
#define ADC_Internal_REF    3

/*Prescaler*/
#define DF2                 1
#define DF4	                2
#define DF8                 3
#define DF16                4
#define DF32                5
#define DF64                6
#define DF128               7
#endif
