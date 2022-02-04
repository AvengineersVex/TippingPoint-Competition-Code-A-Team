#include "vex.h"
#include <iostream>
#include <fstream>

using namespace vex;

void rerun() {

  int currentTime, previousTime, timeDifference;

  std::fstream autonomousProgram;
  autonomousProgram.open("autonomous.cpp", std::ios::out);
  if(autonomousProgram.fail()) {
    std::cerr << "File not found" << std::endl;
  }

  autonomousProgram << "#include \"vex.h\"" << std::endl << std::endl;
  autonomousProgram << "using namespace vex;" << std::endl << std::endl;
  
  while(true) {
    task::sleep(10);
    if(Controller1.ButtonUp.pressing()) {
      break;
    }
  }
  
  while(true) {
//   for(int i = 0; i < 10; i ++) {

    // autonomousProgram << "scissorLift1.spin(fwd, " << scissorLift1.velocity() << ", pct" << std::endl;
    // autonomousProgram << "scissorLift2.spin(fwd, " << scissorLift2.velocity() << ", pct" << std::endl;
    // autonomousProgram << "Hook.spin(fwd, " << Hook.velocity() << ", pct" << std::endl;
    // autonomousProgram << "Conveyor.spin(fwd, " << Conveyor.velocity() << ", pct" << std::endl;
    // autonomousProgram << "LeftDriveSmart.spin(fwd, " << LeftDriveSmart.velocity() << ", pct" << std::endl;
    // autonomousProgram << "RightDriveSmart.spin(fwd, " << RightDriveSmart.velocity() << ", pct" << std::endl;

    autonomousProgram << "scissorLift1.spin(fwd, " << 1 << ", pct)" << std::endl;
    autonomousProgram << "scissorLift2.spin(fwd, " << 2 << ", pct)" << std::endl;
    autonomousProgram << "Hook.spin(fwd, " << 3 << ", pct)" << std::endl;
    autonomousProgram << "Conveyor.spin(fwd, " << 4 << ", pct)" << std::endl;
    autonomousProgram << "LeftDriveSmart.spin(fwd, " << 4 << ", pct)" << std::endl;
    autonomousProgram << "RightDriveSmart.spin(fwd, " << 4 << ", pct)" << std::endl;

    // currentTime = Brain.timer.system;
    // timeDifference = currentTime - previousTime;
    // previousTime = Brain.timer.system;
    currentTime = 20;
    timeDifference = currentTime - previousTime;
    previousTime = 10;

    autonomousProgram << "task::sleep(" << timeDifference << ");" << std::endl << std::endl;
    
    if(Controller1.ButtonDown.pressing()) {
      break;
    }
  }

  autonomousProgram.close();
}
