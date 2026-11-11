void setup() {}
void loop() {
  if (Serial.available()) {
    char data_rcvd = Serial.read();
    Serial.println(data_rcvd);
    if (data_rcvd == '1')
      digitalWrite(8, HIGH);
    if (data_rcvd == '0')
      digitalWrite(8, LOW);
  }
}
