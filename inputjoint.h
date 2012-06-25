#ifndef INPUTJOINT_H
#define INPUTJOINT_H

#include <QWidget>
#include <QString>
#include <QSlider>
#include <QDoubleSpinBox>
//#include <QSpinBox>

/*
    This class provade gui for one joint in pose editor.

    value saved in QDoubleSpinBox
 */
class InputJoint : public QWidget
{
    Q_OBJECT
public:
    explicit InputJoint(QString name = 0, double min = 20, double max = 20, QWidget *parent = 0);
    
signals:
    void valueChanged(double);

public slots:
    void setMaximum(double value);
    void setMaximum(int value);
    void setMinimum(double value);
    void setMinimum(int value);

    void setValue(double value);
    void setValue(int value);

    double getValue();

private:
    QString name;
    QSlider *slider;
    QDoubleSpinBox *spinbox;
//    QSpinBox *spinbox;
};

#endif // INPUTJOINT_H
