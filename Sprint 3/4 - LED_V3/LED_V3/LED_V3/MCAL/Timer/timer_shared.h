/*
 * timer_shared.h
 *
 * Created: 4/7/2023 5:01:19 AM
 *  Author: engma
 */ 


#ifndef TIMER_SHARED_H_
#define TIMER_SHARED_H_

// Timers Errors Enum
typedef enum 
{
	Timer_E_OK = 0,
	Timer_E_TRANSITION,
	Timer_E_PARAM_POINTER,
	Timer_E_INIT_FAILED,
	Timer_E_InvalidValue
}en_timer_Errors_t;



typedef enum
{
	Timer_0 = 0,
	Timer_1,
	Timer_2
}en_timer_Number_t;






#endif /* TIMER_SHARED_H_ */