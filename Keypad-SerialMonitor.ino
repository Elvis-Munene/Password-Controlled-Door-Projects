#include <Keypad.h>

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

void setup() {
  Serial.begin(115200);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}

