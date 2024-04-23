//******************************************************************************************************************
//UNIVERSIDAD DEL VALLE DE GUATEMALA
//IE2023: PROGRAMACIÓN DE MICROCONTROLADORES
//Archivo: Prelab_4
//AUTOR: Guillermo José Schwartz López
//Laboratorio#5 - PWM y Librerias
//HARDWARE: ATMEGA328P
//CREADO: 15/04/2024
//ÚLTIMA MODIFICACIÓN: 16/04/2024 - 07:05
//******************************************************************************************************************

//******************************************************************************************************************
//LIBRERIAS	
//******************************************************************************************************************
#define F_CPU 16000000	 // Frecuencia de reloj de 16 MHz

#include <avr/io.h>
#include <util/delay.h>

//Incluir las librerias trabajadas
#include "PWM1/PWM1.h"
#include "ADC/ADC.h"

//Se declaran las variables para los valores de ADC y el ciclo de trabajo ---> El valor de la variable inicializa en 0
float ADC_V1 = 0;			//Variable que lee el valor del PIN PC0

float dutyCycle = 0;		//Variable que contiene el ciclo de trebajo	

int main(void)
{
	DDRD = 0xFF;			//Configuración del puerto D
	
	//Se llaman a las librerias establecidas en ADC y PWM1
	ADC_init();
	PWM_initial();

	while (1)
	{
		//Configuración Servomotor#1 - PB1
		ADC_V1 = ADC_read(0);		//Lee el canal 0 del puerto C (PC0)
		servo_moB1(ADC_V1);			//Realiza la señal del canal A
		_delay_ms(10);				//Implementar un delay de 10ms para que el giro del servo sea más fluido

	}
}


