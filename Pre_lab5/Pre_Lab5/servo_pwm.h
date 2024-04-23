//******************************************************************************************************************
//UNIVERSIDAD DEL VALLE DE GUATEMALA
//IE2023: PROGRAMACIÓN DE MICROCONTROLADORES
//Archivo: servo_pwm.h
//AUTOR: Guillermo José Schwartz López
//Libreria_PWM_h
//HARDWARE: ATMEGA328P
//******************************************************************************************************************


#ifndef SERVO_PWM_H
#define SERVO_PWM_H

#include <avr/io.h>

// Función para inicializar el PWM para el control del servo
void servo_pwm_init();

// Función para establecer el ciclo de trabajo del PWM para controlar la posición del servo
void servo_set_position(uint16_t position);

#endif