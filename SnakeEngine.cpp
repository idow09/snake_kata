#include <windows.h>
#include "SnakeEngine.h"
#include "InputDevice.h"
#include "Display.h"

SnakeEngine::SnakeEngine(Snake *snake, InputDevice *inputDev, Display *display) : snake(snake), inputDev(inputDev),
                                                                                  display(display),
                                                                                  food(0.8 * BOARD_SIZE,
                                                                                       0.8 * BOARD_SIZE) {}

Position SnakeEngine::RandomPosition() {
    return Position(std::rand() % BOARD_SIZE, std::rand() % BOARD_SIZE); // NOLINT(cert-msc30-c,cert-msc50-cpp)
}

Position SnakeEngine::RandomEmptyPosition() {
    Position pos;
    do {
        pos = RandomPosition();
    } while (snake->In(pos));
    return pos;
}

bool SnakeEngine::HandleInput() const {
    if (inputDev->HasInput()) {
        Input input = inputDev->TakeInput();
        switch (input) {
            case QUIT:
                return true;
            case INPUT_UP:
            case INPUT_DOWN:
            case INPUT_RIGHT:
            case INPUT_LEFT:
                snake->UpdateDirection((Direction) input);
                break;
            default:
                break;
        }
    }
    return false;
}

bool SnakeEngine::Tick() {
    Position nextPos = snake->NextPosition();
    if (snake->In(nextPos))
        return true; // Game Over
    if (nextPos == food) {
        food = RandomEmptyPosition();
        snake->Move(true);
    } else {
        snake->Move();
    }
    return false;
}

void SnakeEngine::StartGame() {
    bool quit = false;
    while (!quit) {
        display->ReDraw(snake, food);

        quit = HandleInput();

        quit |= Tick();

        Sleep(REFRESH_TIME_MS);
    }

}
