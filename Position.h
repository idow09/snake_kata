#ifndef IDOSNAKE_POSITION_H
#define IDOSNAKE_POSITION_H

#include <ostream>
#include "Config.h"

struct Position {
    int r;
    int c;

    Position();

    Position(int r, int c);

    Position(Position const &pos);

    Position operator+(Direction dir);

    bool operator==(const Position &rhs) const;

    bool operator!=(const Position &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Position &pos);
};

#endif //IDOSNAKE_POSITION_H
