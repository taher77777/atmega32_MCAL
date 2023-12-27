/*
 * WDTM_interface.h
 *
 *  Created on: Nov 13, 2023
 *      Author: ELBOSTAN
 */

#ifndef WDTM_INTERFACE_H_
#define WDTM_INTERFACE_H_

#define WDTM_TIMER_16_3_MS          1
#define WDTM_TIMER_32_5_MS          2
#define WDTM_TIMER_65_MS            3
#define WDTM_TIMER_0_13_S           4
#define WDTM_TIMER_0_26_S           5
#define WDTM_TIMER_0_52_S           6
#define WDTM_TIMER_0_1_S            7
#define WDTM_TIMER_2_1_S            8
void WDTM_voidEnable(u8 WDTM_delay);
void WDTM_voidDisable(void);
#endif /* WDTM_INTERFACE_H_ */
