#ifndef _DIO_H_
#define _DIO_H_

#include "DIO_Config.h"

#define DIO_MAX_PINS	32
#define DIO_MAX_PORTS	4

// DIO Errors Enum
typedef enum
{
	DIO_E_OK = 0,
	DIO_InvalidPin,
	DIO_InvalidPort
}en_dio_Errors_t;



// DIO Level type ENUM
typedef enum
{
	STD_LOW = 0,
	STD_HIGH
}en_dio_Level_t;


// DIO DIR type ENUM
typedef enum
{
	STD_INPUT = 0,
	STD_OUTPUT
}en_dio_DIR_t;

en_dio_Errors_t DIO_ChannelSetDIR(en_dio_channel_t ChannelId, en_dio_DIR_t dir);

en_dio_Errors_t DIO_ReadChannel(en_dio_channel_t ChannelId ,en_dio_Level_t* level);
en_dio_Errors_t DIO_WriteChannel(en_dio_channel_t ChannelId, en_dio_Level_t level);




#endif /* DIO_H */