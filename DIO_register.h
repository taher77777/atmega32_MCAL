/***********************************************************************/
/***********************************************************************/
/*****************    AUTHOR: TAHER MOHAMED   **************************/
/*****************    LAYER:  MCAL            **************************/
/*****************    SWC:    DIO             **************************/
/*****************    VERSION:1.00            **************************/
/***********************************************************************/
/***********************************************************************/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA      *((volatile u8*)0x3b)
#define PINA       *((volatile u8*)0x39)

#define PORTB      *((volatile u8*)0x38)
#define PINB       *((volatile u8*)0x36)

#define PORTC      *((volatile u8*)0x35)
#define PINC       *((volatile u8*)0x33)

#define PORTD      *((volatile u8*)0x32)
#define PIND       *((volatile u8*)0x30)
#define DDRA *((u8 *) 0x3A)
#define DDRB *((u8 *) 0x37)
#define DDRC *((u8 *) 0x34)
#define DDRD *((u8 *) 0x31)


#endif
