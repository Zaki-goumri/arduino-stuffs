#include <NewPing.h>

#define TRIG 9
#define ECHO 10
#define MAX_DISTANCE 400 // cm

NewPing sonar(TRIG, ECHO, MAX_DISTANCE);

void setup() { Serial.begin(9600); }

void loop() {
  unsigned int distance = sonar.ping_cm(); // 0 means out of range

  if (distance == 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(5000);
}
