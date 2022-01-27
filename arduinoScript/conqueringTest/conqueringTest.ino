int chessboard[8][8];
int copyBoard[8][8] = {{1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {1,1,1,1,1,1,1,1},
                            {1,1,1,1,1,1,1,1}};


void setup() {

  Serial.begin(9600);
  for(int i = 2; i < 13; i++)
    (i <= 9) ? (pinMode(i, OUTPUT)) : (pinMode(i, INPUT));
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  int start[4];
  
}

/* void loop() {
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
    /*for(int row = 0; row < 8; row++){
    for(int col = 0; col < 8; col++){
      Serial.print(copyChessboard[row][col]);
    }
    Serial.println();
    }
    Serial.println(); 
    delay(5000);
  }


serialBoard();
} 
/*

/* User interface routines */

void loop() {
  int rowDetection[8]= {10, 11, 12, A0, A1, A2, A3, A4}; 
  bool properSetup = false; 
  int flagSetup = 0;
  int flagSetup2 = 0;
  int start[4]; 

  while ((flagSetup == 0) || (flagSetup2 == 0)){ 
      flagSetup = 1;
      for (int i = 7; i >= 0; i--){
        for(int j = 2; j < 10; j++){
          digitalWrite(j, HIGH);
          chessboard[7-i][j-2] = digitalRead(rowDetection[i]);
          //Serial.print(chessboard[7-i][j-2]);
          digitalWrite(j, LOW);
        } 
        //Serial.println();
      }
      
      //checks if this scan matches what is seen in the initial setup 
      
      for (int iRowCheck = 0; iRowCheck < 8; iRowCheck++){
        for (int jColCheck = 0; jColCheck < 8; jColCheck++){
          if(copyBoard[iRowCheck][jColCheck] == chessboard[iRowCheck][jColCheck]){
            flagSetup2 = 1;
            
          }
          if (copyBoard[iRowCheck][jColCheck] != chessboard[iRowCheck][jColCheck]){
             flagSetup = 0;
                  
          } 
          
        }
      }

      // notifies user if the board needs to be fixed based on the copy board matching with the current scan within the board 
      
      if (flagSetup == 0){
        Serial.print("Fix the board");
        Serial.println();
        delay(5000);
      }
      
      else{
        Serial.print("Good to go!");
        break;
      }
      
  }




  
  int flag1 = 0;
  int flag2 = 0;
  //bool stringComplete = false;

  while (flag1 == 0 && flag2 == 0){
    int rowDetection[8]= {10, 11, 12, A0, A1, A2, A3, A4}; 
    for (int i = 7; i >= 0; i--){
     for(int j = 2; j < 10; j++){
       digitalWrite(j, HIGH);
       chessboard[7-i][j-2] = digitalRead(rowDetection[i]);
       //Serial.print(chessboard[7-i][j-2]);
       //Serial.print(digitalRead(rowDetection[i]));
       digitalWrite(j, LOW);
     }
       // Serial.println();     
    }
    //Serial.println();
    
    
    for (int i = 0; i <8; i++){
      for (int j = 0; j < 8; j++){
        if (copyBoard[i][j] == 1 && chessboard[i][j] == 0){
         start[0] = j;
         start[1] = 7-i;  
          flag1 = 1;
        }
        if (copyBoard[i][j] == 0 && chessboard[i][j] == 1){
         start[2] = j;
         start[3] = 7-i;
         flag2 = 1;
        
        }
        if (flag1 ==1 && flag2 ==1){
          //stringComplete = true;
        }
      }
    }
    delay(2000);
  }

}
  
  

  
