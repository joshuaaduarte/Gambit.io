


int chessboard[4][4];

void setup() {

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  
}

void loop() {

  int flag1 = 0;
  int flag2 = 0; 
  while (flag1 == 0 && flag2 == 0){
    int rowOutput[4] = {2, 3, 4, 5};
    int rowInput[4]= {A8, A9, A10, A11}; 
    for (int j = 0; j < 4;j++){
     for(int i = 2; i < 6; i++){
       digitalWrite(i, HIGH);
       chessboard[2-i][j] = analogRead(rowInput[j]);
       Serial.print(chessboard[2-i][j]);
       Serial.print(" ");
       //Serial.print(digitalRead(rowDetection[i]));
       digitalWrite(i, LOW);
     }
        Serial.println();     
    }
    Serial.println();
    
  delay(2000);
  }
  
  
}
  

  
