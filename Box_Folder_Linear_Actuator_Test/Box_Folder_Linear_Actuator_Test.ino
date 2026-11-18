
#define extBut 15 //Blue
#define retBut 14 //Red

#define L_Pwm 2  //White
#define R_Pwm 2  //Black

#define LED 13  // Built In LED

int extButState;
int retButState;

void setup() {
  pinMode(extBut, INPUT_PULLUP);
  pinMode(retBut, INPUT_PULLUP);

  pinMode(L_Pwm, OUTPUT);
  pinMode(R_Pwm, OUTPUT);

  pinMode(LED, OUTPUT);
}

void loop() {
  extButState = digitalRead(extBut);
  retButState = digitalRead(retBut);

  if (extButState == HIGH && retButState == LOW) {
    // Extend
    analogWrite(R_Pwm, 0);
    analogWrite(L_Pwm, 255);
    digitalWrite(LED, HIGH);
  } else if (retButState == HIGH && extButState == LOW) {
    // Retract
    analogWrite(L_Pwm, 0);
    analogWrite(R_Pwm, 255);
    digitalWrite(LED, HIGH);
  } else {
    // Neither pressed, or both pressed: stop
    analogWrite(R_Pwm, 0);
    analogWrite(L_Pwm, 0);
    digitalWrite(LED, LOW);
  }
}