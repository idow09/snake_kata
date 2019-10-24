#include <conio.h>
#include "ConsoleInputDevice.h"

// returns true for exit
Input ConsoleInputDevice::TakeInput() {
    switch (_getch()) {
        case 119: // w
            return INPUT_UP;
        case 115: // s
            return INPUT_DOWN;
        case 100: // d
            return INPUT_RIGHT;
        case 97: // a
            return INPUT_LEFT;
        case 113: // q
            return QUIT;
        default:
            return UNKNOWN;
    }
}

bool ConsoleInputDevice::HasInput() {
    return _kbhit();
}
