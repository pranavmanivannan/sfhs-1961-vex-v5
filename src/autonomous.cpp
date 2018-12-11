#include "main.h"
#include "motordefs.hpp"
#include "motordefs.cpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void moveForward()
{
  frontRight = 200;
  middleRight = 200;
  backRight = 200;
  frontLeft = 200;
  middleLeft = 200;
  backLeft = 200;
  pros::delay(600);
}

void moveBackward()
{
  frontRight = -200;
  middleRight = -200;
  backRight = -200;
  frontLeft = -200;
  middleLeft = -200;
  backLeft = -200;
  pros::delay(600);
}

void turnRight()
{
  frontRight = -200;
  middleRight = -200;
  backRight = -200;
  frontLeft = 200;
  middleLeft = 200;
  backLeft = 200;
  pros::delay(500);
}

void turnLeft()
{
  frontRight = 200;
  middleRight = 200;
  backRight = 200;
  frontLeft = -200;
  middleLeft = -200;
  backLeft = -200;
  pros::delay(500);
}

void startCatapult()
{
  while(!catapultLimit.get_value())
  {
      catapult = 100;
  }
  {
      catapult = 23;
  }
}

void startIntake()
{
  intake = -600;
}

void autonomous()
{
  startIntake();
  startCatapult();
  moveBackward();
  pros::delay(600);
  moveForward();
  pros::delay(1000);
  turnLeft();
  pros::delay(300);
  catapult = 100;
  pros::delay(500);
  moveForward();
  pros::delay(700);

}
