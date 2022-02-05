#include "vex.h"
#include "rerun.h"

using namespace vex;

// Defined in robot-config.cpp
extern controller Controller1;
extern motor LeftDriveSmart;
extern motor RightDriveSmart;
extern motor scissorLift1;
extern motor scissorLift2;

void scissorLiftControl()
{
  // code 1 - press down hold to turn

  if(Controller1.ButtonR1.pressing())
  {
      scissorLift1.spin(forward, -20, percentUnits::pct);
      scissorLift2.spin(forward, -20, percentUnits::pct);
      scissorLift3.spin(forward, -20, percentUnits::pct);
  }

  else if(Controller1.ButtonR2.pressing())
  {
      scissorLift1.spin(forward, 10, percentUnits::pct);
      scissorLift2.spin(forward, 10, percentUnits::pct);
      scissorLift3.spin(forward, 10, percentUnits::pct);
  }
  else
  {
    scissorLift1.setStopping(hold);
    scissorLift1.stop();

    scissorLift2.setStopping(hold);
    scissorLift2.stop();
  }

}

void hookControl()
{
  if(Controller1.ButtonL1.pressing())
  {
    Hook.spin(forward, 100, percentUnits::pct);
  }
  else if(Controller1.ButtonL2.pressing())
  {
    Hook.spin(forward, -100, percentUnits::pct);
  }
  else
  {
    Hook.setStopping(coast);
    Hook.stop();
  }
}

void conveyorControl()
{
  if(Controller1.ButtonA.pressing())
  {
    Conveyor.spin(forward, -100, percentUnits::pct);
  }
  else if(Controller1.ButtonB.pressing())
  {
    Conveyor.spin(forward, 100, percentUnits::pct);
  }
  else
  {
    Conveyor.setStopping(coast);
    Conveyor.stop();
  }
}

void drivetrainControl() {
    float verticalAxis = Controller1.Axis3.position();
    float horizontalAxis = Controller1.Axis1.position();
    
    float leftDriveRatio;
    float rightDriveRatio;
    
    /*
    -100 (left) : 100 (right)
    
    -100 - -100:100
     -50 -    0:100
       0 -  100:100
      50 -  100:0
     100 -  100:-100
    */
    
    if(horizontalAxis >= 0)
    {
      leftDriveRatio = 100;
      rightDriveRatio = 100 - (horizontalAxis * 2);
    }
    else
    {
      leftDriveRatio = 100 + (horizontalAxis * 2);
      rightDriveRatio = 100;
    }
    
    RightDriveSmart.spin(directionType::fwd, rightDriveRatio * verticalAxis / 100, velocityUnits::pct);
    LeftDriveSmart.spin(directionType::fwd, leftDriveRatio * verticalAxis / 100, velocityUnits::pct);
}

void usercontrol()
{
  RightDriveSmart.setVelocity(0, velocityUnits::pct);
  LeftDriveSmart.setVelocity(0, velocityUnits::pct);

  while (true)
  {
    drivetrainControl();
    scissorLiftControl();
    hookControl();
    conveyorControl();

    wait(20, msec);
  }
}