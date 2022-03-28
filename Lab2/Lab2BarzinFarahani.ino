const int ledPin = 20;
const int buttpin = 8;
int buttstate = 0;  
 
void setup() {
  Serial.begin(38400);
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(buttpin, INPUT);
}


void loop() {
  buttstate = digitalRead(buttpin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttstate == LOW) {
    // turn LED on:
    Serial.print("ass");
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.print("00");
  }
}
