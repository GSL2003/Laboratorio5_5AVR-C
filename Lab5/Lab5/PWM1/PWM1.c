/*
 * ADC.c
 *
 * Created: 16/04/2024 15:32:36
 *  Author: Guillermo Schwartz
 */ 

#include "PWM1.h"
#include <avr/io.h>

void PWM1_initial(void){
	//Configuración valores de entrada
	DDRB |= (1<<DDB1)|(1<<DDB2);
	
	TCNT1 = 0;				//Se configura el RESET
	ICR1 = 39999;			//Se configura el TOP
	
	TCCR1A =  (1 << COM1A1) | (1 << COM1B1) | (0 << COM1A0) ;		//Salida en nivel bajo --> Se compara la coincidencia
	TCCR1A |=  (1 << WGM11) | (0 << WGM10) ; // Configuración PWM MODO:Fast TOP ICR1
	TCCR1B = (1 << WGM13) | (1 << WGM12); // Modo Fast PWM TOP ---> ICR1
	
	// Configuración del Prescaler: 8
	TCCR1B |= (1 << CS11);
}

void servo_moA1(float adc_Value){					//Configuración del movimiento del servo canal A
	//// Mapear el valor del potenciómetro al ciclo de trabajo del PWM
	OCR1A = map(adc_Value, 0, 1024, 1000, 4800);
}

void servo_moB1(float adc_Value){					//Configuración del movimiento del servo canal B
	OCR1B = map(adc_Value, 0, 1024, 1000, 4800);
}

uint16_t map(float x, float in_min, float in_max, float out_min, float out_max){
	return ((x - in_min)*(out_max - out_min)/(in_max - in_min)) + out_min;
}