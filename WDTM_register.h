/*
 * WDTM_register.h
 *
 *  Created on: Nov 13, 2023
 *      Author: ELBOSTAN
 */

#ifndef WDTM_REGISTER_H_
#define WDTM_REGISTER_H_

#define WDTCR        *((volatile u8*)0x41)
#define WDTCR_WDTOE  4
#define WDTCR_WDE    3
#define WDTCR_WDP2	 2
#define WDTCR_WDP1	 1
#define WDTCR_WDP0	 0
#endif /* WDTM_REGISTER_H_ */
