int chessboard[8][8];


void setup() {

  Serial.begin(9600);
  for(int i = 2; i < 13; i++)
    (i <= 9) ? (pinMode(i, OUTPUT)) : (pinMode(i, INPUT));
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  
}

void loop() {
    int rowDetection[8]= {10, 11, 12, A0, A1, A2, A3, A4}; 
    for (int i = 7; i >= 0; i--){
     for(int j = 2; j < 10; j++){
       digitalWrite(j, HIGH);
       chessboard[7-i][j-2] = digitalRead(rowDetection[i]);
       Serial.print(chessboard[7-i][j-2]);
       //Serial.print(digitalRead(rowDetection[i]));
       digitalWrite(j, LOW);
     }
        Serial.println();     
    }
    Serial.println();

  delay(1000); 
  }
  
  

  
