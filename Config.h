#ifndef IDOSNAKE_CONFIG_H
#define IDOSNAKE_CONFIG_H

static const int BOARD_SIZE = 20;
static const int INIT_SNAKE_SIZE = 3;
static const int REFRESH_TIME_MS = 10;
static const int GAME_TIME_UNIT_MS = 10 * REFRESH_TIME_MS;

enum Direction {
    UP = 0, DOWN = 1, RIGHT = 2, LEFT = 3
};

enum Input {
    INPUT_UP = 0, INPUT_DOWN = 1, INPUT_RIGHT = 2, INPUT_LEFT = 3, SPECIAL, QUIT, UNKNOWN
};

enum Symbol {
    EMPTY, WALL, SNAKE_HEAD, SNAKE_BODY, SNAKE_TONGUE, FOOD, NEWLINE
};

#endif //IDOSNAKE_CONFIG_H
