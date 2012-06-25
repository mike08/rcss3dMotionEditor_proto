#ifndef MESHAREDINFORMATION_H
#define MESHAREDINFORMATION_H

#include <QObject>

/*
    This class hold inputed information on gui
    main window modify this class.
    robot has pointer and check it in getNextAngle()
 */
class meSharedInformation : public QObject
{
    Q_OBJECT
public:
    explicit meSharedInformation(QObject *parent = 0);

    int getUsingEditor();
    
signals:
    
public slots:
    void setUsingEditor(int);

private:
    int usingEditor; // save tab index to ckeck which editor is used
    // pose_editor_information pei;
    // sequence_editor_information sei;
    // ...
};

#endif // MESHAREDINFORMATION_H
