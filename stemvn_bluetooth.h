#ifndef STEMVN_BLUETOOTH_H
#define STEMVN_BLUETOOTH_H

#include <Arduino.h>

class STEMVN_BLUETOOTH {
    public:
        STEMVN_BLUETOOTH();               
        void begin(long baudRate = 9600);
        String read();
        void write(const String& data);
    private:
        String _data;
        String _command;
};

#endif
