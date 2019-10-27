#include <iostream>
#include "ConsoleDisplay.h"

void ConsoleDisplay::Clear() {
    system("cls");
}

void ConsoleDisplay::Draw(Symbol symbol) {
    switch (symbol) {
        case EMPTY:
            cout << ' ';
            break;
        case WALL:
            cout << 'X';
            break;
        case SNAKE_HEAD:
            cout << 'O';
            break;
        case SNAKE_BODY:
            cout << 'o';
            break;
        case FOOD:
            cout << '*';
            break;
        case NEWLINE:
            cout << '\n';
            break;
        default:
            cout << "ERROR!";
            break;
    }
}
