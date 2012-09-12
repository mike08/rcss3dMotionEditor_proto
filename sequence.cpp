#include "sequence.h"
#include <iostream>

Sequence::Sequence()
{
    num = 0;

}

bool Sequence::addPose(Pose p){
    if(num == MAX_NUM){
        std::cout << "sequence::addPose : sequence has MAX_NUM poses. cannot add any more" << std::endl;
        return false;
    }

    poses[num] = p;
    num++;

    return true;
}

bool Sequence::setPose(int n, Pose p){
    if(n >= num){
        std::cout << "sequence::setPose : setPose cannot add new number of pose" << std::endl;
        return true;
    }

    poses[n] = p;

    return true;
}
