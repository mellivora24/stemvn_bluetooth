#include "stemvn_bluetooth.h"

STEMVN_BLUETOOTH::STEMVN_BLUETOOTH() {}

void STEMVN_BLUETOOTH::begin(long baudRate) {
    Serial.begin(baudRate);
}

String STEMVN_BLUETOOTH::read() {
    String data = "";

    if (Serial.available() > 0) {
        data = Serial.readStringUntil('\n');
    }

    return data;
}

void STEMVN_BLUETOOTH::write(const String& data) {
    Serial.println(data);
}
