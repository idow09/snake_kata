#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Snake.h"
#include "Position.h"
#include "Display.h"
#include "ConsoleDisplay.h"
#include "SnakeEngine.h"

using namespace std;

// returns true for exit
bool HandleInput(Snake &snake) {
    if (_kbhit())
        switch (_getch()) {
            case 119: // w
                snake.UpdateDirection(UP);
                break;
            case 97: // a
                snake.UpdateDirection(LEFT);
                break;
            case 115: // s
                snake.UpdateDirection(DOWN);
                break;
            case 100: // d
                snake.UpdateDirection(RIGHT);
                break;
            case 113: // q
                return true;
            default:
                break;
        }
    return false;
}

int main() {
    std::srand(std::time(nullptr)); // NOLINT(cert-msc32-c,cert-msc51-cpp)
    bool quit = false;
    Snake snake = Snake(RIGHT);
    Position food = Position(0.8 * BOARD_SIZE, 0.8 * BOARD_SIZE);
    Display *display = new ConsoleDisplay();
    while (!quit) {
        display->Clear();
        display->Draw(snake, food);
        quit = HandleInput(snake);
        quit |= SnakeEngine::Tick(snake, food);
        Sleep(REFRESH_TIME_MS);
    }
    return 0;
}

/*
 * TODO
 * design better! no static functions
 * score
 * menus
 * set snake speed - tick only now & then
 */