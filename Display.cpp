#include "Display.h"

void Display::Draw(Snake snake, const Position &food) {
    Symbol screen[BOARD_SIZE + 2][BOARD_SIZE + 2];

    // Put borders on screen
    for (int i = 0; i < BOARD_SIZE + 2; ++i) {
        for (int j = 0; j < BOARD_SIZE + 2; ++j) {
            if (j == 0 || i == 0 || j == BOARD_SIZE + 1 || i == BOARD_SIZE + 1)
                screen[i][j] = WALL;
            else
                screen[i][j] = EMPTY;
        }
    }

    // Put snake on screen
    std::list<Position> snakeBody = snake.getBody();
    auto it = snakeBody.begin();
    screen[it->r + 1][it->c + 1] = SNAKE_HEAD;
    it++;
    for (; it != snakeBody.end(); it++) {
        screen[it->r + 1][it->c + 1] = SNAKE_BODY;
    }

    // Put food on screen
    screen[food.r + 1][food.c + 1] = FOOD;

    // Draw
    for (auto &row : screen) {
        for (auto &cell : row) {
            Draw(cell);
        }
        Draw(NEWLINE);
    }
}