void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  pinMode(A8, INPUT);
  Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(A0, HIGH);
  Serial.print(analogRead(A8));
  Serial.println();
  delay(100);
}
