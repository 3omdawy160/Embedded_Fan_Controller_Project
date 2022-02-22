/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dcMotor.c
 *
 * Description: source file for the dc motor driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#include "dcMotor.h"
#include "gpio.h"
#include <avr/io.h>
#include "pwm.h"

/*******************************************************************************
                       Functions Definitions
 *******************************************************************************/

void DcMotor_Init()
{
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN0,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN1,PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 duty_cycle;

	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,(state & 0x01)>>DC_MOTOR_PIN0);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,(state & 0x02)>>DC_MOTOR_PIN1);

	duty_cycle = (uint8)((uint16)(speed*255)/(100));
	PWM_Timer0_Start(duty_cycle);
}
