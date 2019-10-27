#include <conio.h>
#include "ConsoleInputDevice.h"

Input ConsoleInputDevice::TakeInput() {
    switch (_getch()) {
        case 56: // w
            return INPUT_UP;
        case 53: // s
            return INPUT_DOWN;
        case 54: // d
            return INPUT_RIGHT;
        case 52: // a
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