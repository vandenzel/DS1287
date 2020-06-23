# DS1287

Information and diagnostics to test the Dallas/Maxim DS1287 and related
Real-time Clock and CMOS RAM devices

## Datasheet:

* https://datasheets.maximintegrated.com/en/ds/DS12885-DS12C887A.pdf

## Code

The _diag_ folder contains an Arduino program that lets a Pro Micro device connect
to a DS1287, or compatible device. It gives access to the first 50 registers of the device (DS1287 compatible) and can be expanded to all 128 registers of a DS12887 compatible device.

### Notes on source files:

The source files are in _diag/src_ and relate to each other as follows. Only the
basename is given, if both a _.cpp_ and a _.h_ file exist, they are related.

* _main_ contains the main Arduino code
* _DS1287_ is the interface to the device, using _Pin_ and _Bus_
* _Pin_ and _Bus_ as a class-based GPIO interface, translating the 
  Arduino _pinMode_ and _digitalRead_-style of interfacing to an interface 
  with less typing.
* _UI_ is a simple command line interface on the serial port, that handles typing
  commands.




