#ifndef IDOSNAKE_SNAKEENGINE_H
#define IDOSNAKE_SNAKEENGINE_H

#include "Position.h"
#include "Snake.h"

class SnakeEngine {
    Snake *snake;

    Position RandomEmptyPosition();

    static Position RandomPosition();

public:
    explicit SnakeEngine(Snake *snake);

    bool Tick(Position &food);
};

#endif //IDOSNAKE_SNAKEENGINE_H
