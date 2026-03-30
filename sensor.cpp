#include <Arduino.h>
#include "sensor.h"

Sensor::Sensor()
{
    
}

Sensor::~Sensor()
{
}

void Sensor::init(const int triggerPin, const int echoPin)
{
    this->epin = echoPin;
    this->tpin = triggerPin;
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}

long Sensor::start()
{
    ping();
    long duration = capPing(); 
    return duration;
}

void Sensor::ping()
{
    digitalWrite(tpin, LOW);
    delayMicroseconds(2);
    digitalWrite(tpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(tpin, LOW);
}

long Sensor::capPing()
{
    long duration = pulseIn(epin, HIGH);
    return duration;
}
