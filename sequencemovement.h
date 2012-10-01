#ifndef SEQUENCEMOVEMENT_H
#define SEQUENCEMOVEMENT_H

#include "movementbase.h"
#include "sequence.h"

class SequenceMovement : public MovementBase
{
public:
    SequenceMovement();
    ~SequenceMovement();

    std::string getNextAngle(Action& act, World& w);

    void setNewSequence(Sequence newSeq);

protected:
    Sequence seq; // if be inherited, each child class initialize "seq" in their constructer
                  // in motion editor, "seq" can be modified (by using setNewSequence())
    int timeStamp;

};

#endif // SEQUENCEMOVEMENT_H
