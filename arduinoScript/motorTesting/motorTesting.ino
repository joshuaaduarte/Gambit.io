
// Include the Arduino Stepper Library
#include <Stepper.h>
const int buttonPin = 2;     
int buttonState = 0;  
// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 12, 11, 10, 9);


void setup()
{
  // set the speed at 20 rpm:
  myStepper.setSpeed(150);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
 
    Serial.println("clockwise");
    myStepper.step(2*stepsPerRevolution);
    
  } else {
    // turn LED off:
    Serial.println("counterclockwise");
    myStepper.step(-2*stepsPerRevolution);
  }

  

}
