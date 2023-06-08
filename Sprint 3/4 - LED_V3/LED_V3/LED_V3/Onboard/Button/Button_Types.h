#ifndef _BUTTON_TYPES_H_
#define _BUTTON_TYPES_H_

#include "../../MCAL/DIO/DIO_Config.h"






// Create Button Level ENUM	
typedef uint8_t Button_LevelType;

#define BT_PUSH_LEVEL				((Button_LevelType)0x00)
#define BT_RELEASE_LEVEL	        ((Button_LevelType)0x01)


typedef struct{
	en_dio_channel_t ChannelId;
	uint8_t u8DebounceThreshold;
	uint8_t u8HoldThreshold;
	uint8_t eXt_INT;
}Button_configType;






#endif  /* BUTTON_TYPES_H */