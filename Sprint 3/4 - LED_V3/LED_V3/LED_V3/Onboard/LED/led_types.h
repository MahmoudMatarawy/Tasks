#ifndef _LED_TYPES_H_
#define _LED_TYPES_H_

#include "../../MCAL/DIO/DIO.h"
#include "led.h"










typedef struct
{
	Dio_ChannelType LED_CHANNEL_ID;
	LED_STATE_type LED_STATE;
}LED_Config_Type;


#endif	/* LED_TYPES_H	*/