#include "vex.h"

using namespace vex;

// Defined in robot-config.cpp
extern controller Controller1;
extern motor LeftDriveSmart;
extern motor RightDriveSmart;
extern motor scissorLift;

void scissorLiftFWD(void)
{
  if(Controller1.ButtonL1.pressing())
  {
    scissorLift.spin(fwd);
  }
  if(!Controller1.ButtonL1.pressing())
  {
    scissorLift.setStopping(brake);
    scissorLift.stop();
  }
}

void scissorLiftREV(void)
{
  if(Controller1.ButtonL2.pressing())
  {
    scissorLift.spin(reverse);
  }
  if(!Controller1.ButtonL2.pressing())
  {
    scissorLift.setStopping(brake);
    scissorLift.stop();
  }
}

void scissorLiftControl(void)
{
  //code 1 - press down hold to turn

  // double maxRotationInDeg = 0;
  // double minRotationInDeg = 0;

  // if(Controller1.ButtonL1.pressing())
  // {
    
  //   scissorLift.spin(forward, 12.0, voltageUnits::volt);
  // }

  // else if(Controller1.ButtonL2.pressing())
  // {
  //   scissorLift.spin(forward, -12.0, voltageUnits::volt);
  // }
  // else
  // {
  //   scissorLift.spin(forward, 0, voltageUnits::volt);
  // }

  //code 2 - press down and hold to turn
  scissorLiftFWD();
  scissorLiftREV();
  
  //code 3 - tap to turn to preset position

}

void liftControl(void)
{

}

void usercontrol(void)
{
  RightDriveSmart.spin(fwd);
  LeftDriveSmart.spin(fwd);
  
  RightDriveSmart.setVelocity(0, velocityUnits::pct);
  LeftDriveSmart.setVelocity(0, velocityUnits::pct);
  
  while (true)
  {
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
    
    RightDriveSmart.setVelocity(rightDriveRatio * verticalAxis / 100, velocityUnits::pct);
    LeftDriveSmart.setVelocity(leftDriveRatio * verticalAxis / 100, velocityUnits::pct);
  
    scissorLiftControl();
    
    liftControl();

    wait(20, msec);
  }
}