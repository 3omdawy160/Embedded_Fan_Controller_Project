 /******************************************************************************
 *
 * File Name: lm35.c
 *
 * Description: source file for the LM35 Temperature sensor
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/


#include "lm35.h"
#include "adc.h"

/*******************************************************************************
                       Functions Definitions
 *******************************************************************************/

sint16 LM35_getTemperature()
{
	uint16 ADC_Value;
	sint16 tempValue;

	ADC_Value = ADC_readChannel(2);
	tempValue = (uint16)(((uint32)ADC_Value*LM_MAX_DETECTED_TEMP*AREF_VOLT)/(1023*LM_MAX_OUTPUT_VOLTAGE));
	return tempValue;
}
