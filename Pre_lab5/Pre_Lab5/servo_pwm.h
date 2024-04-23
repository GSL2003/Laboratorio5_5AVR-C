//******************************************************************************************************************
//UNIVERSIDAD DEL VALLE DE GUATEMALA
//IE2023: PROGRAMACI�N DE MICROCONTROLADORES
//Archivo: servo_pwm.h
//AUTOR: Guillermo Jos� Schwartz L�pez
//Libreria_PWM_h
//HARDWARE: ATMEGA328P
//******************************************************************************************************************


#ifndef SERVO_PWM_H
#define SERVO_PWM_H

#include <avr/io.h>

// Funci�n para inicializar el PWM para el control del servo
void servo_pwm_init();

// Funci�n para establecer el ciclo de trabajo del PWM para controlar la posici�n del servo
void servo_set_position(uint16_t position);

#endif