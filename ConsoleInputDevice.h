#ifndef IDOSNAKE_CONSOLEINPUTDEVICE_H
#define IDOSNAKE_CONSOLEINPUTDEVICE_H


#include "Snake.h"
#include "InputDevice.h"

class ConsoleInputDevice : public InputDevice {
public:
    Input TakeInput() override;

    bool HasInput() override;
};


#endif //IDOSNAKE_CONSOLEINPUTDEVICE_H
