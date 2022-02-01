using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;
extern motor ScissorLift;
extern motor Hook;
extern motor Conveyor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );