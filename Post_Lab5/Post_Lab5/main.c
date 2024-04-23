//******************************************************************************************************************
//UNIVERSIDAD DEL VALLE DE GUATEMALA
//IE2023: PROGRAMACI�N DE MICROCONTROLADORES
//Archivo: Lab5
//AUTOR: Guillermo Jos� Schwartz L�pez
//Laboratorio#5 - PWM y Librerias
//HARDWARE: ATMEGA328P
//CREADO: 16/04/2024
//�LTIMA MODIFICACI�N: 18/04/2024 - 16:23
//******************************************************************************************************************

//******************************************************************************************************************
//LIBRERIAS	
//******************************************************************************************************************
#define F_CPU 16000000	 // Frecuencia de reloj de 16 MHz

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Incluir las librerias trabajadas
#include "PWM0/PWM0.h"
#include "PWM1/PWM1.h"
#include "PWM2/PWM2.h"
#include "ADC/ADC.h"



//Se declaran las variables para los valores de ADC y el ciclo de trabajo ---> El valor de la variable inicializa en 0
float ADC_V1 = 0;			//Variable que lee el valor del PIN PC0

uint8_t ADC_V2 = 0;			//Variable que lee el valor del PIN PC1

float ADC_V3 = 0;			//Variable que lee el valor del PIN PC4

int main(void)
{
	cli();
	DDRD = 0xFF;			//Configuraci�n del puerto D
	
	TCCR2A = 0;
	TCCR2B = 0;
	
	//Se llaman a las librerias establecidas en ADC y PWM1
	ADC_init();
	PWM0_init();
	PWM1_initial();
	PWM2_initial(NO_INVERTIDO,1024);

	sei();

	while (1)
	{
		//Configuraci�n Servomotor#1 - PB1
		ADC_V1 = ADC_read(0);		//Lee el canal 0 del puerto C (PC0)
		servo_moA1(ADC_V1);			//Realiza la se�al del canal A
		_delay_ms(10);				//Implementar un delay de 10ms para que el giro del servo sea m�s fluido
		
		ADC_V2 = ADC_read(1);		//Lee el canal 2 del puerto C (PC1)
		servo_mo2(ADC_V2);			//Realiza la se�al del canal A
		_delay_ms(10);				//Implementar un delay de 10ms
		
		ADC_V3 = ADC_read(4);					//Lee el canal 4 del puerto C (PC4)
		ADC_V3 = (ADC_V3 * 100)/1023;			//ADC de 10 Bits -> Se realiza una conversi�n para trabajar al 100%
		PWM0_dca((uint8_t)ADC_V3, NO_INVERTIDO);
		_delay_ms(10);	

	}
}

ISR(ADC_vect){
	ADCSRA |= (1 << ADIF);	//Limpiar la bandera al encender el ADC
}




