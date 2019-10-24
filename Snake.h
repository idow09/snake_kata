#ifndef IDOSNAKE_SNAKE_H
#define IDOSNAKE_SNAKE_H

#include <list>
#include "Position.h"

using namespace std;

class Snake {
    Direction curDir;
    list <Position> body;
public:
    explicit Snake(Direction curDir);

    const list <Position> &getBody();

    void UpdateDirection(Direction newDir);

    Position NextPosition();

    bool In(const Position &position);

    void Move(bool becomeLonger = false);

};


#endif //IDOSNAKE_SNAKE_H
