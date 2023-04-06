
#include "led_types.h"
#include "led.h"
#include "led_cfg.h"



void led_Init(void)
{
	uint8_t u8_index;
	
	for (u8_index = 0 ; u8_index < LED_NUMs ; u8_index++)
	{
		Dio_ChannelSetDIR((LED_Config[u8_index].LED_CHANNEL_ID) , STD_OUTPUT);
		led_OFF(u8_index);
	}
}
void led_OFF(LED_ID_type led)
{
	Dio_WriteChannel(LED_Config[led-1].LED_CHANNEL_ID,LED_OFF);
}
void led_ON(LED_ID_type led)
{
	Dio_WriteChannel(LED_Config[led-1].LED_CHANNEL_ID,LED_ON);
}