#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Clamp = motor(PORT1, ratio36_1, true);
motor BackLift = motor(PORT4, ratio18_1, true);
motor LeftDriveMotorA = motor(PORT9, ratio18_1, false);
motor LeftDriveMotorB = motor(PORT20, ratio18_1, false);
motor_group LeftDrive = motor_group(LeftDriveMotorA, LeftDriveMotorB);
motor RightDriveMotorA = motor(PORT6, ratio18_1, false);
motor RightDriveMotorB = motor(PORT10, ratio18_1, false);
motor_group RightDrive = motor_group(RightDriveMotorA, RightDriveMotorB);
motor FBLiftMotorA = motor(PORT2, ratio36_1, false);
motor FBLiftMotorB = motor(PORT8, ratio36_1, true);
motor_group FBLift = motor_group(FBLiftMotorA, FBLiftMotorB);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}