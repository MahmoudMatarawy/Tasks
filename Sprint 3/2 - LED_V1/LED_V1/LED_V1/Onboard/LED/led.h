#ifndef _LED_H_
#define _LED_H_

// Create LED ID ENUM
typedef uint8_t LED_ID_type;

#define LED_1		((LED_ID_type)0x01)
#define LED_2		((LED_ID_type)0x02)
#define LED_3		((LED_ID_type)0x03)
#define	LED_4		((LED_ID_type)0x04)



// Create LED state ENUM
typedef uint8_t LED_STATE_type;
#define LED_OFF		((LED_STATE_type)0x00)
#define LED_ON		((LED_STATE_type)0x01)


void led_Init(void);
void led_OFF(LED_ID_type led);
void led_ON(LED_ID_type led);

#endif	/* LED_H	*/