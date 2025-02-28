#include <STEMVN_BLE.h>

STEMVN_BLE input;

void setup() {
    input.begin();
    Serial.begin(9600);
}

void loop() {
    input.update();

    // Kiểm tra trạng thái nút
    if (input.isButtonPressed('F')) Serial.println("Forward pressed");
    if (input.isButtonPressed('X')) Serial.println("Stop pressed");
    if (input.isButtonPressed('T')) Serial.println("Speed up pressed");
    if (input.isButtonPressed('V')) Serial.println("Speed down pressed");
    if (input.isButtonPressed('G')) Serial.println("Rotate pressed");
    if (input.isButtonPressed('L')) Serial.println("Left pressed");
    if (input.isButtonPressed('R')) Serial.println("Right pressed");
    if (input.isButtonPressed('B')) Serial.println("Backward pressed");


  delay(100);
}