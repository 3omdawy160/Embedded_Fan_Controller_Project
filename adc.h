 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the adc driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,INTERNAL_256=3
}ADC_referenceVolatge;

typedef enum{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_preScaler;

typedef struct{
	ADC_preScaler preScaler;
	ADC_referenceVolatge referenceVoltage;
}ADC_configType;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADC_init(const ADC_configType *config);
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
