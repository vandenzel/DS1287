// DS1287

#ifndef _DS1287_h_
#define _DS1287_h_

#include <Arduino.h>
#include <Pin.h>
#include <Bus.h>

class DS1287
{

private:
    byte _mode;
    Bus &_ad;
    Pin &_cs;
    Pin &_as;
    Pin &_ds;
    Pin &_rw;
    Pin &_reset;
    Pin &_irq;

public:
    static const byte NUM_REGS = 0x32;

    static const byte MOTOROLA = 1;
    static const byte INTEL = 0;

    DS1287(byte mode, Bus &ad, Pin &cs, Pin &as, Pin &ds, Pin &rw, Pin &reset, Pin &irq);

    void mode(byte mode) { _mode = mode; }
    byte mode() { return _mode; }
    byte retrieve(byte address, byte mask = 0xff, byte offset = 0);
    void update(byte address, byte value, byte mask = 0xff, byte offset = 0);

    void lock();
    void unlock();

    void reset();

    byte seconds() { return retrieve(0x00); }
    void seconds(byte value) { update(0x00, value); }
    byte minutes() { return retrieve(0x02); }
    void minutes(byte value) { update(0x02, value); }
    byte hours() { return retrieve(0x04, 0x7f); }
    void hours(byte value) { update(0x04, value, 0x7f); }
    byte ampm() { return retrieve(0x04, 0x01, 7); }
    void ampm(byte value) { update(0x04, value, 0x01, 7); }

    byte seconds_alarm() { return retrieve(0x01); }
    void seconds_alarm(byte value) { update(0x01, value); }
    byte minutes_alarm() { return retrieve(0x03); }
    void minutes_alarm(byte value) { update(0x03, value); }
    byte hours_alarm() { return retrieve(0x05, 0x7f); }
    void hours_alarm(byte value) { update(0x05, value, 0x7f); }
    byte ampm_alarm() { return retrieve(0x05, 0x01, 7); }
    void ampm_alarm(byte value) { update(0x05, value, 0x01, 7); }

    byte weekday() { return retrieve(0x06); }
    void weekday(byte value) { update(0x06, value); }
    byte day() { return retrieve(0x07); }
    void day(byte value) { update(0x07, value); }
    byte month() { return retrieve(0x08); }
    void month(byte value) { update(0x08, value); }
    byte year() { return retrieve(0x09); }
    void year(byte value) { update(0x09, value % 100); }

    byte uip() { return retrieve(0x0a, 0x01, 7); }
    byte dv() { return retrieve(0x0a, 0x07, 4); }
    void dv(byte value) { update(0x0a, value, 0x07, 4); }
    byte rs() { return retrieve(0x0a, 0x0f) & 0x0f; }
    void rs(byte value) { update(0x0a, value, 0x0f, 0); }

    byte set() { return retrieve(0x0b, 0x01, 7); }
    void set(byte value) { update(0x0b, value, 0x01, 7); }
    byte pie() { return retrieve(0x0b, 0x01, 6); }
    void pie(byte value) { update(0x0b, value, 0x01, 6); }
    byte aie() { return retrieve(0x0b, 0x01, 5); }
    void aie(byte value) { update(0x0b, value, 0x01, 5); }
    byte uie() { return retrieve(0x0b, 0x01, 4); }
    void uie(byte value) { update(0x0b, value, 0x01, 4); }
    byte sqwe() { return retrieve(0x0b, 0x01, 3); }
    void sqwe(byte value) { update(0x0b, value, 0x01, 3); }
    byte dm() { return retrieve(0x0b, 0x01, 2); }
    void dm(byte value) { update(0x0b, value, 0x01, 2); }
    byte twentyfour() { return retrieve(0x0b, 0x01, 1); }
    void twentyfour(byte value) { update(0x0b, value, 0x01, 1); }
    byte dse() { return retrieve(0x0b, 0x01, 0); }
    void dse(byte value) { update(0x0b, value, 0x01, 0); }

    byte irqf() { return retrieve(0x0c, 0x01, 7); }
    byte pf() { return retrieve(0x0c, 0x01, 6); }
    byte af() { return retrieve(0x0c, 0x01, 5); }
    byte uf() { return retrieve(0x0c, 0x01, 4); }

    byte vrt() { return retrieve(0x0d, 0x01, 7); }

private:
    byte read(byte address);
    void write(byte address, byte value);

    byte read_motorola(byte address);
    void write_motorola(byte address, byte value);
    void write_motorola_address(byte address);
    void write_motorola_value(byte value);
    byte read_motorola_value();

    byte read_intel(byte address);
    void write_intel(byte address, byte value);
    void write_intel_address(byte address);
    void write_intel_value(byte value);
    byte read_intel_value();
};

#endif //_DS1287_h_