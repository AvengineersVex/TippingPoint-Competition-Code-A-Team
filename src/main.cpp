/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\108499                                           */
/*    Created:      Mon Dec 13 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"
#include "rerun.h"
#include "autonomous.h"

using namespace vex;

competition Competition;

void pre_auton(void)
{

}

void autonomous() {
  autonomousProgram();
}

int main()
{  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // pre_auton();

  // Rerun Program
  // rerun();

  // Autonomous Program
  // autonomousProgram();

  while(true)
  {
    wait(100, msec);
  }
}