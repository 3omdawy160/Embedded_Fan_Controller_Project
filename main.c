/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: Fan Controller Project
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "lm35.h"
#include "pwm.h"
#include "dcMotor.h"



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void FanController(uint8 temp);
void FanController_init();



int main()
{
	/********************************Initialization*******************************************************/
	uint8 temp;// storing the temperature value coming from the temperature sensor
	ADC_configType config ={F_CPU_8,INTERNAL_256};// configuring the ADC
	ADC_init(&config); // initializing ADC driver
	FanController_init();// initializing the LCD, MOTOR (FAN) and displaying some words on the LCD screen

	/*******************************Endless for loop*****************************************************/
	for(;;)
	{
		temp = LM35_getTemperature();// reading the temperature from the temp.sensor
		FanController(temp);
	}
	return 0;
}




/*******************************************************************************
                       Functions Definitions
 *******************************************************************************/
void FanController(uint8 temp)
{
	/*The following lines are for displaying the temperature on the screen*/
	LCD_moveCursor(1,7);// moving the cursor
	if(temp < 100)
	{
		LCD_displayCharacter(' ');// In case the digital value is two or one digits print space in the next digit place
	}
	LCD_integerToString(temp);

	/*The following lines are for displaying the FAN state on the screen*/
	if(temp < 30)
	{
		LCD_moveCursor(0,7);// moving the cursor
		LCD_displayString("OFF");
		DcMotor_Rotate(STOP,0);// stopping the motor
	}
	else if(temp >= 120)
	{
		LCD_moveCursor(0,7);//moving the cursor
		LCD_displayString("ON");
		DcMotor_Rotate(CLOCK_WISE,100);// rotating the FAN (DC-MOTOR) with 100% of it's speed
	}
	else if(temp >= 90)
	{
		LCD_moveCursor(0,7);// moving the cursor
		LCD_displayString("ON");
		DcMotor_Rotate(CLOCK_WISE,75);// rotating the FAN (DC-MOTOR) with 75% of it's speed
	}
	else if(temp >= 60)
	{
		LCD_moveCursor(0,7);// moving the cursor
		LCD_displayString("ON");
		DcMotor_Rotate(CLOCK_WISE,50);// rotating the FAN (DC-MOTOR) with 50% of it's speed
	}
	else if(temp >= 30)
	{
		LCD_moveCursor(0,7);// moving the cursor
		LCD_displayString("ON");
		DcMotor_Rotate(CLOCK_WISE,25);// rotating the FAN (DC-MOTOR) with 25% of it's speed
	}
}


void FanController_init()
{
	LCD_init(); // initializing LCD driver
	DcMotor_Init();// initializing the motor
	LCD_displayString("FAN is ");// always displaying this word
	LCD_moveCursor(1,0);// moving the cursor to the second row
	LCD_displayString("Temp =    C");// always displaying this word
}
