#include "merobot.h"

meRobot::meRobot(std::string teamname){
  world.setTeamname(teamname);

}

meRobot::~meRobot(){}

std::string meRobot::getNextAngle(std::string &msg){


  return "";
}

std::string meRobot::Init2(){
  return "(init (unum 0)(teamname " + world.getTeamname() + "))";
}
