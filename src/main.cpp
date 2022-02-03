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

int main() {
  
  Competition.drivercontrol(usercontrol);
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Rerun Program
  rerun();
}