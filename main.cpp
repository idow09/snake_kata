#include <windows.h>
#include <ctime>
#include "Snake.h"
#include "Position.h"
#include "Display.h"
#include "ConsoleDisplay.h"
#include "SnakeEngine.h"
#include "ConsoleInputDevice.h"
#include "InputDevice.h"

using namespace std;


int main() {
    std::srand(std::time(nullptr)); // NOLINT(cert-msc32-c,cert-msc51-cpp)

    bool quit = false;
    Input input;
    Direction dir;
    InputDevice *inputDev = new ConsoleInputDevice();
    Snake snake = Snake(RIGHT);
    Position food = Position(0.8 * BOARD_SIZE, 0.8 * BOARD_SIZE);
    Display *display = new ConsoleDisplay();
    SnakeEngine engine = SnakeEngine(&snake);
    while (!quit) {
        display->Clear();
        display->Draw(snake, food);
        if (inputDev->HasInput()) {
            input = inputDev->TakeInput();
            switch (input) {
                case QUIT:
                    quit = true;
                    break;
                case INPUT_UP:
                case INPUT_DOWN:
                case INPUT_RIGHT:
                case INPUT_LEFT:
                    dir = (Direction) input;
                    snake.UpdateDirection(dir);
                    break;
                default:
                    break;
            }
        }
        quit |= engine.Tick(food);
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