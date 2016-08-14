/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Motor
 * Description: This file contain function implementations for ultrasonic motor
 */

#include "motor.h"
#include <Arduino.h>

void motor_initialize(const motor_t* motor)
{
    pinMode(motor->pin_one, OUTPUT);
    pinMode(motor->pin_two, OUTPUT);
}

void motor_brake(const motor_t* motor)
{
    digitalWrite(motor->pin_one, LOW);
    digitalWrite(motor->pin_two, LOW);
}

void motor_turn_forward(const motor_t* motor)
{
    digitalWrite(motor->pin_one, HIGH);
    digitalWrite(motor->pin_two, LOW);
}

void motor_turn_backward(const motor_t* motor)
{
    digitalWrite(motor->pin_one, LOW);
    digitalWrite(motor->pin_two, HIGH);
}
