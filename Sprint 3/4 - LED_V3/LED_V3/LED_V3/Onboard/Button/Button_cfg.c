

#include "Button_cfg.h"
#include "../../MCAL/EXT_INT/EXT_INT.h"

const Button_configType Button_config[BUTTONS_NUM] = {{
	DIO_PORTD_Channel2,										// Button_1 Channel ID
	1,														// Button_1 Debounce Threshold
	Button_HOLD_THRESHOLD,									// Button_1 Hold Threshold
	INT_0_ID												// Button_1 External interrupt
},
{
	DIO_PORTD_Channel3,										// Button_1 Channel ID
	1,														// Button_1 Debounce Threshold
	Button_HOLD_THRESHOLD,									// Button_1 Hold Threshold
	INT_1_ID												// Button_1 External interrupt
}
};
