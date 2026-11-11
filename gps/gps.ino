#include <SoftwareSerial.h>

SoftwareSerial sim(10, 11);

const char *PHONE = "+213659540003";
const char *MESSAGE = "Hello from Arduino!";

void sendCommand(const char *cmd, unsigned long wait = 1000) {
  Serial.print(">> ");
  Serial.println(cmd);
  sim.println(cmd);
  unsigned long start = millis();
  while (millis() - start < wait) {
    while (sim.available())
      Serial.write(sim.read());
  }
}

bool waitForNetwork(unsigned long timeout) {
  unsigned long start = millis();
  while (millis() - start < timeout) {
    sim.println("AT+CREG?");
    String reply = "";
    unsigned long t = millis();
    while (millis() - t < 1000) {
      while (sim.available())
        reply += (char)sim.read();
    }
    Serial.print(reply);
    if (reply.indexOf("0,1") != -1 || reply.indexOf("0,5") != -1) {
      return true;
    }
    delay(2000);
  }
  return false;
}

void sendSMS(const char *number, const char *text) {
  sendCommand("AT+CMGF=1");

  Serial.println(">> Sending SMS...");
  sim.print("AT+CMGS=\"");
  sim.print(number);
  sim.println("\"");
  delay(1000);

  sim.print(text);
  sim.write(26);

  unsigned long start = millis();
  while (millis() - start < 10000) {
    while (sim.available())
      Serial.write(sim.read());
  }
}

void setup() {
  Serial.begin(9600);
  sim.begin(9600);

  Serial.println("Starting module...");
  delay(5000);

  sendCommand("AT");
  sendCommand("ATE0");
  sendCommand("AT+CPIN?");
  sendCommand("AT+CFUN=1");
  sendCommand("AT+COPS=0");

  Serial.println("Waiting for network...");
  if (waitForNetwork(180000)) {
    Serial.println("Registered! Sending SMS.");
    sendSMS(PHONE, MESSAGE);
    Serial.println("Done.");
  } else {
    Serial.println("Network not found. Check SIM and power.");
  }
}

void loop() {}
