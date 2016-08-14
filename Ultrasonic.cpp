/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Ultrasonic
 * Description: This file contain function implementations for ultrasonic HR-SC04
 */

#include <Arduino.h>
#include "Ultrasonic.h"

void ultrasonic_initialize(const ultrasonic_t* ultra)
{
    pinMode(ultra->echo_pin, INPUT);
    pinMode(ultra->trig_pin, OUTPUT);
}

uint32_t ultrasonic_timing(const ultrasonic_t* ultra)
{
    // Preparations
    uint32_t timing = 0;

    // Trig of SR04 must receive a pulse of high (5V) for at least 10us
    digitalWrite(ultra->trig_pin, HIGH);
    delayMicroseconds(TRIGGER_TIME_US);
    digitalWrite(ultra->trig_pin, LOW);

    // When the sensor detected ultrasonic from receiver, 
    // it will set the Echo pin to high (5V) and delay for a period (width) which proportion to distance.
    timing = pulseIn(ultra->echo_pin, HIGH);
    return timing;
}

float ultrasonic_ranging_cm(const ultrasonic_t* ultra)
{
    return 1.0 * ultrasonic_timing(ultra) / CENTIMETER_UNIT;
}

float ultrasonic_ranging_inch(const ultrasonic_t* ultra)
{
    return 1.0 * ultrasonic_timing(ultra) / INCH_UNIT;
}
