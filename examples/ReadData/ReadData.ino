#include <stemvn_bluetooth.h>

STEMVN_BLUETOOTH STEMVN_BLE;

void setup() {
  Serial.begin(115200);
  STEMVN_BLE.begin(9600);
}

void loop() {
  String data = STEMVN_BLE.readData();
  if (data != "") {
    Serial.print("Data received: ");
    Serial.println(data);
  }
  delay(1000);
}