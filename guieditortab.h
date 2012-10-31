#ifndef GUIEDITORTAB_H
#define GUIEDITORTAB_H

#include <QTabWidget>
#include "sequence.h"
#include "poseeditor.h"
#include "sequenceeditor.h"

/*
    GuiEditorTab
    This class is gui part.
    Receive user input. Emit sequence when some inputed value changed.
    Sequence holds motion information that you want to do by robot.
    (robot for soccer game will have function to receive sequence and do that motion)
 */

class GuiEditorTab : public QTabWidget
{
    Q_OBJECT
public:
    explicit GuiEditorTab(QWidget *parent = 0);
    
signals:
    void newSequenceMade(Sequence);

public slots:
    void poseEditorReceiver(Pose p);

private:
    PoseEditor* poseEdit;
    SequenceEditor* seqEdit;
};

#endif // GUIEDITORTAB_H
