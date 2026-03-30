#pragma once

class Sensor
{
public:
    Sensor();
    ~Sensor();

    void init(const int triggerPin, const int echoPin);
    long start();
private:
    void ping();
    long capPing();

    int epin = 0;
    int tpin = 0;
};