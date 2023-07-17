#include <Arduino.h>
#include <EasyButton.h>

// Pin Definitions
#define BUTTON_PIN_1 25
#define BUTTON_PIN_2 26
#define BUTTON_PIN_3 27
#define BUTTON_PIN_4 28

// Put function declarations here:
int myFunction(int, int);
EasyButton button1(BUTTON_PIN_1);
EasyButton button2(BUTTON_PIN_2);
EasyButton button3(BUTTON_PIN_3);
EasyButton button4(BUTTON_PIN_4);


void onPressed() {
    Serial.println("Button has been pressed!");
}


void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

  button1.begin();
  button2.begin();
  button3.begin();
  button4.begin();

  button1.onPressed(onPressed);
  button2.onPressed(onPressed);
  button3.onPressed(onPressed);
  button4.onPressed(onPressed);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}