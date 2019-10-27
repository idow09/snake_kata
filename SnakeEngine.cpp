#include <windows.h>
#include "SnakeEngine.h"
#include "InputDevice.h"
#include "Display.h"

SnakeEngine::SnakeEngine(Snake *snake, InputDevice *inputDev, Display *display) : snake(snake), inputDev(inputDev),
                                                                                  display(display),
                                                                                  food(0.8 * BOARD_SIZE,
                                                                                       0.8 * BOARD_SIZE),
                                                                                  gameOver(false) {}

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

void SnakeEngine::HandleInput() {
    if (inputDev->HasInput()) {
        Input input = inputDev->TakeInput();
        switch (input) {
            case QUIT:
                gameOver = true;
                return;
            case INPUT_UP:
            case INPUT_DOWN:
            case INPUT_RIGHT:
            case INPUT_LEFT:
                snake->UpdateDirection((Direction) input);
                break;
            case SPECIAL:
                snake->setTongue(true);
                break;
            default:
                break;
        }
    }
}

bool SnakeEngine::GameShouldUpdate(unsigned long time) const { return time % GAME_TIME_UNIT_MS == 0; }

void SnakeEngine::Tick() {
    snake->ApplyNewDirection();
    Position nextPos = snake->NextPosition();
    if (snake->In(nextPos)) {
        gameOver = true;
        return;
    }
    if (nextPos == food || (snake->WithTongue() && snake->FutureTonguePosition() == food)) {
        food = RandomEmptyPosition();
        snake->Move(true);
    } else {
        snake->Move();
    }
}

void SnakeEngine::StartGame() {
    unsigned long time = 0;
    while (!gameOver) {
        HandleInput();
        if (GameShouldUpdate(time)) {
            Tick();
            display->ReDraw(snake, food);
            snake->setTongue(false);
        }
        Sleep(REFRESH_TIME_MS);
        time += REFRESH_TIME_MS;
    }
}
