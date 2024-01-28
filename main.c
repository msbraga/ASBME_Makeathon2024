#include <Stepper.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

int Joy_xValue = analogRead(A0);
int Joy_yValue = analogRead(A1);

enum states { UP, DOWN, LEFT, RIGHT, NONEX, NONEY};
char stateX = NONEX;
char stateY = NONEY;

const int stepsPerRevolution = 360;

Stepper myStepper = Stepper(stepsPerRevolution, 10, 12, 11, 13);
// Stepper myStepper2 = Stepper(stepsPerRevolution, 6, 8, 7, 9);

void setup() {
Serial.begin(9600);
myStepper.setSpeed(10);
// myStepper2.setSpeed(10);
}

void loop() {
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
  else if (Joy_xValue <= 100){
    stateX = LEFT;
  }
  else{
    stateX = NONEX;
  }

  //JOYSTICK UP/DOWN
  if (Joy_yValue >= 857){
    stateY = UP;
  }
  else if (Joy_yValue <= 100){
    stateY = DOWN;
  }
  else{
    stateY = NONEY;
  }

  if (stateX == RIGHT){
    myStepper.step(90);
    Serial.print("RIGHT ");
    delay(20);
  }
  else if (stateX == LEFT){
    myStepper.step(-90);
    Serial.print("LEFT ");
    delay(20);
  }

  if (stateY == UP){
    // myStepper2.step(90);
    Serial.print("UP ");
    delay(20);
  }
  else if (stateY == DOWN){
    // myStepper2.step(-90);
    Serial.print("DOWN ");
    delay(20);
  }
}

/*
RIGHT => X>857
LEFT => X<30
UP => Y>1012
DOWN => Y<5
*/

