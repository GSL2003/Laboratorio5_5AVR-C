/*
 * PWM01.h
 *
 * Created: 19/04/2024 15:11:34
 *  Author: Guilelrmo Schwartz
 */ 


#ifndef PWM0_H_
#define PWM0_H_

#include <avr/io.h>
#include <stdint.h>

//Se definen las etiquetas de los modos
#define NO_INVERTIDO	1
#define INVERTIDO		0

void PWM0_init(void);						//Establecer le ciclo de trabajo de la salida PWM
void PWM0_dca(uint8_t dc, uint8_t modo);	//Define si la salida es de tipo invertida o no invertida  -- "dca" Salida del lado A
void PWM0_dcb(uint8_t dc, uint8_t modo);	//Define si la salida es de tipo invertida o no invertida  -- "dcb" Salida del lado B

#endif /* PWM0_H_ */