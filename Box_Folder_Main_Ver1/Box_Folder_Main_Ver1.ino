
#define LED 13  //Built in LED
#define Start_Button 22


//Ball Screw 1 Variables
#define Ball_Screw_1_DirPin 52  // stepper direction pin (LOW = CCW, HIGH = CW)
#define Ball_Screw_1_Pulse 53   // stepper pulse pin
#define Ball_Screw_1_EnPin 51   // stepper enable+ pin (HIGH = release, LOW = hold)

#define BS1_Sen_Engage 24
#define BS1_Sen_Home 23
int BS1_Sen_Home_State;
int BS1_Sen_Engage_State = 0;



#define pulseDelay 600

#define cw 1   // clockwise (HIGH)
#define ccw 0  // counter clockwise (LOW)

int Start_Button_State = 0;



void BS1_Home() {
  BS1_Sen_Home_State = digitalRead(BS1_Sen_Home);

  while (BS1_Sen_Home_State == LOW) {
    digitalWrite(Ball_Screw_1_EnPin, LOW);  // Set stepper to Hold Postion
    digitalWrite(Ball_Screw_1_DirPin, cw);  // Set stepper Direction

    //Pulse Motor
    digitalWrite(Ball_Screw_1_Pulse, HIGH);
    delayMicroseconds(pulseDelay);
    digitalWrite(Ball_Screw_1_Pulse, LOW);
    delayMicroseconds(pulseDelay);

    //Disengage Stepper Hold
    digitalWrite(Ball_Screw_1_EnPin, HIGH);
    BS1_Sen_Home_State = digitalRead(BS1_Sen_Home);
  }
}


void setup() {

  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(Start_Button, INPUT_PULLUP);
  pinMode(BS1_Sen_Engage, INPUT);

  pinMode(Ball_Screw_1_DirPin, OUTPUT);
  pinMode(Ball_Screw_1_Pulse, OUTPUT);
  pinMode(Ball_Screw_1_EnPin, OUTPUT);

  digitalWrite(Ball_Screw_1_EnPin, HIGH);  // keep motor released until needed

 BS1_Home();

  // for(int i = 0; i < 10000; i++){

  //     digitalWrite(Ball_Screw_1_EnPin, LOW);   // Set stepper to Hold Postion
  //     digitalWrite(Ball_Screw_1_DirPin, cw);  // Set stepper Direction

  //     //Pulse Motor
  //     digitalWrite(Ball_Screw_1_Pulse, HIGH);
  //     delayMicroseconds(pulseDelay);
  //     digitalWrite(Ball_Screw_1_Pulse, LOW);
  //     delayMicroseconds(pulseDelay);

  //     //Disengage Stepper Hold
  //     digitalWrite(Ball_Screw_1_EnPin, HIGH);

  // }
}

void loop() {

  Start_Button_State = digitalRead(Start_Button);
  digitalWrite(LED, Start_Button_State); //debug

  while (Start_Button_State == LOW) {
    Serial.println("In Loop"); //debug

    BS1_Sen_Engage_State = digitalRead(BS1_Sen_Engage);
    while (BS1_Sen_Engage_State == 0) {
      digitalWrite(Ball_Screw_1_EnPin, LOW);   // Set stepper to Hold Postion
      digitalWrite(Ball_Screw_1_DirPin, ccw);  // Set stepper Direction

      //Pulse Motor
      digitalWrite(Ball_Screw_1_Pulse, HIGH);
      delayMicroseconds(pulseDelay);
      digitalWrite(Ball_Screw_1_Pulse, LOW);
      delayMicroseconds(pulseDelay);

      //Disengage Stepper Hold
      digitalWrite(Ball_Screw_1_EnPin, HIGH);

      //BS1_Sen_Engage
      BS1_Sen_Engage_State = digitalRead(BS1_Sen_Engage);
    }
  }
}
