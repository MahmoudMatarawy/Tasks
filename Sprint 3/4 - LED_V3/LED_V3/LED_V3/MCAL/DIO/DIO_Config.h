#ifndef _DIO_CONFIG_H_
#define _DIO_CONFIG_H_

#include <stdint.h>


#define PORTA_CHANNELS			8
#define PORTB_CHANNELS			8
#define PORTC_CHANNELS			8
#define PORTD_CHANNELS			8


// DIO channel type ENUM
typedef enum
{
	DIO_PORTA_Channel0 = 0,
	DIO_PORTA_Channel1,
	DIO_PORTA_Channel2,
	DIO_PORTA_Channel3,
	DIO_PORTA_Channel4,
	DIO_PORTA_Channel5,
	DIO_PORTA_Channel6,
	DIO_PORTA_Channel7,
	
	DIO_PORTB_Channel0,
	DIO_PORTB_Channel1,
	DIO_PORTB_Channel2,
	DIO_PORTB_Channel3,
	DIO_PORTB_Channel4,
	DIO_PORTB_Channel5,
	DIO_PORTB_Channel6,
	DIO_PORTB_Channel7,
	
	DIO_PORTC_Channel0,
	DIO_PORTC_Channel1,
	DIO_PORTC_Channel2,
	DIO_PORTC_Channel3,
	DIO_PORTC_Channel4,
	DIO_PORTC_Channel5,
	DIO_PORTC_Channel6,
	DIO_PORTC_Channel7,
	
	DIO_PORTD_Channel0,
	DIO_PORTD_Channel1,
	DIO_PORTD_Channel2,
	DIO_PORTD_Channel3,
	DIO_PORTD_Channel4,
	DIO_PORTD_Channel5,
	DIO_PORTD_Channel6,
	DIO_PORTD_Channel7

}en_dio_channel_t;




// DIO port type ENUM
typedef uint8_t Dio_PortType;

#define PortA			(Dio_PortType(0x00))
#define PortB			(Dio_PortType(0x01))
#define PortC			(Dio_PortType(0x02))
#define PortD			(Dio_PortType(0x03))



#endif /* DIO_CONFIG_H */