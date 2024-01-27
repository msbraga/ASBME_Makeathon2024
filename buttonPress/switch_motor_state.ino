/*
  Code modeled off of "Debounce" example on https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce, which is in the public domain.

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the motor being controlled is swapped. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin

// Variables will change:
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

int currentMotor = LOW;     // the motor currently being controlled

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // alternates the actively controlled motor if the button state is HIGH
      if (buttonState == HIGH) {
        currentMotor = !currentMotor;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
