#include "vex.h"

using namespace vex;

// Defined in robot-config.cpp
extern controller Controller1;
extern motor LeftDriveSmart;
extern motor RightDriveSmart;
extern motor ScissorLift;
extern motor Conveyor;

rotationUnits maxRotation;

void scissorLiftRotate() {

}  

void scissorLiftRotateBack()
{
  while (ScissorLift.position(deg) > 30 && ScissorLift.position(deg) < 90)
  {
    ScissorLift.spinToPosition(90, degrees);
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

    ScissorLift.setVelocity(100, pct);
    Controller1.ButtonR1.pressed(scissorLiftRotate);
    Controller1.ButtonR2.pressed(scissorLiftRotateBack);

      // Move lift up
      // ScissorLift.RotateDown
      // if(ScissorsLift.rotation < minRotation) {
      // Stop rotation
      // }

    }

    if(Controller1.ButtonL1.pressing()) {
      // Move hook up

    }

    if(Controller1.ButtonL2.pressing()) {
      // Move hook down

    }

    if(Controller1.ButtonX.pressing()) {
      // Rotate conveyor forward

    }

    if(Controller1.ButtonB.pressing()) {
      // Rotate conveyor backward

    }
  }
