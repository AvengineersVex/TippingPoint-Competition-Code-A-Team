#include "vex.h"
using namespace vex;

extern brain Brain;
extern brain::lcd Screen;

void pressedCallback();
void detectAlliance(int xPosIn, int yPosIn);
void autonSlector();
int gOp(int xPosIn, int yPosIn);

int progress, alliance, auton;

int returnAutonSelection() {
  return auton;
}

int returnAllianceSelection() {
  return alliance;
}
void startUp() {
  progress = 0;
  Screen.pressed(pressedCallback);
  Screen.setFont(prop40);
  Screen.printAt(130, 50, "Alliance Color");
  Screen.drawRectangle(100, 80, 100, 80, red);
  Screen.drawRectangle(280, 80, 100, 80, blue);
  Screen.drawRectangle(0, 180, 480, 50, green);
  Screen.setFont(prop20);
  Screen.printAt(210, 210, "Skills");
}

void pressedCallback() {
  int xPos = Screen.xPosition();
  int yPos = Screen.yPosition();
  if (progress == 0) {
    detectAlliance(xPos, yPos);
  }
  else if (progress == 2) {
    printf("gOp activated\n");
    auton = gOp(xPos, yPos);
  }
}

void detectAlliance(int xPosIn, int yPosIn) {
  if (100 < xPosIn && xPosIn < 200 && 80 < yPosIn && yPosIn < 160) { // Red Alliance
    Screen.clearScreen();
    progress++;
    alliance = 0;
  }
  else if (280 < xPosIn && xPosIn < 380 && 80 < yPosIn && yPosIn < 160) { // Blue Alliance
    Screen.clearScreen();
    progress++;
    alliance = 1;
  }
  else if (0 < xPosIn && xPosIn < 480 && 180 < yPosIn && yPosIn < 240) { // Skills 
    Screen.clearScreen();
    progress++;
    alliance = 2;
  }
  autonSlector();
}

void autonSlector() {
  Screen.setFont(prop40);
  if (alliance == 0) { // Red Alliance
    Screen.printAt(110, 50, "Auton Selection");
    Screen.drawRectangle(100, 80, 100, 80, purple);
    Screen.drawRectangle(280, 80, 100, 80, yellow);
    progress++;
  }
  else if (alliance == 1) { // Blue Alliance
    Screen.printAt(110, 50, "Auton Selection");
    Screen.drawRectangle(100, 80, 100, 80, purple);
    Screen.drawRectangle(280, 80, 100, 80, yellow);
    progress++;
  }
}

int gOp(int xPosIn, int yPosIn) {
  if (100 < xPosIn && xPosIn < 200 && 80 < yPosIn && yPosIn < 160) {
    Screen.clearScreen();
    return 0;
  }
  else if (280 < xPosIn && xPosIn < 380 && 80 < yPosIn && yPosIn < 160) {
    Screen.clearScreen();
    return 1;
  }
  return -1;
}
