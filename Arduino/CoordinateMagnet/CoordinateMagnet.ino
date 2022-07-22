#include <AccelStepper.h>
#include <ezButton.h>


// Define pin connections
const int dirPin = 2;
const int stepPin = 3;
const int dirPin2 = 4;
const int stepPin2 = 5;
const int magnet = 11;

//define limit switches

ezButton limitswitch(7);
ezButton limitswitch2(8);


// Define two steppers and the pins they will use
AccelStepper stepper1(AccelStepper::DRIVER, stepPin, dirPin);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);


// Declare variables for coordinates
int coordinateOne;    //Declare a float variable to hold your height
int coordinateTwo;
int coordinateThree;
int coordinateFour;

// Calibration
int calibration = 1; 
 
void setup() {
  // Initialize Serial Port
  Serial.begin(9600);     

  // Stepper Motor Settings
  stepper1.setMaxSpeed(3000);
  stepper1.setAcceleration(2000);
  stepper2.setMaxSpeed(3000);
  stepper2.setAcceleration(2000);
  int pos1 = 200;
  int pos2 = 200;

  // Limit Switch Settings 
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  limitswitch.setDebounceTime(5); // set debounce time to 50 milliseconds
  limitswitch2.setDebounceTime(5);

  // Electromagnet Pin Setup 
  pinMode(magnet, OUTPUT); 
}
 
void loop() {
  //Recieve input for the coordinates
  coordinateOneInput();
  coordinateTwoInput();
  coordinateThreeInput();
  coordinateFourInput();


  
  int flag1 = 1;
  int flag2 = 1;
  int pos1 = 200;
  int pos2 = 200;
  int pos3 = 200;
  int pos4 = 200; 
  int pos5 = 200;
  int pos6 = 200; 
  int pos7 = 200;
  int pos8 = 200;  
  

   int rotationOne = coordinateOne * calibration;
   int rotationTwo = coordinateTwo * calibration;


   // Moves electromagnet to desired x coordinate
   if (coordinateOne >= 0){
    pos1 = pos1 * rotationOne;
    pos2 = -pos2 * rotationOne;    
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
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    flag1 = 1;
    flag2 = 1;
   }

  
  // Moves electromagnet to desired y coordinate
  if (coordinateTwo >= 0){
    int temp3 = pos3 * rotationTwo;
    int temp4 = pos4 * rotationTwo;
    Serial.println(temp3);
    Serial.println(temp4);
    while (flag1 == 1 && flag2 == 1){
      stepper1.moveTo(temp3);
      stepper2.moveTo(temp4);

      stepper1.run();
      stepper2.run();
      if (stepper1.distanceToGo() == 0 && stepper2.distanceToGo() == 0){
        flag1 = 0;
        flag2 = 0;
      }  
    }
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    flag1 = 1;
    flag2 = 1;
  }
  
  while (Serial.available() > 0) {
    Serial.read();
  }

  delay(5000);
  // Turns on electromagnet
  magnetOn();

  // New Coordinate Math

  int x2 = coordinateThree - coordinateOne;
  int y2 = coordinateFour - coordinateTwo; 
  int rotationThree = x2 * calibration;
  int rotationFour = y2 * calibration;

  // Moves Piece to new x-coordinate
  if (coordinateFour >= 0){
    pos1 = pos5 * rotationOne;
    pos2 = -pos6 * rotationOne;    
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
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    flag1 = 1;
    flag2 = 1;
   }

  // Moves piece to new y-coordinate
  if (coordinateFour >= 0){
    int temp3 = pos7 * rotationTwo;
    int temp4 = pos8 * rotationTwo;
    Serial.println(temp3);
    Serial.println(temp4);
    while (flag1 == 1 && flag2 == 1){
      stepper1.moveTo(temp3);
      stepper2.moveTo(temp4);

      stepper1.run();
      stepper2.run();
      if (stepper1.distanceToGo() == 0 && stepper2.distanceToGo() == 0){
        flag1 = 0;
        flag2 = 0;
      }  
    }
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    flag1 = 1;
    flag2 = 1;
  }




  // Turns off electromagnet
  magnetOff();


  // Activates motors until limit switches are touched. 
  limitSwitch();
    while (Serial.available() > 0) {
    Serial.read();
  }
  
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
}

// Recieve user input for desired coordinates

int coordinateOneInput(){
  Serial.println("Coordinate One (Units right)?");      //Prompt User for input
  while (Serial.available() ==0 );           //Wait for user input
  coordinateOne = Serial.parseInt();
  return coordinateOne;
  
}

int coordinateTwoInput(){
  Serial.println("Coordinate Two (Units up)?");      //Prompt User for input
  while (Serial.available() ==0 );           //Wait for user input
  coordinateTwo = Serial.parseInt();
  return coordinateTwo;
  
}

int coordinateThreeInput(){
  Serial.println("Coordinate Three (Units right)?");      //Prompt User for input
  while (Serial.available() ==0 );           //Wait for user input
  coordinateThree = Serial.parseInt();
  return coordinateThree;
  
}

int coordinateFourInput(){
  Serial.println("Coordinate Four (Units up)?");      //Prompt User for input
  while (Serial.available() ==0 );           //Wait for user input
  coordinateFour = Serial.parseInt();
  return coordinateFour;
  
}

// Runs motors in specific direction until both limit switches are activated
void limitSwitch(){
      int flag3 = 0;
      int flag4 = 0; 
      limitswitch.loop();
      while (digitalRead(7) == HIGH){
          stepper1.move(-200);

          stepper2.move(-200);

          stepper1.run();
          stepper2.run();
          }
      
    limitswitch2.loop();
    while (digitalRead(8) ==HIGH){
            stepper1.move(-200);

            stepper2.move(200);

            stepper1.run();
            stepper2.run();


            }

     }

// Turns on electromagnet
void magnetOn(){
  digitalWrite(magnet, HIGH); 
  }

// Turns off electromagnet
void magnetOff(){
  digitalWrite(magnet, LOW);
  }
  
    
             
