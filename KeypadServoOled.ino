#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>
#include <Keypad.h>

// ==== OLED Setup ====
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ==== Keypad Setup ====
#define ROW_NUM     4
#define COLUMN_NUM  4
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
byte pin_rows[ROW_NUM] = {1, 10, 9, 11};
byte pin_column[COLUMN_NUM] = {12, 14, 21, 34};
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

// ==== Pins ====
const int DOOR_SERVO_PIN = 20;

// ==== Globals ====
Servo doorServo;
const String password = "7890";
String input_password = "";

// ==== Setup ====
void setup() {
  Serial.begin(115200);
  doorServo.attach(DOOR_SERVO_PIN);
  doorServo.write(0);  // Door closed

  Wire.begin(42, 2); // SDA = 42, SCL = 2
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Enter PIN:");
  display.display();
}

// ==== Loop ====
void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '#') {
      if (input_password == password) {
        grantAccess();
      } else {
        showMessage("Wrong PIN", 2);
      }
      input_password = "";
    } else if (key == '*') {
      input_password = "";
      showMessage("Cleared", 2);
    } else {
      input_password += key;
      showInput(input_password);
    }
  }
}

// ==== Functions ====
void grantAccess() {
  showMessage("Access OK", 2);
  doorServo.write(90);
  delay(3000);
  doorServo.write(0);
  showMessage("Locked", 2);
}

void showMessage(String msg, int size) {
  display.clearDisplay();
  display.setTextSize(size);
  display.setCursor(0, 20);
  display.println(msg);
  display.display();
  delay(1500);
  showInput("");
}

void showInput(String input) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("PIN: ");
  display.println(input);
  display.display();
}