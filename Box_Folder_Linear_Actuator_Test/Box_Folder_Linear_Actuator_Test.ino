
#define extBut 18
#define retBut 19  //Red

#define L_Pwm 21  //White
#define R_Pwm 22  //Black

#define LED 2  // Built In LED

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

  if (extButState == HIGH ) {
    digitalWrite(LED, extButState);
    analogWrite(R_Pwm, 0);
    analogWrite(L_Pwm, 250);
  } else {
    digitalWrite(LED, extButState);
        analogWrite(R_Pwm, 0);
    analogWrite(L_Pwm, 0);
  }
  retButState = digitalRead(retBut);
  if (retButState == HIGH) {
    digitalWrite(LED, retButState);
    analogWrite(R_Pwm, 255);
    analogWrite(L_Pwm, 0);
  }
  else{
        digitalWrite(LED, retButState);
    analogWrite(R_Pwm, 0);
    analogWrite(L_Pwm, 0);
  }
}
