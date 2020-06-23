#include <Arduino.h>

#include "Pin.h"
#include "Bus.h"
#include "DS1287.h"

DS1287::DS1287(byte mode, Bus &ad, Pin &cs, Pin &as, Pin &ds, Pin &rw, Pin &reset, Pin &irq) : _mode(mode), _ad(ad), _cs(cs), _as(as), _ds(ds), _rw(rw), _reset(reset), _irq(irq)
{
    // do stuff
}

byte DS1287::read(byte address)
{
    if (_mode == MOTOROLA)
        return read_motorola(address);
    else
        return read_intel(address);
}

void DS1287::write(byte address, byte value)
{
    if (_mode == MOTOROLA)
        write_motorola(address, value);
    else
        write_intel(address, value);
}

void DS1287::write_motorola(byte address, byte value)
{
    write_motorola_address(address);
    write_motorola_value(value);
}

byte DS1287::read_motorola(byte address)
{
    write_motorola_address(address);
    return read_motorola_value();
}

void DS1287::write_motorola_address(byte address)
{
    _cs.low();
    _ds.low();
    _as.high();
    _rw.high();
    _ad.output();
    _ad.write(address);
    _as.low();
}

void DS1287::write_motorola_value(byte value)
{
    _cs.low();
    _as.low();
    _rw.low();
    _ds.high();
    _ad.output();
    _ad.write(value);
    _ds.low();
}

byte DS1287::read_motorola_value()
{
    byte value = 0;
    _cs.low();
    _ds.high();
    _as.low();
    _rw.high();
    _ds.high();
    _as.input();
    value = _ad.read();
    _ds.low();
    return value;
}

void DS1287::write_intel(byte address, byte value)
{
    write_intel_address(address);
    write_intel_value(value);
}

byte DS1287::read_intel(byte address)
{
    write_intel_address(address);
    return read_intel_value();
}

void DS1287::write_intel_address(byte address)
{
    _cs.low();
    _ds.high();
    _rw.high();
    _as.high();
    _ad.output();
    _ad.write(address);
    _as.low();
}

void DS1287::write_intel_value(byte value)
{
    _cs.low();
    _ds.high();
    _as.low();
    _rw.low();
    _ad.output();
    _ad.write(value);
    _rw.high();
}

byte DS1287::read_intel_value(void)
{
    byte value = 0;
    _cs.low();
    _as.low();
    _rw.high();
    _ds.low();
    _ad.input();
    value = _ad.read();
    _ds.high();
    return value;
}

void DS1287::reset()
{
    _reset.low();
    delay(500);
    _reset.high();
}

byte DS1287::retrieve(byte address, byte mask, byte offset)
{
    if (mask == 0xff)
    {
        return read(address);
    }

    return (read(address) >> offset) & mask;
}

void DS1287::update(byte address, byte value, byte mask, byte offset)
{
    if (mask == 0xff)
    {
        write(address, value);
        return;
    }

    byte t = read(address);
    t &= ~(mask << offset);
    t |= (value & mask) << offset;
    write(address, t);
}

void DS1287::lock()
{
    while (uip())
        ; // wait for UIP to go low;
    set(1);
}

void DS1287::unlock()
{
    set(0);
}
