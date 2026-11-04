
#define solenoidPin 13  // Solenoid Pin
#define solBut 18
#define LED 2  // Built In LED

int solButState;

void setup() {
  pinMode(solenoidPin, OUTPUT);
  pinMode(solBut, INPUT_PULLUP);
  pinMode(LED, OUTPUT);


}

void loop() {
  solButState = digitalRead(solBut);

  if(solButState == 1){
    digitalWrite(LED, solButState);
    digitalWrite(solenoidPin, HIGH);
  }

  else{
    digitalWrite(LED, solButState);
    digitalWrite(solenoidPin, LOW);
  }
}
