int piezoPin = 14;  
int ldrPin = 16;   
int ldrValue = 0;  
void setup() {   
  } 

void loop() {         
  ldrValue = analogRead(ldrPin); // read the value from the LDR         
  tone(piezoPin,1000); // play a 1000Hz tone from the piezo         
  delay(25);  // wait a bit         
  noTone(piezoPin);  // stop the tone         
  delay(ldrValue); // wait the amount of milliseconds in ldrValue 
}
