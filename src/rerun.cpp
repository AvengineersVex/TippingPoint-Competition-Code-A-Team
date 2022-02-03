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

    // autonomousProgram << "motor1.setVelocity(" << motor1.velocity() << ", pct" << std::endl;
    // autonomousProgram << "motor2.setVelocity(" << motor2.velocity() << ", pct" << std::endl;
    // autonomousProgram << "motor3.setVelocity(" << motor3.velocity() << ", pct" << std::endl;
    // autonomousProgram << "motor4.setVelocity(" << motor4.velocity() << ", pct" << std::endl;
    autonomousProgram << "motor1.setVelocity(" << 1 << ", pct)" << std::endl;
    autonomousProgram << "motor2.setVelocity(" << 2 << ", pct)" << std::endl;
    autonomousProgram << "motor3.setVelocity(" << 3 << ", pct)" << std::endl;
    autonomousProgram << "motor4.setVelocity(" << 4 << ", pct)" << std::endl;

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
