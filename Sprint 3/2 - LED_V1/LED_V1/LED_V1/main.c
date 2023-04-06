/*
 * LED_V1.c
 *
 * Created: 4/5/2023 7:52:25 PM
 * Author : Mahmoud Sarhan
 * Email  : Mahmoudsarhan02672@gmail.com
 */ 
//#include <util/delay.h>
#include <avr/io.h>
#include "MCAL/DIO/DIO.h"
#include "Onboard/Button/Button.h"
int main(void)
{
	uint8_t data;
	 Dio_Init();
	 button_Init();
	 //PORTC |= (1<<2);
    /* Replace with your application code */
    while (1) 
    {
		//Dio_ReadChannel(DIO_PORTC_Channel2,&data);
		//Dio_WriteChannel(DIO_PORTB_Channel0 , data);
		//PORTB = ((PINC&(1U<<PINC2))>>PINC2);
		//data = 0;
		button_Main_Task();
		data = getButtonState(0);
		//PORTB = data;
		
		if (data == BT_RELEASED)
		{
			PORTB = 1<<1;
		}
		else if (data == BT_PRE_PUSH)
		{
			PORTB = 1 << 2;
			
		}
		else{
			PORTB = 0;
		}
		//_delay_ms(2000);
    }
}

