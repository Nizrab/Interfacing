byte LATCH = 15; //RCLK
byte CLOCK = 16;  //SRCLK
byte SER = 14; //data
volatile int i;
volatile int x;
IntervalTimer myTimer;
byte numArray[] = {
                  B10001000, //0
                  B11101011, //1
                  B01001100, //2
                  B01001001, //3
                  B00101011, //4
                  B00011001, //5
                  B00011000, //6
                  B11001011, //7
                  B00001000, //8
                  B00001001  //9
                  };
 
void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  digitalWrite (SER, LOW);
  digitalWrite (LATCH, LOW);
  digitalWrite (CLOCK, LOW);
  myTimer.begin( resetCounter, 8000000 );
  delay(300);
}

void loop() {
 for (i = 0; i <= 9; i++) {
  shiftOut(SER,CLOCK,MSBFIRST, numArray[i]);
  digitalWrite (LATCH, HIGH);
  digitalWrite (LATCH, LOW);
  delay(600);                 
  }
 }
void resetCounter(){
    x = i = 0;
}
