#include "pose.h"

Pose::Pose()
{
    for(int i=0; i<22; i++){
        target[i] = 0;
    }

    gain = 0.05;
}

Pose::Pose(double value[]){
    for(int i=0; i<22; i++){
        target[i] = value[i];
    }

    gain = 0.05;
}

double Pose::getGain(){
    return gain;
}

double* Pose::getTarget(){
    return target;
}

Pose& Pose::operator=(const Pose& obj){
    for(int i=0; i<22; i++){
        this->target[i] = obj.target[i];
    }
    this->gain = obj.gain;
    return *this;
}

