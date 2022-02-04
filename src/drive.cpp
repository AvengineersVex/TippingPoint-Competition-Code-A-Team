#include "vex.h"
#include "rerun-old.h"

using namespace vex;

// Defined in robot-config.cpp
extern controller Controller1;
extern motor LeftDriveSmart;
extern motor RightDriveSmart;
extern motor scissorLift1;
extern motor scissorLift2;

bool hooked = false;

void scissorLiftFWD(void)
{
  if(Controller1.ButtonR1.pressing())
  {
    scissorLift1.spin(fwd);
    scissorLift2.spin(fwd);
  }
  if(!Controller1.ButtonR1.pressing())
  {
    scissorLift1.setStopping(brake);
    scissorLift1.stop();

    scissorLift1.setStopping(brake);
    scissorLift1.stop();
  }
}

void scissorLiftREV(void)
{
  if(Controller1.ButtonR2.pressing())
  {
    scissorLift1.spin(reverse);
    scissorLift2.spin(reverse);
  }
  if(!Controller1.ButtonR2.pressing())
  {
    scissorLift1.setStopping(brake);
    scissorLift1.stop();

    scissorLift2.setStopping(brake);
    scissorLift2.stop();
  }
}

void scissorLiftControl(void)
{
  // code 1 - press down hold to turn

  if(Controller1.ButtonL1.pressing())
  {
      scissorLift1.spin(forward, 100, percentUnits::pct);
      scissorLift2.spin(forward, 100, percentUnits::pct);
  }

  else if(Controller1.ButtonL2.pressing())
  {
      scissorLift1.spin(forward, -100, percentUnits::pct);
      scissorLift2.spin(forward, -100, percentUnits::pct);
  }
  else
  {
    scissorLift1.setStopping(hold);
    scissorLift1.stop();

    scissorLift2.setStopping(hold);
    scissorLift2.stop();
  }

  //code 2 - press down and hold to turn
  // scissorLiftFWD();
  // scissorLiftREV();
  
  //code 3 - tap to turn to preset position

}

void hook(void)
{
  if(Controller1.ButtonR1.pressing())
  {
    Hook.setVelocity(100, pct);
    Hook.startRotateTo(90, deg);
  }
  if(Controller1.ButtonR2.pressing())
  {
    Hook.setVelocity(100, pct);
    Hook.startRotateTo(-90, deg);
  }
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
    hook();

    // rerun();

    wait(20, msec);
  }
}