using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Clamp;
extern motor BackLift;
extern motor_group LeftDrive;
extern motor_group RightDrive;
extern motor_group FBLift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );