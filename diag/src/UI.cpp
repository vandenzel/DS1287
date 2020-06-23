// UI.cpp

#include <Arduino.h>

#include "UI.h"

#define ctrl(c) ((c) - '@')

UI::UI(Stream &S) : con(S)
{
    commandline = "";
    state = NEW;
}

String UI::token()
{
    commandline.trim();

    int index = token_index;
    int space = commandline.indexOf(' ', index);

    if (space > 0)
    {
        token_index = space + 1;
        return commandline.substring(index, space);
    }
    else
    {
        token_index = commandline.length();
        return commandline.substring(index);
    }
}

void UI::restart()
{
    state = PROMPT;
    commandline = "";
    token_index = 0;
}

byte UI::loop()
{

    switch (state)
    {
    case NEW:
        con.println(welcome);
        restart();
        break;
    case PROMPT:
        con.print(prompt);
        commandline = "";
        state = TYPING;
        break;
    case TYPING:
        if (con.available())
        {
            char c = con.read();

            switch (c)
            {
            case ctrl('D'):
                state = NEW;
                con.println("^D");
                break;
            case '\r':
                state = DONE;
                con.println();
                break;
            case '\n':
                // ignore.
                break;
            case '\b':
                if (commandline.length() > 0)
                {
                    commandline.remove(commandline.length() - 1);
                    con.print("\b \b");
                }
                break;
            case ctrl('R'):
                con.println("^R");
                con.print(prompt);
                con.print(commandline);
                break;
            case ctrl('U'):
                con.println("^U");
                con.print(prompt);
                commandline = "";
                break;
            default:
                if (c >= ' ')
                {
                    commandline = commandline + c;
                    con.print(c);
                }
                break;
            }
        }
        break;
    case DONE:
        return 1;
        break;
    }

    return 0;
}
