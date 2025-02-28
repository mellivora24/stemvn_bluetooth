#include "STEMVN_BLE.h"

STEMVN_BLE::STEMVN_BLE() {
  memset(_buttons, 0, sizeof(_buttons)); // Khởi tạo tất cả nút là false
  _dx = 0;
  _dy = 0;
  _side = ' ';
}

void STEMVN_BLE::begin() {
  Serial.begin(9600);
}

void STEMVN_BLE::update() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    _processCommand(cmd);
  }
}

bool STEMVN_BLE::isButtonPressed(char button) {
  switch (button) {
    case 'F': return _buttons[0];
    case 'L': return _buttons[1];
    case 'R': return _buttons[2];
    case 'B': return _buttons[3];
    case 'T': return _buttons[4];
    case 'V': return _buttons[5];
    case 'G': return _buttons[6];
    case 'X': return _buttons[7];
    default: return false;
  }
}

int STEMVN_BLE::getJoystickX() {
  return _dx;
}

int STEMVN_BLE::getJoystickY() {
  return _dy;
}

char STEMVN_BLE::getJoystickSide() {
  return _side;
}

void STEMVN_BLE::_processCommand(String cmd) {
  memset(_buttons, 0, sizeof(_buttons));

  if (cmd.length() == 1) {
    switch (cmd[0]) {
      case 'F': _buttons[0] = true; break; // Tiến
      case 'L': _buttons[1] = true; break; // Trái
      case 'R': _buttons[2] = true; break; // Phải
      case 'B': _buttons[3] = true; break; // Lùi
      case 'T': _buttons[4] = true; break; // Tăng tốc
      case 'V': _buttons[5] = true; break; // Giảm tốc
      case 'G': _buttons[6] = true; break; // Xoay
      case 'X': _buttons[7] = true; break; // Dừng
    }
  } else if (cmd[0] == 'L' || cmd[0] == 'R') {
    int colon = cmd.indexOf(':');
    if (colon != -1) {
      _side = cmd[0];
      _dx = cmd.substring(1, colon).toInt();
      _dy = cmd.substring(colon + 1).toInt();
    }
  }
}