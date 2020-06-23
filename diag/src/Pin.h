// Pin.h

#ifndef _Pin_h_
#define _Pin_h_

#include <Arduino.h>

class Pin
{

private:
    byte _pin;

public:
    Pin();
    Pin(byte pin, byte dir);

    void direction(byte dir);

    byte value();
    void value(byte val);

    byte read() { return value(); }
    void write(byte val) { value(val); }
    void high() { value(HIGH); }
    void low() { value(LOW); }
    void output() { direction(OUTPUT); }
    void input() { direction(INPUT); }
    void toggle() { value( ! value() ); }
};

#endif //_Pin_h_