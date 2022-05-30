#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;
const int stepPin = 3;
const int dirPin2 = 4;
const int stepPin2 = 5;

#include <AccelStepper.h>

// Define two steppers and the pins they will use
AccelStepper stepper1(AccelStepper::DRIVER, stepPin, dirPin);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);



int rotations;    //Declare a float variable to hold your height
String stepDirection;
 
void setup() {
  Serial.begin(9600);      // Initialize Serial Port
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(2000);
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(2000);
  int pos1 = 200;
  int pos2 = 200;
}
 
void loop() {
  directionInput();
  rotationInput();

  Serial.print("You will move " + stepDirection + " " + rotations + " rotations");
  Serial.println();
  
  int flag1 = 1;
  int flag2 = 1;
  int pos1 = 200;
  int pos2 = 200;  
  
  if (stepDirection = "left"){
    pos1 = -1 * pos1 * rotations;
    pos2 = -1 * pos2 * rotations;
    Serial.print(pos1);
    Serial.print(pos2);
    while (flag1 == 1 && flag2 == 1){   
      stepper1.moveTo(pos1);
      stepper2.moveTo(pos2);

      stepper1.run();
      stepper2.run();

      if (stepper1.distanceToGo() == 0 && stepper2.distanceToGo() == 0){
        flag1 = 0;
        flag2 = 0;
      }
    }
  }

  if (stepDirection = "right"){
    pos1 = pos1 * rotations;
    pos2 = pos2 * rotations;
    Serial.print(pos1);
    Serial.print(pos2);
    while (flag1 == 1 && flag2 == 1){
      stepper1.moveTo(pos1);
      stepper2.moveTo(pos2);

      stepper1.run();
      stepper2.run();
      
    }
  }

   if (stepDirection = "up"){
    int move1 = pos1 * -rotations;
    int move2 = pos2 * rotations;
    while (flag1 == 1 && flag2 == 1){
      stepper1.moveTo(move1);
      stepper2.moveTo(move2);

      stepper1.run();
      stepper2.run();

      if (stepper1.distanceToGo() == 0 && stepper2.distanceToGo() == 0){
        flag1 = 0;
        flag2 = 0;
      }
    }
   }

   if (stepDirection = "down"){
    pos1 = pos1 * rotations;
    pos2 = -1* pos2 * rotations;    
    while (flag1 == 1 && flag2 == 1){
      
      stepper1.moveTo(pos1);

      stepper2.moveTo(pos2);

      stepper1.run();
      stepper2.run();

      if (stepper1.distanceToGo() == 0 && stepper2.distanceToGo() == 0){
        flag1 = 0;
        flag2 = 0;
      }
    }
   }
  while (Serial.available() > 0) {
    Serial.read();
}
}

String directionInput(){
  Serial.println("What direction?");      //Prompt User for input
  while (Serial.available() ==0 );           //Wait for user input
  stepDirection = Serial.readString();
  return stepDirection;
  
}

int rotationInput(){
  Serial.println("How many rotations? ");      //Prompt User for input
  while (Serial.available() == 0);            //Wait for user input
  rotations = Serial.parseInt();              //Read user input and hold it in a variable
  return rotations;
  
}
  // Print well formatted output               
