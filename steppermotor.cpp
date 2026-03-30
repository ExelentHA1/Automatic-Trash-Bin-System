#include "steppermotor.h"
#include <Arduino.h>

StepperM::StepperM()
{
    
}

StepperM::~StepperM()
{
    delete st;
}

Stepper StepperM::init(int mPin1,int mPin2,int mPin3,int mPin4, Stepper *s)
{
    Stepper st(this->rev, mPin1, mPin2, mPin3, mPin4);
    st.setSpeed(this->speed);
    this->st = s;
    return st;
}

void StepperM::checkBin(long duration)
{
    long cm = duration / 29 / 2;

    int target;

    if (cm > 20)
        target = EMPTY_POS;
    else if (cm >= 10)
        target = HALF_POS;
    else
        target = FULL_POS;

    if (target != currentAngle)
    {
        moveTo(target);
    }
}

void StepperM::moveTo(int targetAngle)
{
    int currentStep = (currentAngle * rev) / 360;
    int targetStep  = (targetAngle * rev) / 360;

    int stepDiff = targetStep - currentStep;

    st->step(stepDiff);

    currentAngle = targetAngle;
}
