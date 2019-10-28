#include <conio.h>
#include "ConsoleInputDevice.h"

Input ConsoleInputDevice::TakeInput() {
    switch (_getch()) {
        case 56: // 8
            return INPUT_UP;
        case 54: // 6
            return INPUT_RIGHT;
        case 53: // 5
            return INPUT_DOWN;
        case 52: // 4
            return INPUT_LEFT;
        case 32: // ' '
            return SPECIAL;
        case 113: // q
            return QUIT;
        default:
            return UNKNOWN;
    }
}

bool ConsoleInputDevice::HasInput() {
    return _kbhit();
}