
#include "app.h"
#include <stdint.h>

#include <avr/interrupt.h>



uint8_t u8_btn_state = BT_PRE_HOLD;
uint8_t f_int = 0;

ISR(INT0_vect)
{
	if (f_int>0)
	{
		u8_btn_state = BT_RELEASED;
	}
	else
	{
		f_int++;
	}
}

void appStart(void)
{
	uint8_t u8_process = LED_ON;
	uint8_t u8_counter = ((uint8_t)1);
	
	 button_Init();
	 led_Init();
	 sei();
	while(1)
	{
		if (u8_process == LED_ON)
		{
			if (u8_btn_state == BT_RELEASED)
			{
				u8_btn_state = BT_PRE_PUSH;
				led_ON(u8_counter);
				if (u8_counter == ((uint8_t)4))
				{
					u8_process = LED_OFF;
					u8_counter = ((uint8_t)1);
				}
				else
				{
					u8_counter += ((uint8_t)1);
				}
			}
		}
		else
		{
			if (u8_btn_state == BT_RELEASED)
			{
				u8_btn_state = BT_PRE_PUSH;
				led_OFF(u8_counter);
				if (u8_counter == ((uint8_t)4))
				{
					u8_process = LED_ON;
					u8_counter = ((uint8_t)1);
				}
				else
				{
					u8_counter += ((uint8_t)1);
				}
			}
		}
	}
	
}