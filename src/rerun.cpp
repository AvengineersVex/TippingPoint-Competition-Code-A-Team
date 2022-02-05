#include "vex.h"
#include <iostream>
#include <fstream>
#include "drive.h"

using namespace vex;

extern controller Controller1;
extern motor LeftDriveSmart;
extern motor RightDriveSmart;
extern motor scissorLift1;
extern motor scissorLift2;

void rerun() {
  
  RightDriveSmart.spin(fwd);
  LeftDriveSmart.spin(fwd);
  
  RightDriveSmart.setVelocity(0, velocityUnits::pct);
  LeftDriveSmart.setVelocity(0, velocityUnits::pct);
  
  u_long currentTime, previousTime, timeDifference;

  // std::fstream autonomousProgram;
  // autonomousProgram.open("autonomous.cpp", std::ios::out);
  // if(autonomousProgram.fail()) {
  //   std::cerr << "File not found\n";
  // }

  std::cout << "#include \"vex.h\"\n\n";
  std::cout << "using namespace vex;\n\n";
  std::cout << "void autonomousProgram() {\n\n";
  
  // while(true) {
  for(int i = 0; i < 1000; i ++) {
    drivetrainControl();
    scissorLiftControl();
    hookControl();
    conveyorControl();
    
    std::cout << "\tscissorLift1.spin(fwd, " << scissorLift1.velocity(pct) << ", pct);" << std::endl;
    std::cout << "\tscissorLift2.spin(fwd, " << scissorLift2.velocity(pct) << ", pct);" << std::endl;
    std::cout << "\tHook.spin(fwd, " << Hook.velocity(pct) << ", pct);" << std::endl;
    std::cout << "\tConveyor.spin(fwd, " << Conveyor.velocity(pct) << ", pct);" << std::endl;
    std::cout << "\tLeftDriveSmart.spin(fwd, " << LeftDriveSmart.velocity(pct) << ", pct);" << std::endl;
    std::cout << "\tRightDriveSmart.spin(fwd, " << RightDriveSmart.velocity(pct) << ", pct);" << std::endl;

    // std::cout << "\tscissorLift1.spin(fwd, " << 1 << ", pct);\n";
    // std::cout << "\tscissorLift2.spin(fwd, " << 2 << ", pct);\n";
    // std::cout << "\tHook.spin(fwd, " << 3 << ", pct);\n";
    // std::cout << "\tConveyor.spin(fwd, " << 4 << ", pct);\n";
    // std::cout << "\tLeftDriveSmart.spin(fwd, " << 4 << ", pct);\n";
    // std::cout << "\tRightDriveSmart.spin(fwd, " << 4 << ", pct);\n";

    currentTime = timer::system();
    timeDifference = currentTime - previousTime;
    previousTime = timer::system();
    // currentTime = 20;
    // timeDifference = currentTime - previousTime;
    // previousTime = 10;

    std::cout << "\ttask::sleep(" << timeDifference << ");\n\n";

    if(Controller1.ButtonDown.pressing()) {
      break;
    }

    wait(100, msec);
  }

  std::cout << "}";
  // autonomousProgram.close();
}
