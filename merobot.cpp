#include "merobot.h"
#include <sstream>
#include "action.h"

meRobot::meRobot(std::string teamname){
  world.setTeamname(teamname);
  newOneComeFlag = false;
}

meRobot::~meRobot(){}

std::string meRobot::getNextAngle(std::string &msg){

    std::stringstream ss; // return value

    static Action action; // action type will be DUMMY. when use in game robot, please add new ActionName in util.h
    static bool actionInit = false;
    if(actionInit == false){
        action.setFinished(true);
        actionInit = true;
    }

    world.update(msg);


    if(newOneComeFlag == true && action.isFinished() == true){
//        std::cout << "do new movement" << std::endl;
        // do new movemet
        seqMove.setNewSequence(next_seq);
        action.setFinished(false); // start new action
        newOneComeFlag = false; // finished copy new one
        ss << seqMove.getNextAngle(action, world);
    }else if(newOneComeFlag == false && action.isFinished() == true){
        // don't move any joint
        ss << "(he1 0)(he2 0)(lae1 0)(rae1 0)(lae2 0)(rae2 0)(lae3 0)(rae3 0)(lae4 0)(rae4 0)(lle1 0)(rle1 0)(lle2 0)(rle2 0)(lle3 0)(rle3 0)(lle4 0)(rle4 0)(lle5 0)(rle5 0)(lle6 0)(rle6 0)";
    }else if(action.isFinished() == false){
//        std::cout << "action is not finished" << std::endl;
        // continue current movement (or stop and start new one)
        ss << seqMove.getNextAngle(action, world);
    }else{
        std::cout << "there is some bug!!" << std::endl;
    }

    return ss.str();
}

std::string meRobot::Init2(){
  return "(init (unum 0)(teamname " + world.getTeamname() + "))";
}

void meRobot::setSequence(Sequence newSeq){
    // hold new one until the robot finish current movement. that is class Robot's task.
//    std::cout << "setSequence called" << std::endl;
    next_seq = newSeq;
    newOneComeFlag = true;

}
