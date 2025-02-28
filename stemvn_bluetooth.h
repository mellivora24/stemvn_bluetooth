#ifndef stemvn_bluetooth_h
#define stemvn_bluetooth_h

#include <Arduino.h>

class STEMVN_BLE {
public:
  STEMVN_BLE();                     // Constructor
  void begin();                   // Khởi tạo Serial
  void update();                  // Cập nhật dữ liệu từ Serial

  // Trạng thái nút (true: nhấn, false: nhả)
  bool isButtonPressed(char button); 

  // Giá trị trục từ joystick
  int getJoystickX();             // Giá trị dx (-100 đến 100)
  int getJoystickY();             // Giá trị dy (-100 đến 100)
  char getJoystickSide();         // 'L' hoặc 'R' (trái/phải)

private:
  bool _buttons[8];               // Trạng thái 8 nút: F, L, R, B, T, V, G, X
  int _dx, _dy;                  // Giá trị trục joystick
  char _side;                    // Bên joystick (L/R)
  void _processCommand(String cmd); // Xử lý lệnh từ Serial
};

#endif