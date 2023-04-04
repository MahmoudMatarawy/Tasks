#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/PWM/pwm.h"


#define MOTOR_MAX_NUM	2

#define MOTORS_RIGHT_Channel	DIO_PORTD_Channel7
#define MOTORS_LEFT_Channel		DIO_PORTB_Channel3

// Create Motor ID ENUM
typedef uint8_t MOTOR_ID_Type;

#define MOTORS_RIGHT			((MOTOR_ID_Type)0x00)
#define MOTORS_LEFT				((MOTOR_ID_Type)0x01)


// Create Motor Dir ENUM
typedef uint8_t MOTOR_DIR_Type;


#define MOTOR_FORWARD		((MOTOR_DIR_Type)0x00)
#define MOTOR_BACKWARD		((MOTOR_DIR_Type)0x01)



void motorStart(MOTOR_ID_Type motor);
void motorStop(MOTOR_ID_Type motor);
void motorSet_dir(MOTOR_ID_Type motor,MOTOR_DIR_Type dir);
void motorSet_speed(MOTOR_ID_Type motor,uint8_t speed);
void motor_RotateLeft(void);
void motor_RotateRight(void);
#endif	/* MOTOR_H */