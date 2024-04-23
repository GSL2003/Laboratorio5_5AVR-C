/*
 * PWM0.c
 *
 * Created: 20/04/2024 21:52:33
 *  Author: Guillermo Schwartz
 */ 

//En esta liberia se configura la implementación de las funciones prototipo

#include "PWM0.h"

void PWM0_init(void)
{
	// Modo Fast PWM
	TCCR0B &= ~(1<<WGM02);
	TCCR0A |= (1<<WGM01);
	TCCR0A |= (1<<WGM00);
	
	// Prescalador 64
	TCCR0B &= ~(1<<CS02);
	TCCR0B |= (1<<CS01);
	TCCR0B |= (1<<CS00);
}

void PWM0_dca(uint8_t dc, uint8_t modo)
{
	if(modo == 1)				//La salida del PWM es NO INVERTIDA
	{
		TCCR0A |= (1<<COM0A1);
		TCCR0A &= ~(1<<COM0A0);
	}
	else                        //Es INVERTIDA
	{
		TCCR0A |= (1<<COM0A1);
		TCCR0A |= (1<<COM0A0);
		
	}
	OCR0A = (dc * 255) / 100;				//Configuración del cilo del trabajo
}

void PWM0_dcb(uint8_t dc, uint8_t modo)
{
	if(modo == 1)
	{
		TCCR0A |= (1<<COM0B1);
		TCCR0A &= ~(1<<COM0B0);
	}
	else
	{
		TCCR0A |= (1<<COM0B1);
		TCCR0A |= (1<<COM0B0);
		
	}
	OCR0B = (dc * 255) / 100;
	
}