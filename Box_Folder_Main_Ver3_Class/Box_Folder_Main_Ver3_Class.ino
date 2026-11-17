#include "Box_Folder_Stepper_Class.h"

#define LED 13  //Built in LED
#define Start_Button 22


//Ball Screw 1 Variables
#define Ball_Screw_1_DirPin 52  // stepper direction pin (LOW = CCW, HIGH = CW)
#define Ball_Screw_1_Pulse 53   // stepper pulse pin
#define Ball_Screw_1_EnPin 51   // stepper enable+ pin (HIGH = release, LOW = hold)

#define BS1_Sen_Home 23
#define BS1_Sen_Engage 25

//Ball Screw 2 Variables
#define Ball_Screw_2_DirPin 48 // stepper direction pin (LOW = CCW, HIGH = CW)
#define Ball_Screw_2_Pulse 49   // stepper pulse pin
#define Ball_Screw_2_EnPin 47   // stepper enable+ pin (HIGH = release, LOW = hold)

#define BS2_Sen_Home 31
#define BS2_Sen_Engage 33

//Ball Screw 3 Variables
#define Ball_Screw_3_DirPin 44 // stepper direction pin (LOW = CCW, HIGH = CW)
#define Ball_Screw_3_Pulse 45   // stepper pulse pin
#define Ball_Screw_3_EnPin 43   // stepper enable+ pin (HIGH = release, LOW = hold)

#define BS3_Sen_Home 27
#define BS3_Sen_Engage 29

#define Left_L_Pwm 2
#define Left_R_Pwm 4

#define Right_L_Pwm 9  
#define Right_R_Pwm 11


#define pulseDelay 700
#define cw 1   // clockwise (HIGH)
#define ccw 0  // counter clockwise (LOW)

int Start_Button_State = 0;


BallScrew BS_1(Ball_Screw_1_DirPin, Ball_Screw_1_Pulse, Ball_Screw_1_EnPin, BS1_Sen_Home, BS1_Sen_Engage, cw ,pulseDelay);
BallScrew BS_2(Ball_Screw_2_DirPin, Ball_Screw_2_Pulse, Ball_Screw_2_EnPin, BS2_Sen_Home, BS2_Sen_Engage, ccw ,pulseDelay);
BallScrew BS_3(Ball_Screw_3_DirPin, Ball_Screw_3_Pulse, Ball_Screw_3_EnPin, BS3_Sen_Home, BS3_Sen_Engage, ccw ,pulseDelay);

Actuator Left_actuator(Left_R_Pwm,Left_L_Pwm );
Actuator Right_actuator(Right_R_Pwm,Right_L_Pwm );


void setup() {

pinMode(LED, OUTPUT);
pinMode(Start_Button, INPUT_PULLUP);

BS_1.begin();
BS_2.begin();
BS_3.begin();

// Left_actuator.begin();
// Right_actuator.begin();



BS_3.goHome();
BS_2.goHome();
BS_1.goHome();


}

void loop() {

// Left_actuator.extend(255, 7000);
// Left_actuator.retract(255, 7000)



BS_1.Engage(HIGH);
BS_3.Engage(LOW);
BS_2.Engage(HIGH);

BS_3.goHome();
// Acutators


BS_3.Engage(LOW);
BS_3.goHome();

BS_2.goHome();
BS_1.goHome();


}
