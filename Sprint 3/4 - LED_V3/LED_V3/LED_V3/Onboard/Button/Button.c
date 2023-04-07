
#include "../../MCAL/DIO/DIO.h"
#include "Button_Types.h"
#include "Button_cfg.h"
#include "Button.h"
#include "../../MCAL/EXT_INT/EXT_INT.h"
typedef struct {
	Button_StateType btn_state;
	uint8_t u8DebounceThreshold;
	uint8_t u8HoldThreshold;
}btn_Config;



static btn_Config strBtnInfo[BUTTONS_NUM];




/******************************************************************************/
/*********************** Private Functions Declaration ************************/
/******************************************************************************/
static void vidUpdateBtnState(Button_IdType enuBtnId);
static void vidPrePushState(Button_IdType enuBtnId);
static void vidPushState(Button_IdType enuBtnId);
static void vidPreHoldState(Button_IdType enuBtnId);
static void vidHoldState(Button_IdType enuBtnId);
static void vidPreReleaseState(Button_IdType enuBtnId);
static void vidReleaseState(Button_IdType enuBtnId);




/******************************************************************************/
/*********************** Public Functions Implementation **********************/
/******************************************************************************/


void button_Init(void)
{
	uint8_t u8Index;
	
	for(u8Index=0;u8Index<BUTTONS_NUM;u8Index++)
	{
		// Set button pin as input
		Dio_ChannelSetDIR((Button_config[u8Index].ChannelId) , STD_INPUT);
		
		// Enable PULLUP
		Dio_WriteChannel(Button_config[u8Index].ChannelId, STD_HIGH);
		
		eXT_INT_Enable(Button_config[u8Index].eXt_INT , EXT_INT_FALLING_EDGE);
		
		strBtnInfo[u8Index].btn_state     = BT_RELEASED;
		strBtnInfo[u8Index].u8DebounceThreshold  = ((uint8_t)0U);
		strBtnInfo[u8Index].u8HoldThreshold      = ((uint8_t)0U);
	}
}



void button_Main_Task(void)
{
	uint8_t u8Index;
	
	
	for(u8Index=0;u8Index<BUTTONS_NUM; u8Index++)
	{
		vidUpdateBtnState((Button_IdType)u8Index);
	}
}


Button_StateType getButtonState(Button_IdType enmButtonId)
{
	Button_StateType enuReturn;
	
	if(enmButtonId < BUTTONS_NUM)
	{
		enuReturn = strBtnInfo[enmButtonId].btn_state ;
	}
	else
	{
		enuReturn = BT_UNDEFINED;
	}
	
	return (enuReturn);
}



static void  vidUpdateBtnState(Button_IdType enuBtnId)
{
	switch(strBtnInfo[enuBtnId].btn_state)
	{
		case BT_PRE_PUSH:
		vidPrePushState(enuBtnId);
		break;
		
		case BT_PUSHED:
		vidPushState(enuBtnId);
		break;
		
		case BT_PRE_HOLD:
		vidPreHoldState(enuBtnId);
		break;
		
		case BT_HOLD:
		vidHoldState(enuBtnId);
		break;
		
		case BT_PRE_RELEASE:
		vidPreReleaseState(enuBtnId);
		break;
		
		case BT_RELEASED:
		vidReleaseState(enuBtnId);
		break;
		
		default:
		break;
	}
}




static void vidPrePushState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId,&u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].btn_state    = BT_PUSHED;
	}
	else
	{
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_PUSH;
	}
}



static void vidPushState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_HOLD;
	}
	else
	{
		strBtnInfo[enuBtnId].btn_state = BT_RELEASED;
	}
}


static void vidPreHoldState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].btn_state   = BT_HOLD;
	}
	else
	{
		strBtnInfo[enuBtnId].btn_state    = BT_RELEASED;
	}
}



static void vidHoldState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold++;
		if(strBtnInfo[enuBtnId].u8DebounceThreshold == Button_config[enuBtnId].u8DebounceThreshold)
		{
			strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
			strBtnInfo[enuBtnId].btn_state    = BT_PRE_RELEASE;
		}
		else
		{
			/* Do Nothing */
		}
		
	}
	else
	{
		/* Do Nothing */
	}
}



static void vidPreReleaseState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold++;
	}
	else
	{
		if(strBtnInfo[enuBtnId].u8DebounceThreshold >= Button_config[enuBtnId].u8DebounceThreshold)
		{
			strBtnInfo[enuBtnId].btn_state = BT_RELEASED;
		}
		else
		{
			strBtnInfo[enuBtnId].btn_state    = BT_PRE_PUSH;
		}
		strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		
	}
}




static void vidReleaseState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_PUSH_LEVEL)
	{
		//strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_PUSH;
	}
	else
	{
		/* Do nothing */
	}
}