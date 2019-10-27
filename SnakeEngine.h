#ifndef IDOSNAKE_SNAKEENGINE_H
#define IDOSNAKE_SNAKEENGINE_H

#include "Position.h"
#include "Snake.h"
#include "InputDevice.h"
#include "Display.h"

class SnakeEngine {
    Snake *snake;
    InputDevice *inputDev;
    Display *display;
    Position food;
    bool gameOver;

    Position RandomEmptyPosition();

    static Position RandomPosition();

public:
    explicit SnakeEngine(Snake *snake, InputDevice *pDevice, Display *pDisplay);

    void Tick();

    void StartGame();

    void HandleInput();

    bool GameShouldUpdate(unsigned long time) const;
};

#endif //IDOSNAKE_SNAKEENGINE_H
