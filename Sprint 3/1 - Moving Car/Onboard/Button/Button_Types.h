#ifndef _BUTTON_TYPES_H_
#define _BUTTON_TYPES_H_


#define BUTTONS_NUM			2U

// Create ButtonID ENUM
typedef uint8_t Button_IdType;

#define Button_Start			(ButtonID(0x00))
#define Button_Stop				(ButtonID(0x01))



// Create Button State ENUM
typedef uint8_t Button_StateType;

#define BT_PRE_PUSH				(Button_StateType(0x00))
#define BT_PUSHED				(Button_StateType(0x01))
#define BT_PRE_HOLD				(Button_StateType(0x02))	
#define BT_HOLD					(Button_StateType(0x03))	
#define BT_PRE_RELEASE			(Button_StateType(0x04))	
#define BT_RELEASED				(Button_StateType(0x05))	
#define BT_UNDEFINED			(Button_StateType(0x06))



// Create Button Level ENUM	
typedef uint8_t Button_LevelType;

#define BT_PUSH_LEVEL				(Button_LevelType(0x00))
#define BT_RELEASE_LEVEL	        (Button_LevelType(0x01))


typedef struct
{
	Dio_ChannelType ChannelId;
	uint8_t u8DebounceThreshold;
	uint8_t u8HoldThreshold;
}Button_configType;






#endif  /* BUTTON_TYPES_H */