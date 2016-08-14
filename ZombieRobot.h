/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: ZombieRobot
 * Description: This file contain function declarations also macros and data structures for zombie robot
 */

#ifndef _ZOMBIE_ROBOT_
#define _ZOMBIE_ROBOT_

#include "Motor.h"
#include "Ultrasonic.h"

typedef struct
{
    ultrasonic_t ultrasonic;
    motor_t motor_left;
    motor_t motor_right;
} zombie_robot_t;

void zombie_robot_initialize(const zombie_robot_t* robot);
void zombie_robot_move_forward(const zombie_robot_t* robot);
void zombie_robot_move_left(const zombie_robot_t* robot);
void zombie_robot_move_right(const zombie_robot_t* robot);

#endif