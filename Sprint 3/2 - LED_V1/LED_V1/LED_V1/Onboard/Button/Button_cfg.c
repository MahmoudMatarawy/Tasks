

#include "Button_cfg.h"

const Button_configType Button_config[BUTTONS_NUM] = {{
	DIO_PORTC_Channel2,										// Button_1 Channel ID
	1,														// Button_1 Debounce Threshold
	Button_HOLD_THRESHOLD									// Button_1 Hold Threshold
}};
