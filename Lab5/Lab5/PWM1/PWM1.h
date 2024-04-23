/*
 * ADC.c
 *
 * Created: 16/04/2024 15:32:36
 *  Author: Guillermo Schwartz
 */ 


#ifndef PWM1_H_
#define PWM1_H_

#include <avr/io.h>

void PWM1_initial(void);					//Prototipo de funci�n para la configuraci�n inicial del PWM (TIMER1)

void servo_moA1(float valADC);			//Prototipo de funci�n para el movimiento del servo en el canal A

void servo_moB1(float valADC);			//Prototipo de funci�n para el movimiento del servo B

//Declarar una funci�n de mapeo para convertir el valor del potenci�metro en el ciclo de trabajo del PWM
uint16_t map(float x, float in_min, float in_max, float out_min, float out_max);

#endif /* PWM1_H_ */