#include "SnakeEngine.h"

Position SnakeEngine::RandomPosition() {
    return Position(std::rand() % BOARD_SIZE, std::rand() % BOARD_SIZE); // NOLINT(cert-msc30-c,cert-msc50-cpp)
}

Position SnakeEngine::RandomEmptyPosition(Snake snake) {
    Position pos;
    do {
        pos = RandomPosition();
    } while (snake.In(pos));
    return pos;
}

bool SnakeEngine::Tick(Snake &snake, Position &food) {
    Position nextPos = snake.NextPosition();
    if (snake.In(nextPos))
        return true; // Game Over
    if (nextPos == food) {
        food = RandomEmptyPosition(snake);
        snake.Move(true);
    } else {
        snake.Move();
    }
    return false;
}