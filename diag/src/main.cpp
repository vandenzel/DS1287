#include <Arduino.h>

#include "Pin.h"
#include "Bus.h"
#include "UI.h"
#include "DS1287.h"

#define VERSION "0.2"

/*
 * 1    MOT             // I    Timing (not connected to arduino)
 * 2    n/a
 * 3    n/a 
 * 4    AD0     2       // I/O  Address/Data bus
 * 5    AD1     3       // I/O  |
 * 6    AD2     4       // I/O  |
 * 7    AD3     5       // I/O  |
 * 8    AD4     6       // I/O  |
 * 9    AD5     7       // I/O  |
 * 10   AD6     8       // I/O  |
 * 11   AD7     9       // I/O  |
 * 12   GND             // P    Ground (not connected to arduino)
 * 13   CS      10      // I    Chip Select
 * 14   AS      16      // I    Address strobe
 * 15   RW      14      // I    Read/Write
 * 16   n/a
 * 17   DS      15      // I    Data Strobe
 * 18   RESET   18      // I    Reset
 * 19   IRQ     19      // O    Interrupt Request
 * 20   n/a
 * 21   RCLR            // I    RAM Clear (not connected to arduino)
 * 22   n/a
 * 23   SQW            // O    Square Wave (not connected to arduino)
 * 24   VCC             // P    +5V 
 */

UI ui(Serial);

Bus AD((byte[]){2, 3, 4, 5, 6, 7, 8, 9}, 8, OUTPUT);
Pin CS(10, OUTPUT);
Pin AS(16, OUTPUT);
Pin RW(14, OUTPUT);
Pin DS(15, OUTPUT);
Pin RESET(18, OUTPUT);
Pin IRQ(19, INPUT);

DS1287 ds1287(DS1287::INTEL, AD, CS, AS, DS, RW, RESET, IRQ);

void printhex(byte b, char pre = ' ', byte wid = 2)
{
    if (wid > 1 && b < 0x10)
        Serial.print(pre);
    Serial.print(b, HEX);
}
void printdec(byte b, char pre = ' ', byte wid = 2)
{
    if (wid > 2 && b < 100)
        Serial.print(pre);
    if (wid > 1 && b < 10)
        Serial.print(pre);
    Serial.print(b, DEC);
}

void cls(void)
{
    Serial.println();
}

void show_time()
{
    if (ds1287.dm())
    {
        Serial.print("TIME (DEC): ");
        printdec(ds1287.hours(), '0');
        Serial.print(":");
        printdec(ds1287.minutes(), '0');
        Serial.print(":");
        printdec(ds1287.seconds(), '0');
        Serial.print(" ");
        if (!ds1287.twentyfour())
        {
            Serial.print(ds1287.ampm() ? "PM" : "AM");
        }
        else
        {
            Serial.print("--");
        }
    }
    else
    {
        Serial.print("TIME (BCD): ");
        printhex(ds1287.hours(), '0');
        Serial.print(":");
        printhex(ds1287.minutes(), '0');
        Serial.print(":");
        printhex(ds1287.seconds(), '0');
        Serial.print(" ");
        if (!ds1287.twentyfour())
        {
            Serial.print(ds1287.ampm() ? "PM" : "AM");
        }
        else
        {
            Serial.print("--");
        }
    }
    Serial.println();
}

void show_alarm()
{

    if (ds1287.dm())
    {
        Serial.print("ALARM (DEC): ");
        printdec(ds1287.hours_alarm(), '0');
        Serial.print(":");
        printdec(ds1287.minutes_alarm(), '0');
        Serial.print(":");
        printdec(ds1287.seconds_alarm(), '0');
        Serial.print(" ");
        if (!ds1287.twentyfour())
        {
            Serial.print(ds1287.ampm_alarm() ? "PM" : "AM");
        }
        else
        {
            Serial.print("--");
        }
    }
    else
    {
        Serial.print("ALARM (BCD): ");
        printhex(ds1287.hours_alarm(), '0');
        Serial.print(":");
        printhex(ds1287.minutes_alarm(), '0');
        Serial.print(":");
        printhex(ds1287.seconds_alarm(), '0');
        Serial.print(" ");
        if (!ds1287.twentyfour())
        {
            Serial.print(ds1287.ampm_alarm() ? "PM" : "AM");
        }
        else
        {
            Serial.print("--");
        }
    }
    Serial.println();
}

