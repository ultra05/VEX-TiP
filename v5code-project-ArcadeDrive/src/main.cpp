/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Clamp                motor         1               
// BackLift             motor         4               
// LeftDrive            motor_group   9, 20           
// RightDrive           motor_group   6, 10           
// FBLift               motor_group   2, 8            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

  // leftDrive.spin(forward, 50, percent);
  // rightDrive.spin(forward, 50, precent);
  // wait(2,sec);
  // leftDrive.stop();
  // rightDrive.stop();


  //--------AUTO 1-------------
  // Clamp.spinFor(directionType::rev, 1, rotationUnits::rev, 70, velocityUnits::pct);

  // LeftDrive.spinFor(directionType::fwd, 1, rotationUnits::rev, 50, velocityUnits::pct, false);
  // RightDrive.spinFor(directionType::fwd, 1, rotationUnits::rev, 50, velocityUnits::pct);
  // Clamp.spinFor(directionType::fwd, 0.7, rotationUnits::rev, 70, velocityUnits::pct);

  // LeftDrive.spinFor(directionType::fwd, 1.7, rotationUnits::rev, 50, velocityUnits::pct, false);
  // RightDrive.spinFor(directionType::rev, 1.7, rotationUnits::rev, 50, velocityUnits::pct);

  // LeftDrive.spinFor(directionType::fwd, 1, rotationUnits::rev, 50, velocityUnits::pct, false);
  // RightDrive.spinFor(directionType::fwd, 1, rotationUnits::rev, 50, velocityUnits::pct);

  // Clamp.spinFor(directionType::rev, 0.7, rotationUnits::rev, 70, velocityUnits::pct);

  // LeftDrive.spinFor(directionType::rev, 2, rotationUnits::rev, 70, velocityUnits::pct, false);
  // RightDrive.spinFor(directionType::rev, 2, rotationUnits::rev, 70, velocityUnits::pct);

  // LeftDrive.spinFor(directionType::fwd, 1.83, rotationUnits::rev, 50, velocityUnits::pct, false);
  // RightDrive.spinFor(directionType::rev, 1.83, rotationUnits::rev, 50, velocityUnits::pct );

  // BackLift.spinFor(directionType::fwd, 2.6, rotationUnits::rev, 60, velocityUnits::pct);

  // LeftDrive.spinFor(directionType::rev, 2, rotationUnits::rev, 70, velocityUnits::pct, false);
  // RightDrive.spinFor(directionType::rev, 2, rotationUnits::rev, 70, velocityUnits::pct);


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  
  int deadBand = 5;
  while (1) {
    
    int leftMotorSpeed = Controller1.Axis1.position() + Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis1.position() - Controller1.Axis3.position();
    
    if (abs(leftMotorSpeed) < deadBand) {
      LeftDrive.setVelocity(0,percent);
    } else {
      LeftDrive.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < deadBand) {
      RightDrive.setVelocity(0,percent);
    } else {
      RightDrive.setVelocity(rightMotorSpeed, percent);
    }

    if (Controller1.ButtonL1.pressing()){
      FBLift.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    } else if (Controller1.ButtonL2.pressing()){
      FBLift.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    } else {
      FBLift.stop(brakeType::hold);
    }


    if (Controller1.ButtonR1.pressing()){
      Clamp.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
    } else if (Controller1.ButtonR2.pressing()){
      Clamp.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
    } else {
      Clamp.stop(brakeType::hold);
    }

    if (Controller1.ButtonUp.pressing()){
      BackLift.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    } else if (Controller1.ButtonDown.pressing()){
      BackLift.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    } else {
      BackLift.stop(brakeType::hold);
    }


    LeftDrive.spin(forward);
    RightDrive.spin(forward);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
