/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: ZombieRobot
 * Description: This file contain function implementations for zombie robot
 */

#include "ZombieRobot.h"

void zombie_robot_initialize(const zombie_robot_t* robot)
{
    ultrasonic_initialize(&(robot->ultrasonic));
    motor_initialize(&(robot->motor_left));
    motor_initialize(&(robot->motor_right));
}

void zombie_robot_move_forward(const zombie_robot_t* robot)
{
    motor_turn_forward(&(robot->motor_left));
    motor_turn_forward(&(robot->motor_right));
}

void zombie_robot_move_left(const zombie_robot_t* robot)
{
    motor_turn_backward(&(robot->motor_left));
    motor_turn_forward(&(robot->motor_right));
}

void zombie_robot_move_right(const zombie_robot_t* robot)
{
    motor_turn_backward(&(robot->motor_right));
    motor_turn_forward(&(robot->motor_left));
}
