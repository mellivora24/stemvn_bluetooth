#include <stemvn_bluetooth.h>

STEMVN_BLUETOOTH STEMVN_BLE;

void setup() {
    Serial.begin(115200);
    STEMVN_BLE.begin(9600);
}

void loop() {
    STEMVN_BLE.write("STEMVN");
    delay(1000);
}