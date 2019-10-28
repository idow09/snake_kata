#ifndef IDOSNAKE_SNAKE_H
#define IDOSNAKE_SNAKE_H

#include <list>
#include "Position.h"

using namespace std;

class Snake {
    Direction curDir;
    Direction nextDir;
    list <Position> body;
    bool tongue;
public:
    explicit Snake(Direction curDir);

    const list <Position> &getBody();

    void UpdateDirection(Direction newDir);

    Position NextPosition();

    bool In(const Position &position);

    void Move(bool becomeLonger = false);

    void setTongue(bool val);

    void ApplyNewDirection();

    Position FutureTonguePosition();

    bool WithTongue();

    bool OppositeDirection(Direction newDir);
};


#endif //IDOSNAKE_SNAKE_H
