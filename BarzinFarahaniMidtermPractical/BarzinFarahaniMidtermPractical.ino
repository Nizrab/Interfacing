/*
* Name: Barzin Farahni
* Student Number: 040922695
* Prof: Gerry Hurdle
* Date: 2021/07/07
* Project: Midterm Practical
*/
//Include Statment
#include <Bounce2.h>
//Varable Declerations
byte LATCH = 15; //RCLK
byte CLOCK = 16;  //SRCLK
byte SER = 14; //data
long randNumber;
int firstInput = 1;
int pushButton = 8;
int rround = 1;
int randNumber1,randNumber2,secondInput,buttonState,randarray;
int flash = 0;
int dezz = 1;
int bruh = 1;
int s = millis();
//Creating the debounce object
Bounce debouncerMode0 = Bounce(); 
//Array with 0-9 for the 7 segment display
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
//Setup Method                  
void setup() {
  Serial.begin(38400);
  //Sets pinmodes for 7 segment display
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  //Sets a pin for random 
  pinMode(A3, INPUT);
  randomSeed (analogRead(A3));
  digitalWrite (SER, LOW);
  digitalWrite (LATCH, LOW);
  digitalWrite (CLOCK, LOW);
  //Sets the debounce for the button to PULLUP
  debouncerMode0.attach(pushButton,INPUT_PULLUP);
  delay(3000);
}
//Loop Method
void loop() {
  //if setement for checking the rounds
  if(bruh == 1){
    Serial.println("Round #"+String(rround)+"....");
    }
    bruh++;
    //Using millis with a if statment to be able to take in the button imput 
    if(millis() - s > 2000){
      randarray = random(0,10);
      //Sets the first number to the nubmer that is being displayed
      if(dezz == 1){
        randNumber1 = randarray;
        }
      //Sets the second number to the nubmer that is being displayed
      if(dezz == 2){
        randNumber2 = randarray;
        }
        //Displays the Number 
        shiftOut(SER,CLOCK,MSBFIRST, numArray[randarray]);
        digitalWrite (LATCH, HIGH);
        digitalWrite (LATCH, LOW);
        s=millis();
    }
    //Update the debonce 
    debouncerMode0.update();
    //When the button is pressed gose into this if statment
    if(debouncerMode0.fell()){
      //When the first number is pressed
      if(dezz == 1){
        //Sets number to a variable 
        firstInput = randNumber1;
        Serial.println("PBS press # 1 ==> "+String(firstInput));
        dezz++;
        }
      //When the second number is pressed
      else if(dezz == 2){
        //Sets number to a variable 
        secondInput = randNumber2;
        Serial.println("PBS press # 2 ==> "+String(secondInput));
        //Once the second number is selected gose to numcheck method
        numcheck();
       }
    }
 }
//Numcheck method used to check if the numbers match or not
void numcheck(){
  //if the first and second number matchs 
  if(firstInput == secondInput ){
    Serial.println("==> **MATCH**\n");
    rround++;
    bruh = 0;
    flash=0;
    dezz = 1;
    //Fashes the number for 2 seconds when the numbers match
    while(flash <= 5){
    //Displays Selected Number
    shiftOut(SER,CLOCK,MSBFIRST, numArray[firstInput]);
    digitalWrite (LATCH, HIGH);
    digitalWrite (LATCH, LOW);
    delay(200);
    //Displays Nothing
    shiftOut(SER,CLOCK,MSBFIRST, B11111111);
    digitalWrite (LATCH, HIGH);
    digitalWrite (LATCH, LOW);
    delay(200);
    flash++;
    }
  }
  //If not match gets sent to else statment
  else{
    Serial.println("==> NO Match… period.\n"); 
    rround++;
    dezz = 1;
    bruh = 0;
    //Displays the dot for 2 seconds 
    shiftOut(SER,CLOCK,MSBFIRST, B11110111);
    digitalWrite (LATCH, HIGH);
    delay(2000);
    digitalWrite (LATCH, LOW);
    delay(2000);
  }
}
