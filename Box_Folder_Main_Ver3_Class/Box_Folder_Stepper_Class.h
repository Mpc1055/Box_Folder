#ifndef BOX_FOLDER_STEPPER_CLASS_H
#define BOX_FOLDER_STEPPER_CLASS_H

#include <Arduino.h>

class BallScrew {
public:

  int Dir_Pin;     // stepper direction pin (LOW = CCW, HIGH = CW)
  int Pulse_Pin;   // stepper pulse pin
  int En_Pin;      // stepper enable+ pin (HIGH = release, LOW = hold)
  int Home_Dir;    // ball screw backward motion
  int engage_Dir;  // ball screw forward motion

  int Sen_Home;    // home sensor
  int Sen_Engage;  // engage sensor

  int Sen_Home_State;
  int Sen_Engage_State;

  int Pulse_Delay;

  /* Constructor
     dirPin         = stepper direction pin
     pulsePin       = stepper pulse pin
     enPin          = stepper enable+ pin
     Sen_Home_Pin   = home sensor pin
     Sen_Engage_Pin = engage sensor pin
     homeDir        = which direction the stepper motor needs to run to go backwards
     pdly           = pulse HIGH time and LOW time in microseconds
  */
  BallScrew(int dirPin, int pulsePin, int enPin, int Sen_Home_Pin, int Sen_Engage_Pin, int homeDir, int pdly) {
    Dir_Pin = dirPin;
    Pulse_Pin = pulsePin;
    En_Pin = enPin;

    Home_Dir = homeDir;
    engage_Dir = !homeDir;
    Sen_Home = Sen_Home_Pin;
    Sen_Engage = Sen_Engage_Pin;

    Pulse_Delay = pdly;
  }

  void begin() {
    pinMode(Dir_Pin, OUTPUT);
    pinMode(Pulse_Pin, OUTPUT);
    pinMode(En_Pin, OUTPUT);

    pinMode(Sen_Home, INPUT);
    pinMode(Sen_Engage, INPUT);

    digitalWrite(En_Pin, HIGH);  // disengage stepper
  }

  void goHome() {
    Sen_Home_State = digitalRead(Sen_Home);

    if (Sen_Home_State == LOW) {  // only power up if we need to move
      digitalWrite(En_Pin, LOW);
      digitalWrite(Dir_Pin, Home_Dir);
      delayMicroseconds(10);

      while (Sen_Home_State == LOW) {
        digitalWrite(Pulse_Pin, HIGH);
        delayMicroseconds(Pulse_Delay);
        digitalWrite(Pulse_Pin, LOW);
        delayMicroseconds(Pulse_Delay);
        Sen_Home_State = digitalRead(Sen_Home);
      }
    }

    digitalWrite(En_Pin, HIGH);  // release after homing
  }

  void Engage(int hold) {
    Sen_Engage_State = digitalRead(Sen_Engage);

    if (Sen_Engage_State == LOW) {  // only power up if we need to move
      digitalWrite(En_Pin, LOW);
      digitalWrite(Dir_Pin, engage_Dir);
      delayMicroseconds(10);

      while (Sen_Engage_State == LOW) {
        digitalWrite(Pulse_Pin, HIGH);
        delayMicroseconds(Pulse_Delay);
        digitalWrite(Pulse_Pin, LOW);
        delayMicroseconds(Pulse_Delay);
        Sen_Engage_State = digitalRead(Sen_Engage);
      }
    }

    digitalWrite(En_Pin, hold);  // LOW = hold, HIGH = release
  }

private:
};


class Actuator {
public:

  int L_Pwm;
  int R_Pwm;

  Actuator(int r_pwm, int l_pwm) {
    R_Pwm = r_pwm;
    L_Pwm = l_pwm;
  }

  void begin() {
    pinMode(R_Pwm, OUTPUT);
    pinMode(L_Pwm, OUTPUT);
    stop();
  }

  void stop() {
    analogWrite(R_Pwm, 0);
    analogWrite(L_Pwm, 0);
  }

  void retract(int speed, int dlay) {
    analogWrite(L_Pwm, 0);      // turn off the other side first
    analogWrite(R_Pwm, speed);
    delay(dlay);
    stop();
  }

  void extend(int speed, int dlay) {
    analogWrite(R_Pwm, 0);      // turn off the other side first
    analogWrite(L_Pwm, speed);
    delay(dlay);
    stop();
  }

private:
};

#endif
