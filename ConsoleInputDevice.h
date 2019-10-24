#ifndef IDOSNAKE_CONSOLEINPUTDEVICE_H
#define IDOSNAKE_CONSOLEINPUTDEVICE_H


#include "Snake.h"

class ConsoleInputDevice {
public:
    Input TakeInput();

    bool HasInput();
};


#endif //IDOSNAKE_CONSOLEINPUTDEVICE_H
