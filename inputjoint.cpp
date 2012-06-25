 #include "inputjoint.h"
//#include <QtGui>
#include <QHBoxLayout>
#include <QLabel>

InputJoint::InputJoint(QString arg_name, double min, double max, QWidget *parent) :
    QWidget(parent)
{
    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
//    spinbox = new QDoubleSpinBox();
    spinbox = new QDoubleSpinBox();

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(new QLabel(arg_name));
    hLayout->addWidget(slider);
    hLayout->addWidget(spinbox);

    this->setLayout(hLayout);

    this->setMaximum(max);
    this->setMinimum(min);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
    connect(spinbox, SIGNAL(valueChanged(double)), this, SLOT(setValue(double)));
}

void InputJoint::setMaximum(double value){
    slider->setMaximum((int)value);
    spinbox->setMaximum(value);
}

void InputJoint::setMaximum(int value){
    slider->setMaximum(value);
    spinbox->setMaximum((double)value);
}

void InputJoint::setMinimum(double value){
    slider->setMinimum((int)value);
    spinbox->setMinimum(value);
}

void InputJoint::setMinimum(int value){
    slider->setMinimum(value);
    spinbox->setMinimum((double)value);
}

void InputJoint::setValue(double value){
    if(value > spinbox->maximum() || value < spinbox->minimum()){
        return;
    }
    slider->setValue((int)value);
    if(spinbox->value() != value){
        spinbox->setValue(value);
    }
}

void InputJoint::setValue(int value){
    if(value > (int)(spinbox->maximum()) || value < (int)(spinbox->minimum())){
        return;
    }
    slider->setValue(value);
    if(spinbox->value() != (double)value){
        spinbox->setValue((double)value);
    }
}

double InputJoint::getValue(){
    return spinbox->value();
}
