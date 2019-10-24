#ifndef IDOSNAKE_DISPLAY_H
#define IDOSNAKE_DISPLAY_H

#include "Snake.h"

class Display {
public:
    void Draw(Snake snake, const Position &food);

    virtual void Clear() = 0;

    virtual void Draw(Symbol symbol) = 0;
};

#endif //IDOSNAKE_DISPLAY_H
