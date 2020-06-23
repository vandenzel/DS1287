// Bus.h

#ifndef _Bus_h_
#define _Bus_h_

#include <Arduino.h>
#include "Pin.h"

class Bus: public Pin
{

private:
    Pin _pins[8];
    byte _npins;

public:
    Bus(const byte pins[], byte npins, byte dir);

    void direction(byte dir);

    byte value();
    void value(byte val);

    byte read() { return value(); }
    void write(byte val) { value(val); }
    void output() { direction(OUTPUT); }
    void input() { direction(INPUT); }
};

#endif //_Bus_h_
