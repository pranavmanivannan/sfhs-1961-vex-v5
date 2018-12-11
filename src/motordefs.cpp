#include "main.h"
#include "motordefs.hpp"

//defining which controller to call when calling master
pros::Controller master (pros::E_CONTROLLER_MASTER);

//giving ports to motors
pros::Motor frontRight(1);
pros::Motor middleRight(2);
pros::Motor backRight(3);
pros::Motor frontLeft(5);
pros::Motor middleLeft(6);
pros::Motor backLeft(7);
pros::Motor intake(9);
pros::Motor catapult(10);

//giving ports to sensors
pros::ADIDigitalIn catapultLimit('a');
pros::ADIDigitalIn potentiometer('b');
