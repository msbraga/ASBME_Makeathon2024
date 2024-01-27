// THE JOYSTICKS

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

int Joy_xValue = analogRead(A0);
int Joy_yValue = analogRead(A1);

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

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

}