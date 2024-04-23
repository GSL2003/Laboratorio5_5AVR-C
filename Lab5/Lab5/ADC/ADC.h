/*
 * ADC.h
 *
 * Created: 16/04/2024 15:32:08
 *  Author: Guillermo Schwartz
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_init(void);					//Prototipo de funci�n para configruar el ADC

uint16_t ADC_read(uint8_t canal);		//Prototipo de funci�n para leer los canales del ADC

#endif /* ADC_H_ */