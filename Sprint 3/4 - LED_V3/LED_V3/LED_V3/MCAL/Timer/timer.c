#include "timer.h"
#include "Timer_Reg.h"
#include "timer_app.h"
#include <avr/interrupt.h>


uint8_t Timers_status[Max_Timer_Numbers];

en_timer_Errors_t Timer_Init(en_timer_Number_t Timer_Num)
{
	en_timer_Errors_t en_timer_Errors = Timer_E_OK;
		if (Timer_Num >= Max_Timer_Numbers)
		{
			en_timer_Errors = Timer_E_InvalidValue;
		}
		else
		{
			if (Timers_status[Timer_Num] == Timer_S_Ready)
			{
				en_timer_Errors = Timer_E_TRANSITION;
			}
			else
			{
				switch(Timer_Num)
				{
					case Timer_0 :
					{
									TIMER_0_CONTROL_REG |= (1U << TIMER_0_CLOCK_SELECT_BIT_0);
									TIMER_INTERRUPT_MASK_REG |= (1U << TIMER_0_OVERFLOW_INTERRUPT_ENABLE);
									Timers_status[Timer_Num] = Timer_S_Ready;
									break;
					}
					case Timer_1 :
					{
									TIMER_1_CONTROL_B_REG |= (1U << TIMER_1_CLOCK_SELECT_BIT_0);
									TIMER_INTERRUPT_MASK_REG |= (1U << TIMER_1_OVERFLOW_INTERRUPT_ENABLE);
									Timers_status[Timer_Num] = Timer_S_Ready;
									break;
					}
					case Timer_2 :
					{
									TIMER_2_CONTROL_REG |= (1U << TIMER_2_CLOCK_SELECT_BIT_0);
									TIMER_INTERRUPT_MASK_REG |= (1U << TIMER_2_OVERFLOW_INTERRUPT_ENABLE);
									Timers_status[Timer_Num] = Timer_S_Ready;
									break;
					}
					default:
					{
						break;
					}
				}
			}
		}
	return en_timer_Errors;
}





en_timer_Errors_t Timer_Set(en_timer_Number_t Timer_Num , uint16_t Timer_value)
{
	en_timer_Errors_t en_timer_Errors = Timer_E_OK;
	
	if ((Timer_Num < Max_Timer_Numbers)		&&		
		(Timer_value < Timers_Capacity[Timer_Num]))
	{
		if (Timers_status[Timer_Num] == Timer_S_Ready)
		{
			switch(Timer_Num)
			{
				case Timer_0:
				{
					TIMER_0_COUNTER_REG = Timer_value;
					break;
				}
				
				case Timer_1:
				{
					TIMER_1_COUNTER_REG = Timer_value;
					break;
				}
				
				
				case Timer_2:
				{
					TIMER_2_COUNTER_REG = Timer_value;
					break;
				}
				
				
				default:
				{
					break;
				}
				
			}
			en_timer_Errors = Timer_E_OK;
		}
		else
		{
			en_timer_Errors = Timer_E_TRANSITION;
		}
	}
	else
	{
		en_timer_Errors = Timer_E_InvalidValue;
	}
	return en_timer_Errors;
}

/*

Timer_Errors Timer_Read(Timer_Number Timer_Num , uint16_t* Timer_value)
{
	if (Timer_Num < Max_Timer_Numbers)
	{
		if (Timers_status[Timer_Num] == Timer_S_Ready)
		{
			switch(Timer_Num)
			{
				case Timer_0:
				*Timer_value = TIMER_0_COUNTER_REG;
				break;
				
				case Timer_1:
				*Timer_value = TIMER_1_COUNTER_REG;
				break;
				
				case Timer_2:
				*Timer_value = TIMER_1_COUNTER_REG;
				break;
				
				default:
				break;
			}
			return Timer_E_OK;
		}
		else
		{
			return Timer_E_TRANSITION;
		}
	}
	else
	{
		return Timer_E_InvalidValue;
	}
}
*/
/*
Timer_Errors Timer_DeInit(Timer_Number Timer_Num)
{
	
	if (Timer_Num < Max_Timer_Numbers)
	{
		if (Timers_status[Timer_Num] == Timer_S_Ready)
		{
			switch(Timer_Num)
			{
				case Timer_0:
				TIMER_0_CONTROL_REG &= ~(1U << TIMER_0_CLOCK_SELECT_BIT_0);
				TIMER_INTERRUPT_MASK_REG &= ~(1U << TIMER_0_OVERFLOW_INTERRUPT_ENABLE);
				TIMER_0_COUNTER_REG = 0;
				Timers_status[Timer_Num] = Timer_S_UnInit;
				break;
				
				case Timer_1:
				TIMER_1_CONTROL_B_REG &= ~(1U << TIMER_1_CLOCK_SELECT_BIT_0);
				TIMER_INTERRUPT_MASK_REG &= ~(1U << TIMER_1_OVERFLOW_INTERRUPT_ENABLE);
				TIMER_1_COUNTER_REG = 0;
				Timers_status[Timer_Num] = Timer_S_UnInit;
				break;
				
				case Timer_2:
				TIMER_2_CONTROL_REG &= ~(1U << TIMER_2_CLOCK_SELECT_BIT_0);
				TIMER_INTERRUPT_MASK_REG &= ~(1U << TIMER_2_OVERFLOW_INTERRUPT_ENABLE);
				TIMER_2_COUNTER_REG = 0;
				Timers_status[Timer_Num] = Timer_S_UnInit;
				break;
				
				default:
				break;
			}
			return Timer_E_OK;
		}
		else
		{
			return Timer_E_TRANSITION;
		}
	}
	else
	{
		return Timer_E_InvalidValue;
	}
}
*/


en_timer_Errors_t timer_delay_50ms(en_timer_Number_t num)
{
	en_timer_Errors_t en_timer_Errors = Timer_E_OK;
	if (num < Max_Timer_Numbers)
	{
		Timer_Init(num);
		Timer_Set(num,15536);
		sei();
		
		en_timer_Errors = Timer_E_OK;
	}
	else
	{
		en_timer_Errors = Timer_E_InvalidValue;
	}
	return en_timer_Errors;
}