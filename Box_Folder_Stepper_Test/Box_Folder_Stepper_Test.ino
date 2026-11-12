/* Box Folder Stepper Test Code

When limit swtich is wired int he NC position using internal pull up, not pressed state = LOW.
Clock Wise = Up
*/


#define LED 13  // Built In LED


#define cw 1   // clockwise (HIGH)
#define ccw 0  // counter clockwise (LOW)


#define step_1_DirPin 52  // stepper direction pin (LOW = CCW, HIGH = CW)
#define step_1_pullp 53   // stepper pulse pin
#define step_1_EnPin 51   // stepper enable+ pin (HIGH = release, LOW = hold)
//#define step_1_Top 34     // Top Limit Switch (for this test this will be down)

#define SPR 200     //steps per revolution
#define downBut 14  //Start button (for this test start will be up )
#define upBut 15

#define step1Delay 1000  // Pulse length

int downButState;
int upButState;


void setup() {

  pinMode(step_1_DirPin, OUTPUT);
  pinMode(step_1_EnPin, OUTPUT);
  pinMode(step_1_pullp, OUTPUT);

  pinMode(LED, OUTPUT);

  pinMode(downBut, INPUT_PULLUP);
  pinMode(upBut, INPUT_PULLUP);

  digitalWrite(step_1_EnPin, HIGH);  // Set stepper to release
}



void loop() {

  downButState = digitalRead(downBut);

  while (downButState == HIGH) {
    digitalWrite(step_1_EnPin, LOW);   // Set stepper to Hold Postion
    digitalWrite(step_1_DirPin, ccw);  // Set stepper Direction
    digitalWrite(step_1_pullp, HIGH);
    //Pulse Motor
    delayMicroseconds(step1Delay);
    digitalWrite(step_1_pullp, LOW);
    delayMicroseconds(step1Delay);

    digitalWrite(step_1_EnPin, HIGH);     //Release Hold
    downButState = digitalRead(downBut);  // Check button state again
  }

  upButState = digitalRead(upBut);
  digitalWrite(LED, upButState);

  while (upButState == HIGH) {

    digitalWrite(step_1_EnPin, LOW);  // Set stepper to Hold Postion
    digitalWrite(step_1_DirPin, cw);  //  Set Direction
    //Pulse Motor
    digitalWrite(step_1_pullp, HIGH);
    delayMicroseconds(step1Delay);
    digitalWrite(step_1_pullp, LOW);
    delayMicroseconds(step1Delay);

    digitalWrite(step_1_EnPin, HIGH);  //Release Hold
    upButState = digitalRead(upBut);   // Check button state again
  }
}
