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

    Position RandomEmptyPosition();

    static Position RandomPosition();

public:
    explicit SnakeEngine(Snake *snake, InputDevice *pDevice, Display *pDisplay);

    bool Tick();

    void StartGame();

    bool HandleInput() const;
};

#endif //IDOSNAKE_SNAKEENGINE_H
