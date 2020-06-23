// Pin.cpp

#include <Arduino.h>

#include "Pin.h"

Pin::Pin() {
    // Nothing, just placeholder
}

Pin::Pin(byte pin, byte dir) : _pin(pin)
{
    pinMode(_pin, dir);
}

void Pin::direction(byte dir)
{
    pinMode(_pin, dir);
}

byte Pin::value()
{
    return digitalRead(_pin);
}

void Pin::value(byte val)
{
    digitalWrite(_pin, val);
}
