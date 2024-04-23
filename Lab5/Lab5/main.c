//******************************************************************************************************************
//UNIVERSIDAD DEL VALLE DE GUATEMALA
//IE2023: PROGRAMACIÓN DE MICROCONTROLADORES
//Archivo: Lab5
//AUTOR: Guillermo José Schwartz López
//Laboratorio#5 - PWM y Librerias
//HARDWARE: ATMEGA328P
//CREADO: 16/04/2024
//ÚLTIMA MODIFICACIÓN: 18/04/2024 - 16:23
//******************************************************************************************************************

//******************************************************************************************************************
//LIBRERIAS	
//******************************************************************************************************************
#define F_CPU 16000000	 // Frecuencia de reloj de 16 MHz

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Incluir las librerias trabajadas
#include "PWM1/PWM1.h"

#include "PWM2/PWM2.h"

#include "ADC/ADC.h"

//Se declaran las variables para los valores de ADC y el ciclo de trabajo ---> El valor de la variable inicializa en 0
float ADC_V1 = 0;			//Variable que lee el valor del PIN PC0

uint8_t ADC_V2 = 0;

float dutyCycle = 0;		//Variable que contiene el ciclo de trabajo

float DutyC2 = 0;

void setup(void);

int main(void)
{
	cli();
	DDRD = 0xFF;			//Configuración del puerto D
	
	TCCR2A = 0;
	TCCR2B = 0;
	
	//Se llaman a las librerias establecidas en ADC y PWM1
	ADC_init();
	PWM1_initial();
	PWM2_initial(no_invertido,1024);
	setup();
	
	sei();

	while (1)
	{
		//Configuración Servomotor#1 - PB1
		ADC_V1 = ADC_read(0);		//Lee el canal 0 del puerto C (PC0)
		servo_moA1(ADC_V1);			//Realiza la señal del canal A
		_delay_ms(10);				//Implementar un delay de 10ms para que el giro del servo sea más fluido
		
		ADC_V2 = ADC_read(1);		//Lee el canal 0 del puerto C (PC1)
		servo_mo2(ADC_V2);			//Realiza la señal del canal A
		_delay_ms(10);				//Implementar un delay de 10ms

	}
}

void setup (void){
	UCSR0B = 0;		// Desabilita RX y TX
	DDRC = 0;		// Se configura el puerto C como entrada
}

ISR(ADC_vect){
	ADCSRA |= (1 << ADIF);	//Limpiar la bandera al encender el ADC
}




