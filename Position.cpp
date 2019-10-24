#include "Position.h"

Position::Position() {
    r = 0;
    c = 0;
}

Position::Position(int r, int c) {
    this->r = r;
    this->c = c;
}

Position::Position(Position const &pos) {
    this->r = pos.r;
    this->c = pos.c;
}

Position Position::operator+(Direction dir) {
    switch (dir) {
        case RIGHT:
            return Position(r, (c + 1) % BOARD_SIZE);
        case LEFT:
            return Position(r, (c - 1 + BOARD_SIZE) % BOARD_SIZE);
        case DOWN:
            return Position((r + 1) % BOARD_SIZE, c);
        case UP:
            return Position((r - 1 + BOARD_SIZE) % BOARD_SIZE, c);
        default:
            return Position(r, c);
    }
}

std::ostream &operator<<(std::ostream &os, const Position &pos) {
    os << "(" << pos.r << "," << pos.c << ")";
    return os;
}

bool Position::operator==(const Position &rhs) const {
    return r == rhs.r &&
           c == rhs.c;
}

bool Position::operator!=(const Position &rhs) const {
    return !(rhs == *this);
}