#ifndef MOTORDEFS_H
#define MOTORDEFS_H
#include "main.h"

//define which controller you are using to call input from
extern pros::Controller master;

//motor definitions
extern pros::Motor frontRight;
extern pros::Motor middleRight;
extern pros::Motor backRight;
extern pros::Motor frontLeft;
extern pros::Motor middleLeft;
extern pros::Motor backLeft;
extern pros::Motor intake;
extern pros::Motor catapult;

//sensor definitions
extern pros::ADIDigitalIn catapultLimit;
extern pros::ADIDigitalIn potentiometer;

#endif
