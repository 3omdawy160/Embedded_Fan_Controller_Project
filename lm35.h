/******************************************************************************
 *
 * File Name: lm35.h
 *
 * Description: header file for the LM35 Temperature sensor
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"



/*******************************************************************************
                                 Some Definitions
 *******************************************************************************/
#define AREF_VOLT 2.56
#define LM_MAX_DETECTED_TEMP 150
#define LM_MAX_OUTPUT_VOLTAGE 1.5


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
sint16 LM35_getTemperature();


#endif /* TEMPSENSOR_H_ */
