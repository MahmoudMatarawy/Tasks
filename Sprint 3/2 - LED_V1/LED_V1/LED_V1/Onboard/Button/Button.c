
#include "../../MCAL/DIO/DIO.h"
#include "Button_Types.h"
#include "Button_cfg.h"
#include "Button.h"

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


void button_Init(void)
{
	uint8_t u8Index;
	
	for(u8Index=0;u8Index<BUTTONS_NUM;u8Index++)
	{
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
		strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_RELEASE;
	}
	else
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold++;
		
		if(strBtnInfo[enuBtnId].u8DebounceThreshold ==
		Button_config[enuBtnId].u8DebounceThreshold)
		{
			strBtnInfo[enuBtnId].btn_state    = BT_PUSHED;
		}
		else
		{
			/* Do Nothing */
		}
	}
}



static void vidPushState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_RELEASE;
	}
	else
	{
		strBtnInfo[enuBtnId].u8HoldThreshold  = ((uint8_t)0);
		strBtnInfo[enuBtnId].btn_state = BT_PRE_HOLD;
	}
}


static void vidPreHoldState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		strBtnInfo[enuBtnId].u8HoldThreshold    = BT_PRE_RELEASE;
	}
	else
	{
		strBtnInfo[enuBtnId].u8HoldThreshold++;
		if(strBtnInfo[enuBtnId].u8HoldThreshold >=
		Button_config[enuBtnId].u8HoldThreshold)
		{
			strBtnInfo[enuBtnId].btn_state = BT_HOLD;
		}
		else
		{
			/* Do Nothing */
		}
	}
}



static void vidHoldState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_RELEASE_LEVEL)
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_RELEASE;
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
		
		if(strBtnInfo[enuBtnId].u8DebounceThreshold ==
		Button_config[enuBtnId].u8DebounceThreshold)
		{
			strBtnInfo[enuBtnId].btn_state = BT_RELEASED;
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_PUSH;
	}
}




static void vidReleaseState(Button_IdType enuBtnId)
{
	uint8_t u8BtnValue;
	
	Dio_ReadChannel(Button_config[enuBtnId].ChannelId, &u8BtnValue);
	
	if(u8BtnValue == BT_PUSH_LEVEL)
	{
		strBtnInfo[enuBtnId].u8DebounceThreshold = ((uint8_t)0);
		strBtnInfo[enuBtnId].btn_state    = BT_PRE_PUSH;
	}
	else
	{
		/* Do nothing */
	}
}