static const char *weekdays[] = {
    "err", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
static const char *months[] = {
    //DEC  0      1      2      3      4      5      6      7      8      9     10     11     12     13     14    15     16    17     18
    //BCD 00     01     02     03     04     05     06     07     08      09    0a     0b     0c     0d     0e    0f     10    11     12
    "err", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC", "err", "err", "err", "OCT", "NOV", "DEC"

};

void show_date()
{
    byte weekday = ds1287.weekday();
    if (weekday > 7)
        weekday = 0;
    byte month = ds1287.month();
    if (month > 18)
        month = 0;

    if (ds1287.dm())
    {
        byte century = 19;

        Serial.print("DATE (DEC): ");
        printdec(century, '0');
        printdec(ds1287.year(), '0');
        Serial.print("-");
        printdec(ds1287.month(), '0');
        Serial.print("-");
        printdec(ds1287.day(), '0');
    }
    else
    {
        byte century = 0x19;

        Serial.print("DATE (BCD): ");
        printhex(century, '0');
        printhex(ds1287.year(), '0');
        Serial.print("-");
        printhex(ds1287.month(), '0');
        Serial.print("-");
        printhex(ds1287.day(), '0');
    }
    Serial.print("    month: ");
    Serial.print(months[month]);
    Serial.print(" weekday: ");
    Serial.print(weekdays[weekday]);

    Serial.println();
}

void show_registers()
{
    // 0x0a Control A
    Serial.print("UIP   = ");
    Serial.println(ds1287.uip());
    Serial.print("DV    = ");
    Serial.println(ds1287.dv());
    Serial.print("RS    = ");
    Serial.println(ds1287.rs());

    // 0x0b Control B
    Serial.print("SET   = ");
    Serial.println(ds1287.set());
    Serial.print("PIE   = ");
    Serial.println(ds1287.pie());
    Serial.print("AIE   = ");
    Serial.println(ds1287.aie());
    Serial.print("UIE   = ");
    Serial.println(ds1287.uie());
    Serial.print("SQWE  = ");
    Serial.println(ds1287.sqwe());
    Serial.print("DM    = ");
    Serial.println(ds1287.dm());
    Serial.print("12/24 = ");
    Serial.println(ds1287.twentyfour());
    Serial.print("DSE   = ");
    Serial.println(ds1287.dse());

    // 0x0c Control C
    Serial.print("IRQF  = ");
    Serial.println(ds1287.irqf());
    Serial.print("PF    = ");
    Serial.println(ds1287.pf());
    Serial.print("AF    = ");
    Serial.println(ds1287.af());
    Serial.print("UF    = ");
    Serial.println(ds1287.uf());

    // 0x0d Control D
    Serial.print("VRT   = ");
    Serial.println(ds1287.vrt());
}

enum States : byte
{
    INITIAL = 0,
    WAITING,
    RESETTING,
    SETTIME,
    SETDATE,
    SETALARM,
    DONE
};

States state = INITIAL;

void setup()
{

    Serial.begin(115200);
    while (!Serial)
        ;

    ds1287.reset();

    ui.welcome =
        "DS1287 Series test program\n"
        "Version " VERSION "\n";
    ui.prompt = "> ";
}

void loop()
{

    if (ui.loop())
    {
        do
        {

            String command = ui.token();
            command.toUpperCase();

            if (command == "START")
            {
                ds1287.dv(0b010);
                Serial.println("Clock started.");
                break;
            }

            if (command == "STOP")
            {
                ds1287.dv(0b000);
                Serial.println("Clock stopped.");
                break;
            }

            if (command == "DATE")
            {
                String setting = ui.token();
                if (setting.length())
                {
                    byte year = setting.substring(0, 2).toInt();
                    byte month = setting.substring(2, 4).toInt();
                    byte day = setting.substring(4, 6).toInt();

                    Serial.print("Setting date...");

                    ds1287.lock();
                    ds1287.dm(1);
                    ds1287.twentyfour(1);
                    ds1287.year(year);
                    ds1287.month(month);
                    ds1287.day(day);
                    ds1287.unlock();

                    Serial.println("\b\b Done.");

                    show_date();
                }
                else
                {
                    show_date();
                }
                break;
            }

            if (command == "TIME")
            {
                String setting = ui.token();
                if (setting.length())
                {
                    byte hour = setting.substring(0, 2).toInt();
                    byte min = setting.substring(2, 4).toInt();
                    byte sec = setting.substring(4, 6).toInt();

                    Serial.print("Setting time...");

                    ds1287.lock();
                    ds1287.dm(1);
                    ds1287.twentyfour(1);
                    ds1287.hours(hour);
                    ds1287.minutes(min);
                    ds1287.seconds(sec);
                    ds1287.unlock();

                    Serial.println("\b\b Done.");

                    show_time();
                }
                else
                {
                    show_time();
                }
                break;
            }

            if (command == "ALARM")
            {
                String setting = ui.token();
                if (setting.length())
                {
                    Serial.println("SET ALARM");
                }
                else
                {
                    show_alarm();
                }
                break;
            }

            if ( command == "BLINK" ) {
                ds1287.rs( 15 );
                ds1287.sqwe( 1);
                break;
                
            }

            if ( command == "REGS" ) {
                show_registers();
                break;
            }

            if (command == "RESET")
            {
                Serial.print("Resetting...");
                ds1287.reset();
                Serial.println("\b\b Done.");
                break;
            }

            if (command == "DUMP")
            {
                Serial.println(String("Mode: ") + (ds1287.mode() == DS1287::MOTOROLA ? "Motorola" : "Intel"));
                for (byte l = 0x00; l < DS1287::NUM_REGS; l += 0x10)
                {
                    printhex(l, '0');
                    Serial.print(":  ");
                    for (byte c = 0; c < 16; c++)
                    {
                        byte r = l + c;
                        if (r < DS1287::NUM_REGS)
                        {
                            printhex(ds1287.retrieve(r), '0');
                            Serial.print(" ");
                        }
                    }
                    Serial.println();
                }
                break;
            }

        } while (false);
        ui.restart();
    }
}

// void oldloop()
// {

//     case SETTIME:
//         byte stime[6];
//         if (6 == 6)
//         {
//             ds1287.lock();
//             if (ds1287.dm())
//             {
//                 byte hour = stime[0] * 10 + stime[1];
//                 if (ds1287.twentyfour())
//                 {
//                     ds1287.hours(hour);
//                 }
//                 else
//                 {
//                     byte ampm = hour > 11;
//                     hour = hour % 12;
//                     if (hour == 0)
//                         hour = 12;
//                     ds1287.hours(hour);
//                     ds1287.ampm(ampm);
//                 }
//                 ds1287.minutes(stime[2] * 10 + stime[3]);
//                 ds1287.seconds(stime[3] * 10 + stime[4]);
//             }
//             else
//             {
//                 ds1287.hours(stime[0] * 0x10 + stime[1]);
//                 ds1287.minutes(stime[2] * 0x10 + stime[3]);
//                 ds1287.seconds(stime[3] * 0x10 + stime[4]);
//             }
//             ds1287.unlock();
//         }
//         else
//         {
//             Serial.println("(failed)");
//         }

//         state = DONE;
//         break;
//     case SETDATE:
//         state = DONE;
//         break;
//     case SETALARM:
//         state = DONE;
//         break;
//     case DONE:

//         show_date();
//         show_time();
//         show_registers();

//         for (byte l = 0x00; l < DS1287::NUM_REGS; l += 0x10)
//         {
//             printhex(l, '0');
//             Serial.print(":  ");
//             for (byte c = 0; c < 16; c++)
//             {
//                 byte r = l + c;
//                 if (r < DS1287::NUM_REGS)
//                 {
//                     printhex(ds1287.retrieve(r), '0');
//                     Serial.print(" ");
//                 }
//             }
//             Serial.println();
//         }
//         state = INITIAL;
//         break;
//     }
// }
