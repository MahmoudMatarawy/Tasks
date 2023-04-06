#ifndef _LED_TYPES_H_
#define _LED_TYPES_H_

#include "../../MCAL/DIO/DIO.h"

// Create LED state ENUM
typedef uint8_t LED_STATE_type;

#define LED_OFF		((LED_STATE)0x00)
#define LED_ON		((LED_STATE)0x01)



// Create LED ID ENUM
typedef uint8_t LED_ID_type;

#define LED_1		((LED_ID_type)0x00)
#define LED_2		((LED_ID_type)0x01)
#define LED_3		((LED_ID_type)0x02)
#define	LED_4		((LED_ID_type)0x03)



typedef struct
{
	Dio_ChannelType LED_CHANNEL_ID;
	LED_STATE_type LED_STATE;
}LED_Config_Type;


#endif	/* LED_TYPES_H	*/