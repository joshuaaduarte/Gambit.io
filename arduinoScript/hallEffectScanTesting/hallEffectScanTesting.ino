int chessboard[2][2];


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
    int rowDetection[2]= {A0,A1}; 
    for (int i = 1; i >= 0; i--){
     for(int j = 2; j < 4; j++){
       digitalWrite(j, HIGH);
       chessboard[3-i][j-2] = analogRead(rowDetection[i]);
       Serial.print(chessboard[3-i][j-2]);
       Serial.print(',');
       //Serial.print(digitalRead(rowDetection[i]));
       digitalWrite(j, LOW);
     }
        Serial.println();     
    }
    Serial.println();

  delay(1000); 
  }
  
  
