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
    if(Controller.ButtonUp.pressing()) {
      break;
    }
  }
  
  while(true) {
//   for(int i = 0; i < 10; i ++) {

    // autonomousProgram << "motor1.spin(fwd, " << motor1.velocity() << ", pct" << std::endl;
    // autonomousProgram << "motor2.spin(fwd, " << motor2.velocity() << ", pct" << std::endl;
    // autonomousProgram << "motor3.spin(fwd, " << motor3.velocity() << ", pct" << std::endl;
    // autonomousProgram << "motor4.spin(fwd, " << motor4.velocity() << ", pct" << std::endl;
    autonomousProgram << "motor1.spin(fwd, " << 1 << ", pct)" << std::endl;
    autonomousProgram << "motor2.spin(fwd, " << 2 << ", pct)" << std::endl;
    autonomousProgram << "motor3.spin(fwd, " << 3 << ", pct)" << std::endl;
    autonomousProgram << "motor4.spin(fwd, " << 4 << ", pct)" << std::endl;

    // currentTime = Brain.timer.system;
    // timeDifference = currentTime - previousTime;
    // previousTime = Brain.timer.system;
    currentTime = 20;
    timeDifference = currentTime - previousTime;
    previousTime = 10;

    autonomousProgram << "task::sleep(" << timeDifference << ");" << std::endl << std::endl;
    
    if(Controller.ButtonDown.pressing()) {
      break;
    }
  }

  autonomousProgram.close();
}
