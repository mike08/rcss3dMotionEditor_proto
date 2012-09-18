#include "merobot.h"
#include <sstream>

meRobot::meRobot(std::string teamname){
  world.setTeamname(teamname);

}

meRobot::~meRobot(){}

std::string meRobot::getNextAngle(std::string &msg){

    std::stringstream ss; // return value

    /*
    if(mesi->getUsingEditor() == 0){
        // pose editing
        // Pose temppose = mesi->getPose();
        // ss << walking.poseAction(temppose)
    }

    if( mesi->getBeaming() == true){
        ss << "(beam -1.0 -3 0)";
    }
    */

    return ss.str();
}

std::string meRobot::Init2(){
  return "(init (unum 0)(teamname " + world.getTeamname() + "))";
}

void meRobot::saveMeSIpointer(meSharedInformation *mesip){
//    mesi = mesip;
}
