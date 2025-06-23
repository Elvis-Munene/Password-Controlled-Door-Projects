# Password Controlled Door Projects

This repository contains three ESP32-S2-based projects for creating a password-controlled door system using a keypad, servo motor, and optional OLED display. Each project demonstrates a different approach to controlling access using a password.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Prerequisites](#prerequisites)
3. [Hardware Setup](#hardware-setup)
4. [Wiring Diagrams](#wiring-diagrams)
5. [Project Instructions](#project-instructions)
    - [1. Keypad-SerialMonitor](#1-keypad-serialmonitor)
    - [2. Keypad-Servo](#2-keypad-servo)
    - [3. KeypadServoOled](#3-keypadservooled)
6. [Uploading Code](#uploading-code)
7. [Expected Results](#expected-results)
8. [Troubleshooting](#troubleshooting)
9. [License](#license)

---

## Project Overview

### 1. Keypad-SerialMonitor
- Enter a password using a keypad.
- Password entry and results are displayed on the Serial Monitor.

### 2. Keypad-Servo
- Enter a password using a keypad.
- If correct, a servo motor unlocks the door (rotates to open position).
- Status is shown via Serial Monitor.

### 3. KeypadServoOled
- Enter a password using a keypad.
- If correct, a servo motor unlocks the door.
- Status and prompts are displayed on an OLED screen.

---

## Prerequisites

### Hardware
- ESP32-S2 Dev Module (or compatible ESP32 board)
- 4x4 Matrix Keypad
- Servo Motor (e.g., SG90)
- Jumper wires
- (Optional for Project 3) 0.96" I2C OLED Display (SSD1306)

### Software
- [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/)
- ESP32 board support installed in Arduino IDE ([instructions here](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html))
- Required Arduino libraries:
    - `Keypad` library
    - `Servo` library
    - (For Project 3) `Adafruit SSD1306` and `Adafruit GFX` libraries

---

## Hardware Setup

### Keypad
- Connect the 8 pins of the 4x4 keypad to 8 available GPIO pins on the ESP32-S2 Dev Module (e.g., GPIO1-GPI34).

### Servo
- Connect the servo's signal wire to a PWM-capable GPIO pin (e.g., GPIO20).
- Connect power (VCC) to 5V and ground (GND) to GND on the ESP32-S2 Dev Module.

### OLED Display (Project 3 only)
- Connect VCC to 3.3V or 5V (depending on your OLED module), GND to GND.
- Connect SDA to a suitable pin, SCL to another. Adjust in code as needed.

---

## Wiring Diagrams

### 1. Keypad-SerialMonitor
```
Keypad Pin 1 -> ESP32-S2 GPIO1
Keypad Pin 2 -> ESP32-S2 GPIO10
Keypad Pin 3 -> ESP32-S2 GPIO19
Keypad Pin 4 -> ESP32-S2 GPIO11
Keypad Pin 5 -> ESP32-S2 GPIO12
Keypad Pin 6 -> ESP32-S2 GPIO14
Keypad Pin 7 -> ESP32-S2 GPIO21
Keypad Pin 8 -> ESP32-S2 GPIO34
```

### 2. Keypad-Servo
```
Keypad wiring: (same as above)
Servo Signal -> ESP32-S2 GPIO20
Servo VCC -> 5V
Servo GND -> GND
```

### 3. KeypadServoOled
```
Keypad wiring: (same as above)
Servo wiring: (same as above)
OLED VCC -> 3.3V or 5V (check your module)
OLED GND -> GND
OLED SDA -> ESP32-S2 SDA
OLED SCL -> ESP32-S2 SCL
```

---

## Project Instructions

### 1. Keypad-SerialMonitor
1. Connect the keypad directly to the ESP32-S2 Dev Module as shown in the wiring diagram.
2. Open `Keypad-SerialMonitor/Keypad-SerialMonitor.ino` in Arduino IDE.
3. Install the `Keypad` library via Library Manager if not already installed.
4. Upload the code to your ESP32-S2 Dev Module.
5. Open the Serial Monitor (set baud rate as specified in the code, usually 9600 or 115200).
6. Enter the password using the keypad. The Serial Monitor will display access status.

### 2. Keypad-Servo
1. Connect the keypad and servo directly to the ESP32-S2 Dev Module as shown in the wiring diagram.
2. Open `Keypad-Servo/Keypad-Servo.ino` in Arduino IDE.
3. Install the `Keypad` and `Servo` libraries via Library Manager.
4. Upload the code to your ESP32-S2 Dev Module.
5. Open the Serial Monitor.
6. Enter the password using the keypad. If correct, the servo will rotate to unlock.

### 3. KeypadServoOled
1. Connect the keypad, servo, and OLED directly to the ESP32-S2 Dev Module as shown in the wiring diagram.
2. Open `KeypadServoOled/KeypadServoOled.ino` in Arduino IDE.
3. Install the `Keypad`, `Servo`, `Adafruit SSD1306`, and `Adafruit GFX` libraries via Library Manager.
4. Upload the code to your ESP32-S2 Dev Module.
5. The OLED will display prompts and status. Enter the password using the keypad. If correct, the servo will unlock.

---

## Uploading Code

1. Open the Arduino IDE.
2. Go to `File > Open` and select the `.ino` file for the project you want to upload.
3. Connect your ESP32-S2 Dev Module via USB.
4. Select the correct board (ESP32-S2 Dev Module) and port under `Tools`.
5. Click the Upload button (right arrow).

---

## Expected Results

- **Keypad-SerialMonitor:** Enter the password on the keypad. The Serial Monitor will display whether access is granted or denied.
- **Keypad-Servo:** Enter the password. If correct, the servo will rotate to unlock the door.
- **KeypadServoOled:** Enter the password. The OLED will display prompts and status, and the servo will unlock if the password is correct.

---

## Troubleshooting

- **Keypad not responding:** Check wiring and pin assignments in the code.
- **Servo not moving:** Ensure the servo is powered and connected to the correct pin.
- **OLED not displaying:** Check I2C connections and address in the code.
- **Libraries missing:** Install required libraries via Arduino IDE Library Manager.
- **Serial Monitor not showing output:** Ensure the correct baud rate is set and the right COM port is selected.

---

## License

This project is open-source and free to use for educational purposes. 
