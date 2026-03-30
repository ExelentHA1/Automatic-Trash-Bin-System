#include "servomotor.h"

ServoM::ServoM()
{
}

ServoM::~ServoM()
{
}

void ServoM::init(const int svMotorPin)
{
    sv.attach(svMotorPin, 600, 2300);
}

bool ServoM::detected(long duration)
{
    long cm = duration / 29 / 2;

    if (cm < 50 && state != OPEN)
    {  
        this->state = OPEN;
        this->open();
    }
    else if (cm >= 50 && state != CLOSE)
    {
        state = CLOSE;
        this->close();
    }

    return (state == OPEN); // true if open
}

void ServoM::rotate(int angle)
{
    sv.write(angle);
}

void ServoM::open()
{
    sv.write(180);
}

void ServoM::close()
{
    sv.write(0);
}
