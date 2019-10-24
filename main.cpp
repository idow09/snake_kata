#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Snake.h"
#include "Position.h"

using namespace std;

class Display {
public:
    void Draw(Snake snake, const Position &food) {
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

    virtual void Clear() = 0;

    virtual void Draw(Symbol symbol) = 0;
};

class ConsoleDisplay : public Display {
public:
    void Clear() override {
        system("cls");
    }

    void Draw(Symbol symbol) override {
        switch (symbol) {
            case EMPTY:
                cout << ' ';
                break;
            case WALL:
                cout << 'X';
                break;
            case SNAKE_HEAD:
                cout << '8';
                break;
            case SNAKE_BODY:
                cout << 'O';
                break;
            case FOOD:
                cout << '*';
                break;
            case NEWLINE:
                cout << '\n';
                break;
            default:
                cout << "ERROR!";
                break;
        }
    }
};

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
 * check snake collision with itself
 * score
 * menus
 * set snake speed - tick only now & then
 * design better! no static functions
 * edge case: snake is filling the whole screen, food cannot be generated
 *
 *
 * &getBody()
 * remove redundant include statements
 * snake init in 0.2 BOARD_SIZE
 */