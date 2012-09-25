#ifndef MEROBOT_H
#define MEROBOT_H

#include <iostream>
#include "world.h"
#include "sequence.h"


/*
  This class is interface to main window
  This class receive some structure from main window.
  The structure contain target angle of robot pose, inputed by gui part.

  This class is robot. But not inherit "robot class". (robot class is our another project for soccer game robot)
  Because robot class should decide next action by itself, so there is many "wasted" part for motion editor robot.

  -------robot.h------ autonomous soccer player agent ----- this tool aim to use outcome in robot as player
  This class is interface to main function.
  This class receive string from server(include what the robot sensor observed).
  And return message to server(include how the robot want to move his joint).
  Process (ex.interpret string, decide action, calculate joint angle) is subclass's task, so this class has few work.
 */
class meRobot{
 public:
  meRobot(std::string teamname);
  ~meRobot();

  std::string Init(){
    // inform server to use nao model
    return "(scene rsg/agent/nao/nao.rsg)";
  }

  std::string Init2(); // send teamname

  std::string getNextAngle(std::string &msg);

  void setSequence(Sequence newSeq);

 protected:
  World world;
};

#endif
