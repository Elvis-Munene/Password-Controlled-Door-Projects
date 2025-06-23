#include <ESP32Servo.h>
#include <Keypad.h>

const int DOOR_SERVO_PIN = 20;
Servo doorServo;

const String password = "7890";
String input_password = "";

void setup() {
  Serial.begin(115200);
  doorServo.attach(DOOR_SERVO_PIN);
  doorServo.write(0); // Door closed
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '#') {
      if (input_password == password) {
        Serial.println("Access Granted");
        doorServo.write(90);   // Open
        delay(3000);
        doorServo.write(0);    // Close
      } else {
        Serial.println("Wrong PIN");
      }
      input_password = "";
    } else if (key == '*') {
      input_password = "";
      Serial.println("Input Cleared");
    } else {
      input_password += key;
      Serial.print("Input: ");
      Serial.println(input_password);
    }
  }
}
