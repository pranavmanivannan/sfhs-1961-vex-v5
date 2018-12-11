#include "main.h"
#include "motordefs.hpp"
#include "motordefs.cpp"
#include "api.h"
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
while(true){

int accel = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
int drift = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

//arcade drive control
frontRight.move(accel - drift);
middleRight.move(accel - drift);
backRight.move(accel - drift);
frontLeft.move(accel + drift);
middleLeft.move(accel + drift);
backLeft.move(accel + drift);

//intake control
if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
{
		intake.move(-600);
}
else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
{
		intake.move(600);
}
else
{
		intake.move(0);
}

//catapult control
if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
	{
		if(!catapultLimit.get_value())
		{
				catapult.move(100);
		}
		else if(catapultLimit.get_value())
		{
				catapult.move(23);
		}
else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
	{
				catapult.move(100);
	}


	}


		pros::delay(20);
	}
}
