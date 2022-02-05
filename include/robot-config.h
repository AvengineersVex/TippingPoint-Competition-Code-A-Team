using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftDriveSmart;
extern motor RightDriveSmart;
extern drivetrain Drivetrain;
extern controller Controller1;
extern motor scissorLift1;
extern motor scissorLift2;
extern motor scissorLift3;
extern motor Hook;
extern motor Conveyor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );