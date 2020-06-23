// Bus.cpp

#include <Arduino.h>

#include "Pin.h"
#include "Bus.h"

Bus::Bus(const byte *pins, byte npins, byte dir)
{
    _npins = npins;
    for (byte pin = 0; pin < _npins; pin++)
        _pins[pin] = Pin(pins[pin], dir);
}

void Bus::direction(byte dir)
{
    for (byte pin = 0; pin < _npins; pin++)
        _pins[pin].direction(dir);
}

byte Bus::value()
{
    byte val = 0;
    for (byte pin = 0; pin < _npins; pin++)
    {
        val |= (_pins[pin].value() ? 1 << pin : 0);
    }

    return val;
}

void Bus::value(byte val)
{
    for ( byte pin = 0; pin < _npins; pin++ )
    {
        _pins[pin].value( val & ( 1 << pin ) );
    }
}
