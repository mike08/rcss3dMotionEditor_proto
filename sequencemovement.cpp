#include "sequencemovement.h"

SequenceMovement::SequenceMovement()
{
    // Sequence is initialized in that constructor

    timeStamp = 0;
}

SequenceMovement::~SequenceMovement(){}

std::string SequenceMovement::getNextAngle(Action &act, World &w){

    std::cout << "SequenceMovement::getNextAngle" << std::endl;

    resetAngleMap();

    /*
      for(poses[0] -> poses[num]){ // actually, "for" cannot use!
        set poses[timeStamp]
        if(all set() return false(it means, any joints are moved)){
          timeStamp++;
          // set poses[new timeStamp] ?  // be careful not to access poses[more_than_10]

        }
      }

      if(timeStamp >= seq.num){
        // action finished
        act.setFinished(true);
        timeStamp = 0;
      }

      */

    if(timeStamp < seq.getNum()){
        // check seq.poses[timeStamp]
        Pose tempPose = seq.getPose(timeStamp);
        double *tempTarget = tempPose.getTarget();
        double tempGain = tempPose.getGain();
        std::cout << seq.getNum() << std::endl;
        // do that pose
        // check return value of set()
        if( // all joint return false(not need to move joint)
                !set(w, hj1, tempTarget[0], tempGain) &&
                !set(w, hj2, tempTarget[1], tempGain) &&
                !set(w, laj1, tempTarget[2], tempGain) &&
                !set(w, raj1, tempTarget[3], tempGain) &&
                !set(w, laj2, tempTarget[4], tempGain) &&
                !set(w, raj2, tempTarget[5], tempGain) &&
                !set(w, laj3, tempTarget[6], tempGain) &&
                !set(w, raj3, tempTarget[7], tempGain) &&
                !set(w, laj4, tempTarget[8], tempGain) &&
                !set(w, raj4, tempTarget[9], tempGain) &&
                !set(w, llj1, tempTarget[10], tempGain) &&
                !set(w, rlj1, tempTarget[11], tempGain) &&
                !set(w, llj2, tempTarget[12], tempGain) &&
                !set(w, rlj2, tempTarget[13], tempGain) &&
                !set(w, llj3, tempTarget[14], tempGain) &&
                !set(w, rlj3, tempTarget[15], tempGain) &&
                !set(w, llj4, tempTarget[16], tempGain) &&
                !set(w, rlj4, tempTarget[17], tempGain) &&
                !set(w, llj5, tempTarget[18], tempGain) &&
                !set(w, rlj5, tempTarget[19], tempGain) &&
                !set(w, llj6, tempTarget[20], tempGain) &&
                !set(w, rlj6, tempTarget[21], tempGain)
                ){
            timeStamp++;
        }

    }

    if(timeStamp >= seq.getNum()){ // after timeStamp (may) is added, robot want to check if action is finished in same cycle.
        // all action finished. reset
        act.setFinished(true);
        timeStamp = 0;
    }


    return angleToString();
}

void SequenceMovement::setNewSequence(Sequence newSeq){
    seq = newSeq;
}
