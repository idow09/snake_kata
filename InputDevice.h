#ifndef IDOSNAKE_INPUTDEVICE_H
#define IDOSNAKE_INPUTDEVICE_H


#include "Snake.h"

class InputDevice {
public:
    virtual Input TakeInput() = 0;

    virtual bool HasInput() = 0;
};


#endif //IDOSNAKE_INPUTDEVICE_H
