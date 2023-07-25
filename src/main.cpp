#include <Arduino.h>
#include <EasyButton.h>

// Pin Definitions
#define BUTTON_PIN_1 20
#define BUTTON_PIN_2 21
#define BUTTON_PIN_3 22
#define BUTTON_PIN_4 23
#define POT_PIN_1 26
#define POT_PIN_2 27

// Put global variables here
int potVal1 = 0;
int potVal2 = 0;

// Put function declarations here:
int myFunction(int, int);
EasyButton button1(BUTTON_PIN_1);
EasyButton button2(BUTTON_PIN_2);
EasyButton button3(BUTTON_PIN_3);
EasyButton button4(BUTTON_PIN_4);


void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

  button1.begin();
  button2.begin();
  button3.begin();
  button4.begin();

  button1.onPressed(onPressed1);
  button2.onPressed(onPressed2);
  button3.onPressed(onPressed3);
  button4.onPressed(onPressed4);

  pinMode(POT_PIN_1, INPUT_ANALOG);
  pinMode(POT_PIN_2, INPUT_ANALOG);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  button1.read();
  button2.read();
  button3.read();
  button4.read();

  potVal1 = analogRead(POT_PIN_1);
  potVal2 = analogRead(POT_PIN_2);

  // Convert the analog value from a range of 0 - 4095 to a digital value in the range 0 - 1024 using the map function
  potVal1 = map(potVal1, 0, 4095, 0, 1024);   // 4095 is the max analog value for a 12 bit adc, which is the default we are assuming, 
  potVal2 = map(potVal2, 0, 4095, 0, 1024);

  potRead1(potVal1); 
  potRead2(potVal1); 
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

void onPressed1() { // define the functionality for each buttons here
    Serial.println("Button has been pressed!");
}

void onPressed2() {
    Serial.println("Button has been pressed!");
}

void onPressed3() {
    Serial.println("Button has been pressed!");
}

void onPressed4() {
    Serial.println("Button has been pressed!");
}

void potRead1(long potValue) {
  if (potValue > 512) {
    Serial.println("potValue1 is high");
    Serial.println(potValue);
  }
  else {
    Serial.println("potValue1 is high");
    Serial.println(potValue);
  }
}

void potRead2(long potValue) {
  if (potValue > 512) {
    Serial.println("potValue2 is high");
    Serial.println(potValue);
  }
  else {
    Serial.println("potValue2 is high");
    Serial.println(potValue);
  }
}