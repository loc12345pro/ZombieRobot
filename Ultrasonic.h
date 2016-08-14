/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Ultrasonic
 * Description: This file contain function declarations also macros and data structures for 
 *  ultrasonic HR-SC04
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <stdint-gcc.h>

#define TRIGGER_TIME_US 10
#define CENTIMETER_UNIT 58
#define INCH_UNIT 148

typedef struct
{
    uint8_t trig_pin;
    uint8_t echo_pin;
} ultrasonic_t;

typedef enum 
{
    CENTIMETERS, 
    INCHES
} distance_unit_t;

void ultrasonic_initialize(const ultrasonic_t* ultra);
uint32_t ultrasonic_timing(const ultrasonic_t* ultra);
float ultrasonic_ranging_cm(const ultrasonic_t* ultra);
float ultrasonic_ranging_inch(const ultrasonic_t* ultra);

#endif

/* End of file */
