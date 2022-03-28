// Lab03 - PWM and ISRs
// Gerald.Hurdle@AlgonquinCollege.com

#define MY_DELAY 800

//These Teensy pins are PWM
int greenLED = 20;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 21;//2.3V, ~111ohm
int redLED = 23;//1.6V, ~189ohm
int coloursflag;
// Demo #3 and Demo #4
int pushButton = 10;
// Demo #3
volatile int states = LOW;
volatile bool test = false;
volatile int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(blueLED,  OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED,   OUTPUT);
  // Demo #3 and Demo #4
  pinMode(pushButton, INPUT);

  //use this open circuited pin for a seed to the random number generator
  pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
  // Demo #4
  //README: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt( pushButton, cycleRGB, FALLING );//hight to low
}
void randomLights() {
  analogWrite(redLED, random(256));
  analogWrite(greenLED, random(256));
  analogWrite(blueLED, random(256));
  delay(MY_DELAY);
}
//DEMO #4 - COLOUR CYCLING WITH AN INTERRUPT SERVICE ROUTINE (ISR)
void loop() {
  if(counter == 0){
    randomLights();
  }
} 

void cycleRGB() {
  Serial.print(counter);
  counter++;
  if(counter < 10){
    randomLights();
    }
  else{
    counter = 0;
  }
 }
