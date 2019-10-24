#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Snake.h"
#include "Position.h"
#include "Display.h"
#include "ConsoleDisplay.h"

using namespace std;

class SnakeUtil {
    static Position RandomPosition() {
        return Position(std::rand() % BOARD_SIZE, std::rand() % BOARD_SIZE); // NOLINT(cert-msc30-c,cert-msc50-cpp)
    }

public:
    static Position RandomEmptyPosition(Snake snake) {
        Position pos;
        do {
            pos = RandomPosition();
        } while (snake.In(pos));
        return pos;
    }
};

class SnakeRules {

public:
    static bool Tick(Snake &snake, Position &food) {
        Position nextPos = snake.NextPosition();
        if (snake.In(nextPos))
            return true; // Game Over
        if (nextPos == food) {
            food = SnakeUtil::RandomEmptyPosition(snake);
            snake.Move(true);
        } else {
            snake.Move();
        }
        return false;
    }
};

// returns true for exit
bool HandleInput(Snake &snake) {
    if (_kbhit())
        switch (_getch()) {
            case 119: // w
                snake.UpdateDirection(UP);
                break;
            case 97: // a
                snake.UpdateDirection(LEFT);
                break;
            case 115: // s
                snake.UpdateDirection(DOWN);
                break;
            case 100: // d
                snake.UpdateDirection(RIGHT);
                break;
            case 113: // q
                return true;
            default:
                break;
        }
    return false;
}

int main() {
    std::srand(std::time(nullptr)); // NOLINT(cert-msc32-c,cert-msc51-cpp)
    bool quit = false;
    Snake snake = Snake(RIGHT);
    Position food = Position(0.8 * BOARD_SIZE, 0.8 * BOARD_SIZE);
    Display *display = new ConsoleDisplay();
    while (!quit) {
        display->Clear();
        display->Draw(snake, food);
        quit = HandleInput(snake);
        quit |= SnakeRules::Tick(snake, food);
        Sleep(REFRESH_TIME_MS);
    }
    return 0;
}


/*
 * TODO
 * design better! no static functions
 * score
 * menus
 * set snake speed - tick only now & then
 */