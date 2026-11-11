char mystr[10];

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.readBytes(mystr,5);
  Serial.println(mystr);
  delay(1000);
}
