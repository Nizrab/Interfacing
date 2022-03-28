byte LATCH = 15; //RCLK
byte CLOCK = 16;  //SRCLK
byte SER = 14; //data
byte var = 1;
int bitArray[] = {1, 3, 7, 15, 31, 63, 127, 255};
bool boo = true;
void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);
  delay(1000);
}
void loop() {
  //Demo1
//  //first bit: ON
//  digitalWrite(LATCH, LOW);
//  shiftOut(SER, CLOCK, MSBFIRST, var); 
//  digitalWrite(LATCH, HIGH);
//  delay(500);
//  //first bit: OFF
//  digitalWrite(LATCH, LOW);
//  shiftOut(SER, CLOCK, MSBFIRST, var);
//  digitalWrite(LATCH, HIGH);
//  delay(500);
//  if(boo){
//    var<<= 1;
//  }
//  else{
//      var>>= 1;
//  }
//  if(var == B10000000){
//    boo = false;
//  }
//  else if(var == B00000001){
//    boo = true;
//  }

//Demo2
  for(int i=0; i<8; i++){
    shiftOut(SER, CLOCK, MSBFIRST, 0); 
    shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]); 
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);
    delay(100);
   }
  for(int i=0; i<8; i++){
    shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]); 
    shiftOut(SER, CLOCK, MSBFIRST, 255); 
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);
    delay(100);
  }
  
   for(int i=7; i>=0; i--){
    shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]); 
    shiftOut(SER, CLOCK, MSBFIRST, 255); 
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);
    delay(100);
  }
   for(int i=7; i>=0; i--){
    shiftOut(SER, CLOCK, MSBFIRST, 0); 
    shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]); 
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);
    delay(100);
  }

}
