
#include "app.h"
#include <stdint.h>
void appStart(void)
{
	uint8_t u8_process = LED_ON;
	uint8_t u8_counter = ((uint8_t)1);
	uint8_t u8_btn_state = BT_PRE_HOLD;
	//DDRA = 0xff;
	 button_Init();
	 led_Init();
	while(1)
	{
		//_delay_ms(10);
		button_Main_Task();
		if (u8_process == LED_ON)
		{
			// set leds ON one in a press
			u8_btn_state = getButtonState(Button_Start);
			//PORTA = u8_btn_state;
			if (u8_btn_state == BT_RELEASED)
			{
				led_ON(u8_counter);
				//_delay_ms(300);
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
			// set leds OFF one in a press
			u8_btn_state = getButtonState(Button_Start);
			//PORTA = u8_btn_state;
			if (u8_btn_state == BT_RELEASED)
			{
				led_OFF(u8_counter);
				//_delay_ms(300);
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