
#include "led_types.h"
#include "led.h"
#include "led_cfg.h"



void led_Init(void)
{
	uint8_t u8_index;
	
	for (u8_index = 0 ; u8_index < LED_NUMs ; u8_index++)
	{
		Dio_ChannelSetDIR((LED_Config[u8_index].LED_CHANNEL_ID) , STD_OUTPUT);
		if (LED_Config[u8_index].LED_STATE == LED_ON)
		{
			led_ON(u8_index+1);
		}
		else
		{
			led_OFF(u8_index+1);
		}
		
	}
}
LED_ERROR_type led_OFF(LED_ID_type led)
{
	if(led > LED_NUMs)
	{
		return LED_UNDEFINED;
	}
	Dio_WriteChannel(LED_Config[led-1].LED_CHANNEL_ID,LED_OFF);
	return  LED_OK;
}
LED_ERROR_type led_ON(LED_ID_type led)
{
	if(led > LED_NUMs)
	{
		return LED_UNDEFINED;
	}
	Dio_WriteChannel(LED_Config[led-1].LED_CHANNEL_ID,LED_ON);
	return  LED_OK;
}