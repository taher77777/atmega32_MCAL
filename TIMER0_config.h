/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
//clock source
#define CLK_K    8000

//Waveform Generation Mode

#define NORMAL   			1
#define PWM_Phase_Correct	2
#define CTC					3
#define PWM_FAST_MODE		4
#define TIMER0_MODE         PWM_FAST_MODE

//clock select

	/*
		no_source :   CLK_NOSOURSE
		normal	  :   CLK_DIF_BY_1
		clock/8   :   CLK_DIF_BY_8
		clock/64  :   CLK_DIF_BY_64
		clock/256 :   CLK_DIF_BY_256
		clock/1024:   CLK_DIF_BY_1024
		E_S_T0_F_E:   CLK_E_S_T0_F_E    		External clock source on T0 pin. Clock on falling edge
		E_S_T0_R_E:   CLK_DIF_E_S_T0_R_E		External clock source on T0 pin. Clock on raising edge
						*/
#define TIMER0_CLK_PRE      CLK_DIF_BY_8

/*ctc outbut oc0*/

	/* 
		oc0 disconected  TIMER0_CTC_OC0_DISCONECTED
		oc0 toggle       TIMER0_CTC_OC0_TOGGLE
		oc0 clear        TIMER0_CTC_OC0_CLEAR
		oc0 set          TIMER0_CTC_OC0_SET
							                          */

#define TIMER0_CTC_OC0   TIMER0_CTC_OC0_disconected

/*pwm FAST Mode*/

   /*
		oc0 disconected  								TIMER0_PWM_F_MODE_OC0_DISCONECTED
		Clear OC0 on compare match, set OC0 at TOP      TIMER0_PWM_F_MODE_OC0_C_AT_C_S_AT_T
		set OC0 on compare match, clear OC0 at TOP		TIMER0_PWM_F_MODE_OC0_S_AT_C_C_AT_T
															                                  */
#define TIMER0_PWM_F_MODE_OC0   TIMER0_PWM_F_MODE_OC0_C_AT_C_S_AT_T

/*Phase Correct PWM Mode*/

   /*
		oc0 disconected  																			TIMER0_PWM_PHASE_MODE_OC0_DISCONECTED
		Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting     TIMER0_PWM_PHASE_MODE_OC0_C_AT_C_UP_S_AT_C_DOWN
		Set OC0 on compare match when up-counting. Clear OC0 on comparematch when downcounting		TIMER0_PWM_PHASE_MODE_OC0_S_AT_C_UP_C_AT_C_DOWN
															*/
#define TIMER0_PWM_PH_MODE_OC0   TIMER0_PWM_PHASE_MODE_OC0_C_AT_C_UP_S_AT_C_DOWN
											
 

#endif
