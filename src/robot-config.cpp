#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT17, ratio18_1, false);
motor RightDriveSmart = motor(PORT18, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 355.59999999999997, 330.2, mm, 0.625);
controller Controller1 = controller(primary);
motor scissorLift1 = motor(PORT11, ratio36_1, false);
motor scissorLift2 = motor(PORT13, ratio36_1, false);
motor Hook = motor(PORT15, ratio18_1, false);
motor Conveyor = motor(PORT9, ratio18_1, false);