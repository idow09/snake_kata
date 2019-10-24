#ifndef IDOSNAKE_DISPLAY_H
#define IDOSNAKE_DISPLAY_H

#include "Snake.h"

class Display {
    virtual void Clear() = 0;

    virtual void Draw(Symbol symbol) = 0;

    void Draw(Snake *snake, const Position &food);

public:
    void ReDraw(Snake *snake, const Position &food);
};

#endif //IDOSNAKE_DISPLAY_H
