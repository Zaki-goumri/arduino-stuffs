void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int level = analogRead(A1);
  if (level > 150) {
    digitalWrite(3,HIGH);
  }else {
    digitalWrite(3,LOW);
  }
  Serial.print("water level");
  Serial.println(level);
  delay(300);
}
