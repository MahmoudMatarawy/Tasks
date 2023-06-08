
#include "app.h"
#include <stdint.h>

#include <avr/interrupt.h>



uint8_t u8_btn_state = BT_PRE_HOLD;
uint8_t f_int = 0;
uint8_t f_int1 = 0;
volatile uint8_t u8_blink_counter = 0;
uint8_t u8_mode_counter=0;
volatile uint8_t u8_Full_cycle = 0;




ISR(INT0_vect)
{
	if (f_int>0)
	{
		u8_Full_cycle++;
	}
	else
	{
		f_int++;
	}
}



ISR(INT1_vect)
{
	if (f_int1>0)
	{
		u8_blink_counter = 0;
		if (u8_mode_counter == 4)
		{
			u8_mode_counter = 0;
		}
		else
		{
			u8_mode_counter++;
		}
		//u8_mode_counter++;
	}
	else
	{
		f_int1++;
	}
}



ISR(TIMER1_OVF_vect)
{
	u8_blink_counter++;
	TCNT1 = 15536 ;
}




void blink_1(LED_ID_type led)
{
	if (u8_blink_counter >= 0  && u8_blink_counter < 2)
	{
		led_ON(led);
	}
	else if (u8_blink_counter >= 2	&& u8_blink_counter < 20)
	{
		led_OFF(led);
	}
	else if (u8_blink_counter >= 20)
	{
		u8_blink_counter = 0;
	}
	else
	{
		// do nothing
	}
}
void blink_2(LED_ID_type led)
{
	if (u8_blink_counter >= 0  && u8_blink_counter < 4)
	{
		led_ON(led);
	}
	else if (u8_blink_counter >= 4	&& u8_blink_counter < 20)
	{
		led_OFF(led);
	}
	else if (u8_blink_counter >= 20)
	{
		u8_blink_counter = 0;
	}
	else
	{
		// do nothing
	}
}
void blink_3(LED_ID_type led)
{
	if (u8_blink_counter >= 0  && u8_blink_counter < 6)
	{
		led_ON(led);
	}
	else if (u8_blink_counter >= 6	&& u8_blink_counter < 20)
	{
		led_OFF(led);
	}
	else if (u8_blink_counter >= 20)
	{
		u8_blink_counter = 0;
	}
	else
	{
		// do nothing
	}
}
void blink_4(LED_ID_type led)
{
	if (u8_blink_counter >= 0  && u8_blink_counter < 10)
	{
		led_ON(led);
	}
	else if (u8_blink_counter >= 10	&& u8_blink_counter < 20)
	{
		led_OFF(led);
	}
	else if (u8_blink_counter >= 20)
	{
		u8_blink_counter = 0;
	}
	else
	{
		// do nothing
	}
}
void blink_5(LED_ID_type led)
{
	if (u8_blink_counter >= 0  && u8_blink_counter < 16)
	{
		led_ON(led);
	}
	else if (u8_blink_counter >= 16	&& u8_blink_counter < 20)
	{
		led_OFF(led);
	}
	else if (u8_blink_counter >= 20)
	{
		u8_blink_counter = 0;
	}
	else
	{
		// do nothing
	}
}

void blink_mode(uint8_t blink , uint8_t led)
{
	switch(blink)
	{
		case 0 :
		{
			blink_1(led);
			break;
		}
		
		
		case 1 :
		{
			blink_2(led);
			break;
		}
		
		
		case 2:
		{
			blink_3(led);
			break;
		}
		
		
		case 3 :
		{
			blink_4(led);
			break;
		}
		
		
		case 4 :
		{
			blink_5(led);
			break;
		}
		
		
		default:
		{
			break;
		}
	}
}

void appStart(void)
{
	 button_Init();
	 led_Init();
	 timer_delay_50ms(Timer_1);
	 
	while(1)
	{
		switch(u8_Full_cycle)
		{
			case 1:
			{
				blink_mode(u8_mode_counter , 1);
				break;
			}
			
			
			case 2:
			{
				blink_mode(u8_mode_counter , 1);
				blink_mode(u8_mode_counter , 2);
				break;
			}
			
			
			case 3 :
			{
				blink_mode(u8_mode_counter , 1);
				blink_mode(u8_mode_counter , 2);
				blink_mode(u8_mode_counter , 3);
				break;
			}
			
			
			case 4 :
			{
				blink_mode(u8_mode_counter , 1);
				blink_mode(u8_mode_counter , 2);
				blink_mode(u8_mode_counter , 3);
				blink_mode(u8_mode_counter , 4);
				break;
			}
			
			
			case 5:
			{
				led_OFF(1);
				blink_mode(u8_mode_counter , 2);
				blink_mode(u8_mode_counter , 3);
				blink_mode(u8_mode_counter , 4);
				break;
			}
			
			
			case 6:
			{
				led_OFF(1);
				led_OFF(2);
				blink_mode(u8_mode_counter , 3);
				blink_mode(u8_mode_counter, 4);
				break;
			}
			
			
			
			case 7 :
			{
				led_OFF(1);
				led_OFF(2);
				led_OFF(3);
				blink_mode(u8_mode_counter , 4);
				break;
			}
			
			
			case 8 :
			{
				led_OFF(1);
				led_OFF(2);
				led_OFF(3);
				led_OFF(4);
				u8_Full_cycle = 0;
				break;
			}
			
			default:
			{
				break;
			}
		}
	}
	
}