/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dcMotor.h
 *
 * Description: header file for the dc motor driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"



/*******************************************************************************
                                 Some Definitions
 *******************************************************************************/
#define DC_MOTOR_PORT PORTB_ID
#define DC_MOTOR_PIN0 PIN0_ID
#define DC_MOTOR_PIN1 PIN1_ID



/*******************************************************************************
                                Types Declaration
 *******************************************************************************/
typedef enum{
	STOP,CLOCK_WISE,ANTI_CLOCK_WISE
}DcMotor_State;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DCMOTOR_H_ */
