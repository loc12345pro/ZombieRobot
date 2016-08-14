/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Motor
 * Description: This file contain function declarations also macros and data structures for 
 *  motor
 */

#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint-gcc.h>

typedef struct 
{
    uint8_t pin_one;
    uint8_t pin_two;
} motor_t;

void motor_initialize(const motor_t* motor);
void motor_brake(const motor_t* motor);
void motor_turn_forward(const motor_t* motor);
void motor_turn_backward(const motor_t* motor);

#endif