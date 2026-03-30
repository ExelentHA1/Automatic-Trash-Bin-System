#pragma once

#include <Servo.h>

enum LID_STATE
{
    OPEN, CLOSE
};

class ServoM
{
public:
    ServoM();
    ~ServoM();
    void init(const int svMotorPin);
    bool detected(long duration); // detect if a person is trying to put a trash 
private:
    void rotate(int angle);
    void open(); // 180deg rotation
    void close(); // 0deg
    int state = CLOSE;
    Servo sv;
};