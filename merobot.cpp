#include "merobot.h"
#include <sstream>

meRobot::meRobot(std::string teamname){
  world.setTeamname(teamname);

}

meRobot::~meRobot(){}

std::string meRobot::getNextAngle(std::string &msg){

    std::stringstream ss; // return value

    /*
    if( mesi->getBeaming() == true){
        ss << "(beam -1.0 -3 0)";
    }
    */

/*
    if(newOneComeFlag == true && doingSomeMovementFlag == false){
        doSeq = next_seq
        newOneComeFlag = false
    }

    if(newOnecomeFlag == false && doingSomeMovementFlag == false){
        // move any joint
    }

    if(doingSomeMovementFlag == true){
        // continue current movement (or stop and start new one)
    }

  */

    return ss.str();
}

std::string meRobot::Init2(){
  return "(init (unum 0)(teamname " + world.getTeamname() + "))";
}

void meRobot::setSequence(Sequence newSeq){
    // next_seq = newSeq
    // newOneComeFlag = true
}
