#ifndef _LED_H_
#define _LED_H_

#include "led_types.h"

void led_Init(void);
void led_OFF(LED_ID_type led);
void led_ON(LED_ID_type led);

#endif	/* LED_H	*/