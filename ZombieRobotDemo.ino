/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Main program
 * Description: Main program
 */

// Include header files
#include "ZombieRobot.h"

// Define macros
#define DISTANCE_CM 35
#define PIN_TRIGGER 8
#define PIN_ECHO 9

#define PIN_IN1 2
#define PIN_IN2 3
#define PIN_IN3 4
#define PIN_IN4 5

#define PIN_LED 13

// Declare variables
zombie_robot_t robot;

// Declare functions
zombie_robot_t zombie_robot_create();
motor_t motor_create(uint8_t pin_one, uint8_t pin_two);
ultrasonic_t ultrasonic_create(uint8_t pin_trigger, uint8_t pin_echo);

void setup() 
{
    // Initialize robot
    robot = zombie_robot_create();
    zombie_robot_initialize(&robot);

    // Initialize LED
    pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
    float calc_distance = ultrasonic_ranging_cm(&(robot.ultrasonic));
    if (calc_distance <= DISTANCE_CM)
    {
        digitalWrite(PIN_LED, HIGH);
        zombie_robot_move_right(&robot);
    }
    else
    {
        digitalWrite(PIN_LED, LOW);
        zombie_robot_move_forward(&robot);
    }
}

// Implement functions
zombie_robot_t zombie_robot_create()
{
    zombie_robot_t result;
    
    result.ultrasonic = ultrasonic_create(PIN_TRIGGER, PIN_ECHO);
    result.motor_left = motor_create(PIN_IN1, PIN_IN2);
    result.motor_right = motor_create(PIN_IN3, PIN_IN4);

    return result;
}

motor_t motor_create(uint8_t pin_one, uint8_t pin_two)
{
    motor_t result;

    result.pin_one = pin_one;
    result.pin_two = pin_two;

    return result;
}

ultrasonic_t ultrasonic_create(uint8_t pin_trigger, uint8_t pin_echo)
{
    ultrasonic_t result;

    result.trig_pin = pin_trigger;
    result.echo_pin = pin_echo;

    return result;
}
