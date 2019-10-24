#ifndef IDOSNAKE_SNAKEENGINE_H
#define IDOSNAKE_SNAKEENGINE_H

#include "Position.h"
#include "Snake.h"

class SnakeEngine {
    static Position RandomPosition();

    static Position RandomEmptyPosition(Snake snake);

public:
    static bool Tick(Snake &snake, Position &food);
};

#endif //IDOSNAKE_SNAKEENGINE_H
