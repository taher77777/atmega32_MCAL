/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*****************************************************************/
/******************** CLOCK SELECT *******************************/
/*****************************************************************/

#define CLK_NOSOURSE                              1
#define CLK_DIF_BY_1                              2
#define CLK_DIF_BY_8                              3
#define CLK_DIF_BY_64                             4
#define CLK_DIF_BY_256                            5
#define CLK_DIF_BY_1024                           6
#define CLK_E_S_T0_F_E                            7
#define CLK_DIF_E_S_T0_R_E                        8


/*****************************************************************/
/********************** CTC MODE ********************************/
/*****************************************************************/

#define TIMER2_CTC_OC2_DISCONECTED                1
#define TIMER2_CTC_OC2_TOGGLE                     2
#define TIMER2_CTC_OC2_CLEAR                      3
#define TIMER2_CTC_OC2_SET                        4

/*****************************************************************/
/********************** FAST MODE ********************************/
/*****************************************************************/

#define TIMER2_PWM_F_MODE_OC2_DISCONECTED         1
#define TIMER2_PWM_F_MODE_OC2_C_AT_C_S_AT_T       2
#define TIMER2_PWM_F_MODE_OC2_S_AT_C_C_AT_T       3

/*****************************************************************/
/********************** PHASE MODE *******************************/
/*****************************************************************/

#define TIMER2_PWM_PHASE_MODE_OC2_DISCONECTED                 1
#define TIMER2_PWM_PHASE_MODE_OC2_C_AT_C_UP_S_AT_C_DOWN       2
#define TIMER2_PWM_PHASE_MODE_OC2_S_AT_C_UP_C_AT_C_DOWN       3


#endif
