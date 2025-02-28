#include <STEMVN_BLE.h>

STEMVN_BLE input;

void setup() {
  input.begin();
  Serial.begin(9600);
}

void loop() {
  input.update();

  // Lấy giá trị joystick
  int dx = input.getJoystickX();
  int dy = input.getJoystickY();
  char side = input.getJoystickSide();

  if (side == 'L' || side == 'R') {
    Serial.print("Joystick ");
    Serial.print(side);
    Serial.print(": dx=");
    Serial.print(dx);
    Serial.print(", dy=");
    Serial.println(dy);
  }

  delay(100);
}