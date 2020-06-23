// UI.h

#ifndef _UI_h_
#define _UI_h_

#include <Arduino.h>

class UI
{

    
private:
    Stream &con;
    String commandline;
    int token_index;

    enum State
    {
        NEW,
        PROMPT,
        TYPING,
        DONE
    } state;

public:
    UI(Stream &S);

    String welcome;
    String prompt;

    byte loop();
    String token();
    void restart();


};

#endif //_UI_h_
