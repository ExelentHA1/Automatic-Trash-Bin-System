#include <Arduino.h>
#include "sensor.h"
#include "servomotor.h"
#include "steppermotor.h"

// sensors pin
const int PIN_TRIG1 = 6;
const int PIN_E1 = 7;
const int PIN_TRIG2 = 5;
const int PIN_E2 = 4;

// motors pin
const int PIN_DC = 3; // DC motor
const int PIN_SV = 9; // Servo motor

// Stepper motor
const int PIN_SM1 = 8; 
const int PIN_SM2 = 10; 
const int PIN_SM3 = 11; 
const int PIN_SM4 = 12; 

Sensor s1, s2;
ServoM sv;
StepperM st;
Stepper stpm = st.init(PIN_SM1, PIN_SM2, PIN_SM3, PIN_SM4, &stpm);
void setup() {
  sv.init(PIN_SV);
  s1.init(PIN_TRIG1, PIN_E1);
  s2.init(PIN_TRIG2, PIN_E2);
  pinMode(PIN_DC, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long dur1, dur2;
  dur2 = s2.start();
  dur1 = s1.start();
  
  st.checkBin(dur2);
  
  if(sv.detected(dur1))
  {
    int speed = 153;
    if (speed >= 0 && speed <= 255) {
      analogWrite(PIN_DC, speed);
    }
  }
  else
  {
    analogWrite(PIN_DC, LOW);
  }
  delay(100);
}