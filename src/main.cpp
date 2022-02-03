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

using namespace vex;

competition Competition;

void pre_auton(void)
{
  vexcodeInit();
}

void autonomous(void)
{
  //rerun
  rerun();
}

void initDrive(void)
{
  while(true)
  {
    usercontrol();
    wait(20, msec);
  }
}

int main()
{  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(initDrive);

  pre_auton();

  // Rerun Program
  autonomous();

  while(true)
  {
    wait(100, msec);
  }
}