/*
 * LED_V1.c
 *
 * Created: 4/5/2023 7:52:25 PM
 * Author : Mahmoud Sarhan
 * Email  : Mahmoudsarhan02672@gmail.com
 */ 
#include <util/delay.h>
#include <avr/io.h>
#include "Application/app.h"
//#include "MCAL/DIO/DIO.h"
#include "Onboard/Button/Button.h"
#include "Onboard/LED/led.h"
int main(void)
{
	//appStart();
	uint8_t data;
	 //Dio_Init();
	 button_Init();
	 led_Init();
	 //DDRB = 0xff;
	 //PORTC |= (1<<2);
    //Replace with your application code 
    while (1) 
    {
		//Dio_ReadChannel(DIO_PORTC_Channel2,&data);
		//Dio_WriteChannel(DIO_PORTB_Channel0 , data);
		//PORTB = ((PINC&(1U<<PINC2))>>PINC2);
		//data = 0;
		_delay_ms(10);
		button_Main_Task();
		data = getButtonState(0);
		//PORTB = data;
		
		if (data == BT_PRE_RELEASE)
		{
			led_ON(1);
			led_ON(2);
			led_ON(3);
			led_ON(4);
			//PORTB = 1<<1;
			//_delay_ms(1000);
		}
		else if (data == BT_PRE_PUSH)
		{
			led_OFF(1);
			led_OFF(2);
			led_OFF(3);
			led_OFF(4);
			//PORTB = 1 << 3;
			//_delay_ms(1000);
		}
		else{
			//PORTB = 0;
		}
		//_delay_ms(2000);
    }
}

