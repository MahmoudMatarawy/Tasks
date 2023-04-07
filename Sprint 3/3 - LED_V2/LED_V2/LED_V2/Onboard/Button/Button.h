#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <stdint.h>
// Create ButtonID ENUM
typedef uint8_t Button_IdType;

#define Button_Start			((Button_IdType)0x00)
//#define Button_Stop				(ButtonID(0x01))



// Create Button State ENUM
typedef uint8_t Button_StateType;

#define BT_PRE_PUSH				((Button_StateType)0x00)
#define BT_PUSHED				((Button_StateType)0x01)
#define BT_PRE_HOLD				((Button_StateType)0x02)
#define BT_HOLD					((Button_StateType)0x03)
#define BT_PRE_RELEASE			((Button_StateType)0x04)
#define BT_RELEASED				((Button_StateType)0x05)
#define BT_UNDEFINED			((Button_StateType)0x06) 


void button_Main_Task(void);
void button_Init(void);
Button_StateType getButtonState(Button_IdType enmButtonId);




#endif  /* BUTTON_H */