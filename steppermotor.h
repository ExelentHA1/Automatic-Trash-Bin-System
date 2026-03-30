#pragma once

#include <Stepper.h>

#define EMPTY_POS 0
#define HALF_POS  90
#define FULL_POS  180
class StepperM
{
public:
    StepperM();
    ~StepperM();
    Stepper init(int mPin1,int mPin2,int mPin3,int mPin4, Stepper *s);
    void checkBin(long duration);
private:
    int currentAngle = 0;
    int rev = 16;
    int speed = 10;
    Stepper *st;
    void moveTo(int target);
};