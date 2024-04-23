/*
 * PWM2.h
 *
 * Created: 17/04/2024 15:37:57
 *  Author: Guillermo Schwartz
 */ 


#ifndef PWM2_H_
#define PWM2_H_

#include <avr/io.h>
#include <stdint.h>

#define NO_INVERTIDO 1
#define INVERTIDO 0

float map1(float, float, float, float, float);				//Función para convertir valores

void PWM2_initial(uint8_t inverted, uint16_t prescaler);	//Función del PWM2 ---> Canal A

void servo_mo2(uint8_t duty);							//Funcion ciclo del trabajo del Servomotor

#endif /* PWM2_H_ */
