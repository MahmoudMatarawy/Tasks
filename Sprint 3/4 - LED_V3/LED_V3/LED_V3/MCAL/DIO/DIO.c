#include "DIO_init.h"

/*****************************************************************************************/
/*    Function Description    : This Function to initialize the DIO module */
/*    Parameter in            : None */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : None */
/*    Requirment              : None */
/*****************************************************************************************/
/*void Dio_Init(void)
{
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTA = DIO_Config[u8_Counter];
	}
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTB = DIO_Config[u8_Counter+8];
	}
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTC = DIO_Config[u8_Counter+16];
	}
	for (uint8_t u8_Counter = 0 ; u8_Counter < 8 ; u8_Counter++)
	{
		DATA_DIRECTION_PORTD = DIO_Config[u8_Counter+24];
	}
}
*/



/*****************************************************************************************/
/*    Function Description    : This Function Sets pin Direction */
/*    Parameter in            : Dio_ChannelType ChannelId , Dio_LevelType level */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : DIO_E_OK if done correctly
*								DIO_InvalidPin if the ChannelId is valid Id*/
/*    Requirment              : None */
/*****************************************************************************************/
en_dio_Errors_t DIO_ChannelSetDIR(en_dio_channel_t ChannelId, en_dio_DIR_t dir)
{
	en_dio_Errors_t en_dio_Errors = DIO_E_OK;
	uint8_t pinNumber = 0 ;
	
	
	if (ChannelId < DIO_MAX_PINS)
	{
		if (ChannelId < DIO_PORTB_Channel0)
		{
			pinNumber = ChannelId;
			DATA_DIRECTION_PORTA |= dir << pinNumber;
		}
		else if (ChannelId < DIO_PORTC_Channel0)
		{
			pinNumber = ChannelId-PORTA_CHANNELS;
			DATA_DIRECTION_PORTB |= dir << pinNumber;
		}
		else if (ChannelId < DIO_PORTD_Channel0)
		{
			pinNumber = ChannelId - PORTA_CHANNELS - PORTB_CHANNELS;
			DATA_DIRECTION_PORTC |= dir << pinNumber;
		}
		else
		{
			pinNumber = ChannelId - PORTA_CHANNELS - PORTB_CHANNELS - PORTC_CHANNELS;
			DATA_DIRECTION_PORTD |= dir << pinNumber;
		}
		//return DIO_E_OK;
	}
	else{
		en_dio_Errors =  DIO_InvalidPin;
	}
	
	
	return en_dio_Errors;
}



/*****************************************************************************************/
/*    Function Description    : This Function to Read the Level of the pin */
/*    Parameter in            : Dio_ChannelType ChannelId  */
/*    Parameter inout         : None */
/*    Parameter out           : Dio_LevelType* level */
/*    Return value            : DIO_E_OK if done correctly 
*								DIO_InvalidPin if the ChannelId is valid Id*/
/*    Requirment              : None */
/*****************************************************************************************/
en_dio_Errors_t DIO_ReadChannel(en_dio_channel_t ChannelId ,en_dio_Level_t* level)
{
	en_dio_Errors_t en_dio_Errors = DIO_E_OK;
	uint8_t pinNumber ;
	
	
	if (ChannelId < DIO_MAX_PINS )
	{
		if (ChannelId < DIO_PORTB_Channel0)
		{
			pinNumber = ChannelId;
			*level = ((RE_PORT_A & (1U<<pinNumber))>>pinNumber); 
		}
		else if (ChannelId < DIO_PORTC_Channel0)
		{
			pinNumber = ChannelId - PORTA_CHANNELS;
			*level = ((RE_PORT_B & (1U<<pinNumber))>>pinNumber);
		}
		else if (ChannelId < DIO_PORTD_Channel0)
		{
			pinNumber = ChannelId - PORTA_CHANNELS - PORTB_CHANNELS;
			*level = ((RE_PORT_C & (1U<<pinNumber))>>pinNumber);
		}
		else
		{
			pinNumber = ChannelId - PORTA_CHANNELS - PORTB_CHANNELS - PORTC_CHANNELS;
			*level = ((RE_PORT_D & (1U<<pinNumber))>>pinNumber);
		}
		//*level &= 0x01; 
		//return DIO_E_OK;
	}
	else{
		en_dio_Errors =  DIO_InvalidPin;
	}
	
	return en_dio_Errors;	
}


/*****************************************************************************************/
/*    Function Description    : This Function Sets pin Level */
/*    Parameter in            : Dio_ChannelType ChannelId , Dio_LevelType level */
/*    Parameter inout         : None */
/*    Parameter out           : None */
/*    Return value            : DIO_E_OK if done correctly
*								DIO_InvalidPin if the ChannelId is valid Id*/
/*    Requirment              : None */
/*****************************************************************************************/
en_dio_Errors_t DIO_WriteChannel(en_dio_channel_t ChannelId, en_dio_Level_t level)
{
	en_dio_Errors_t en_dio_Errors = DIO_E_OK;
	uint8_t pinNumber ;
	
	
	if (ChannelId < DIO_MAX_PINS )
	{
		if (ChannelId < DIO_PORTB_Channel0)
		{
			pinNumber = ChannelId;
			if (level == STD_HIGH)
			{
				WR_PORT_A |= (1U << pinNumber);
			}
			else{
				WR_PORT_A &= ~(1U << pinNumber);
			}
		}
		else if (ChannelId < DIO_PORTC_Channel0)
		{
			pinNumber = ChannelId - PORTA_CHANNELS;
			if (level == STD_HIGH)
			{
				WR_PORT_B |= (1U << pinNumber);
			}
			else{
				WR_PORT_B &= ~(1U << pinNumber);
			}
		}
		else if (ChannelId < DIO_PORTD_Channel0)
		{
			pinNumber = ChannelId - PORTA_CHANNELS - PORTB_CHANNELS;
			if (level == STD_HIGH)
			{
				WR_PORT_C |= (1U << pinNumber);
			}
			else{
				WR_PORT_C &= ~(1U << pinNumber);
			}
		}
		else
		{
			pinNumber = ChannelId - PORTA_CHANNELS - PORTB_CHANNELS - PORTC_CHANNELS;
			if (level == STD_HIGH)
			{
				WR_PORT_D |= (1U << pinNumber);
			}
			else{
				WR_PORT_D &= ~(1U << pinNumber);
			}
		}
		//return DIO_E_OK;
	}
	else{
		en_dio_Errors = DIO_InvalidPin;
	}
	
	return en_dio_Errors;
}