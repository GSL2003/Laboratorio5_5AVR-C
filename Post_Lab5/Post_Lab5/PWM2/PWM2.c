/*
 * PWM2.c
 *
 * Created: 17/04/2024 15:39:26
 *  Author: Guillermo Schwartz
 */ 

#include "PWM2.h"
#include <avr/io.h>

//->Configuración PWM Timer2

void PWM2_initial(uint8_t inverted, uint16_t prescaler){			//Configuración del Canal A
	//Declarar saldias
	DDRB |= (1 << DDB3); //Se define el pin PB3 como salida
	
	//Configuración modo Fast
	TCCR2A |= (1 << WGM21)|(1 << WGM20); 
	
	//Configuración de PWM INVERTIDO
	if (inverted) {
		TCCR2A |= (1 << COM2A1)|(1 << COM2A0);
		} else	 {	//PWM NO INVERTIDO
		TCCR2A |= (1 << COM2A1);
	}

	//Configuración Prescaler de 1024
	if (prescaler == 1024) {
		TCCR2B |= (1 << CS22)|(1 << CS21)|(1 << CS20);
		} else {
		TCCR2B |= (1 << CS20);
	}
}

void servo_mo2(uint8_t duty){		//Mapeo canal A
	OCR2A = map1(duty,0,200,6,36);
}

//Declarar una función de mapeo para convertir el valor del potenciómetro
float map1(float x, float in_min, float in_max, float out_min, float out_max){
	return ((x - in_min)*(out_max - out_min)/(in_max - in_min)) + out_min;
}