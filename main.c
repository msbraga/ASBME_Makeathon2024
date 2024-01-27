#include <Stepper.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

int Joy_xValue = analogRead(A0);
int Joy_yValue = analogRead(A1);

enum states { UP, DOWN, LEFT, RIGHT, NONEX, NONEY};
char stateX = NONEX;
char stateY = NONEY;

const int stepsPerRevolution = 200;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
myStepper.setSpeed(100);

}

void loop() {
  // put your main code here, to run repeatedly:

  // read analog X and Y analog values
  Joy_xValue = analogRead(VRX_PIN);
  Joy_yValue = analogRead(VRY_PIN);

  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(Joy_xValue);
  Serial.print(", y = ");
  Serial.println(Joy_yValue);
  delay(200);

  //JOYSTICK RIGHT/LEFT
  if (Joy_xValue >= 857){
    stateX = RIGHT;
  }
  else if (Joy_xValue <= 30){
    stateX = LEFT;
  }
  else{
    stateX = NONEX;
  }

  //JOYSTICK UP/DOWN
  if (Joy_yValue >= 857){
    stateY = UP;
  }
  else if (Joy_yValue <= 30){
    stateY = DOWN;
  }
  else{
    stateY = NONEY;
  }

  if (stateX == RIGHT){
    myStepper.step(100);
    delay(100);
  }
  else if (stateX == LEFT){
    myStepper.step(-100);
    delay(100);
  }
  

}

/*
RIGHT => X>857
LEFT => X<30
UP => Y>1012
DOWN => Y<5
*/

