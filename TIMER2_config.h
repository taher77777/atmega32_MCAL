/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER2				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

#define CLK_K  8000
//Waveform Generation Mode

#define NORMAL   			1
#define PWM_Phase_Correct	2
#define CTC					3
#define PWM_FAST_MODE		4
#define TIMER2_MODE         PWM_FAST_MODE

//clock select

	/*
		no_source :  CLK_NOSOURSE
		normal	  :  CLK_DIF_BY_1
		clock/8   :  CLK_DIF_BY_8
		clock/64  :  CLK_DIF_BY_64
		clock/256 :  CLK_DIF_BY_256
		clock/1024:  CLK_DIF_BY_1024
		E_S_T0_F_E:  CLK_E_S_T0_F_E    		External clock source on T0 pin. Clock on falling edge
		E_S_T0_R_E:  CLK_DIF_E_S_T0_R_E		External clock source on T0 pin. Clock on raising edge
						*/
#define TIMER2_CLK_PRE      CLK_DIF_BY_8

/*ctc outbut oc2*/

	/* 
		oc2 disconected TIMER2_CTC_OC2_DISCONECTED
		oc2 toggle      TIMER2_CTC_OC2_TOGGLE
		oc2 clear       TIMER2_CTC_OC2_CLEAR
		oc2 set         TIMER2_CTC_OC2_SET
							*/

#define TIMER2_CTC_OC2   TIMER2_CTC_OC2_DISCONECTED

/*pwm FAST Mode*/

   /*
		oc2 disconected  								TIMER2_PWM_F_MODE_OC2_DISCONECTED
		Clear oc2 on compare match, set oc2 at TOP      TIMER2_PWM_F_MODE_OC2_C_AT_C_S_AT_T
		set oc2 on compare match, clear oc2 at TOP		TIMER2_PWM_F_MODE_OC2_S_AT_C_C_AT_T
															*/
#define TIMER2_PWM_F_MODE_OC2   TIMER2_PWM_F_MODE_OC2_C_AT_C_S_AT_T

/*Phase Correct PWM Mode*/

   /*
		oc2 disconected  																			TIMER2_PWM_PHASE_MODE_OC2_DISCONECTED
		Clear oc2 on compare match when up-counting. Set oc2 on compare match when downcounting     TIMER2_PWM_PHASE_MODE_OC2_C_AT_C_UP_S_AT_C_DOWN
		Set oc2 on compare match when up-counting. Clear oc2 on comparematch when downcounting		TIMER2_PWM_PHASE_MODE_OC2_S_AT_C_UP_C_AT_C_DOWN
															*/
#define TIMER2_PWM_PH_MODE_OC2   TIMER2_PWM_PHASE_MODE_OC2_S_AT_C_UP_C_AT_C_DOWN
											
 

#endif
