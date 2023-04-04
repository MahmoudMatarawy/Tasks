


#ifndef _TIMER_H_
#define _TIMER_H_

#include "Timer_config.h"


#define Max_Timer_Numbers 3

// Timer_0 8bit  max_capacity = 256 ,
// Timer_1 16bit max_capacity = 65536 , 
// Timer_3 8bit  max_capacity = 256
const uint16_t Timers_Capacity[Max_Timer_Numbers] = {256,65536,256}; 

// Timer Config Structure
typedef struct {
	Timer_Number timer_num;
	uint8_t mode;
	uint8_t com[2];
	uint16_t clock_select;
	uint8_t com_interrupt_enable[2];
	uint8_t overflow_interrupt_enable;	
}Timer_configType;

// Timer Status Enum
typedef uint8_t Timer_Status;

#define Timer_S_Ready			((Timer_Status)0x00)
#define Timer_S_UnInit			((Timer_Status)0x01)


// Timers Errors Enum
typedef uint8_t Timer_Errors;		

#define Timer_E_OK				((Timer_Errors)0x00)
#define Timer_E_TRANSITION		((Timer_Errors)0x01)
#define Timer_E_PARAM_POINTER	((Timer_Errors)0x02)
#define Timer_E_INIT_FAILED		((Timer_Errors)0x03)
#define Timer_E_InvalidValue	((Timer_Errors)0x04)



Timer_Errors Timer_Init(Timer_configType* config);
Timer_Errors Timer_Set(Timer_Number Timer_Num , uint16_t Timer_value);
Timer_Errors Timer_DeInit(Timer_Number Timer_Num);



#endif /* TIMER_H */