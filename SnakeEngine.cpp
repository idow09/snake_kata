#include "SnakeEngine.h"

SnakeEngine::SnakeEngine(Snake *snake) : snake(snake), food(0.8 * BOARD_SIZE, 0.8 * BOARD_SIZE) {}

Position SnakeEngine::RandomPosition() {
    return Position(std::rand() % BOARD_SIZE, std::rand() % BOARD_SIZE); // NOLINT(cert-msc30-c,cert-msc50-cpp)
}

Position SnakeEngine::RandomEmptyPosition() {
    Position pos;
    do {
        pos = RandomPosition();
    } while (snake->In(pos));
    return pos;
}

bool SnakeEngine::Tick() {
    Position nextPos = snake->NextPosition();
    if (snake->In(nextPos))
        return true; // Game Over
    if (nextPos == food) {
        food = RandomEmptyPosition();
        snake->Move(true);
    } else {
        snake->Move();
    }
    return false;
}

Position SnakeEngine::WhereIsFood() {
    return food;
}
