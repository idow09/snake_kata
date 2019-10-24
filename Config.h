#ifndef IDOSNAKE_CONFIG_H
#define IDOSNAKE_CONFIG_H

static const int BOARD_SIZE = 20;
static const int INIT_SNAKE_SIZE = 3;
static const int REFRESH_TIME_MS = 100;

enum Direction {
    UP = 0, LEFT, DOWN, RIGHT
};

enum Symbol {
    EMPTY = 0, WALL, SNAKE_HEAD, SNAKE_BODY, FOOD, NEWLINE
};

#endif //IDOSNAKE_CONFIG_H
