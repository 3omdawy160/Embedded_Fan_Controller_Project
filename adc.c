/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: source file for the icu driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#include "adc.h"
#include "gpio.h"
#include "avr/io.h"
#include "common_macros.h"

/*******************************************************************************
                       Functions Definitions
 *******************************************************************************/

void ADC_init(const ADC_configType *config) // This ADC is only configured to work in the polling mode
{
	ADMUX = (ADMUX & 0x3F) | ((config->referenceVoltage)<<6);//Inserting the reference voltage
	ADCSRA = (ADCSRA & 0xF8) | (config->preScaler);//Inserting the prescaler
	CLEAR_BIT(ADMUX,ADLAR);//right adjusted

	/* Configuring the ADCSRA register */
	SET_BIT(ADCSRA,ADEN);//enabling the ADC
	CLEAR_BIT(ADCSRA,ADATE);//disabling the auto trigger
	CLEAR_BIT(ADCSRA,ADIE);//disabling the interrupt of the ADC
}

uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);//Inserting the channel number
	SET_BIT(ADCSRA,ADSC);//to start the conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF));//waiting for the flag to be set (polling technique)
	SET_BIT(ADCSRA,ADIF);//Clearing the flag bin
	return ADC;//returning the digital value after conversion
}
