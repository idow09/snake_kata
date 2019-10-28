#include "Snake.h"

using namespace std;

Snake::Snake(Direction curDir) : curDir(curDir), tongue(false) {
    body = list<Position>();
    for (int i = 0; i < INIT_SNAKE_SIZE; ++i) {
        body.push_front(Position(0.2 * BOARD_SIZE, int(0.2 * BOARD_SIZE) + i));
    }
}

const list<Position> &Snake::getBody() {
    return body;
}

void Snake::UpdateDirection(Direction newDir) {
    curDir = newDir;
}

Position Snake::NextPosition() {
    Position pos = body.front() + curDir;
    return pos;
}

bool Snake::In(const Position &position) {
    for (const auto &bodyPart : body) {
        if (bodyPart == position)
            return true;
    }
    return false;
}

void Snake::Move(bool becomeLonger) {
    body.push_front(NextPosition());
    if (!becomeLonger)
        body.pop_back();
}

void Snake::setTongue(bool val) {
    this->tongue = val;
}

bool Snake::WithTongue() {
    return tongue;
}

Position Snake::FutureTonguePosition() {
    return NextPosition() + curDir;
}

Direction Snake::direction() {
    return curDir;
}
