#include <iostream>
#include <list>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

static const int BOARD_SIZE = 15;
static const int REFRESH_TIME_MS = 100;
static const int INIT_SNAKE_SIZE = 3;

enum Direction {
    UP, LEFT, DOWN, RIGHT
};

enum Symbol {
    EMPTY, WALL, SNAKE_HEAD, SNAKE_BODY, FOOD, NEWLINE
};

struct Position {
    Position() {
        r = 0;
        c = 0;
    }

    Position(int r, int c) {
        this->r = r;
        this->c = c;
    }

    Position(Position const &pos) {
        this->r = pos.r;
        this->c = pos.c;
    }

    int r;
    int c;

    Position operator+(Direction dir) {
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

    friend std::ostream &operator<<(std::ostream &os, const Position &pos) {
        os << "(" << pos.r << "," << pos.c << ")";
        return os;
    }

    bool operator==(const Position &rhs) const {
        return r == rhs.r &&
               c == rhs.c;
    }

    bool operator!=(const Position &rhs) const {
        return !(rhs == *this);
    }
};

class Snake {
    Direction curDir;
    list<Position> body;
public:
    explicit Snake(Direction curDir) : curDir(curDir) {
        body = list<Position>();
        for (int i = 0; i < INIT_SNAKE_SIZE; ++i) {
            body.push_front(Position(2, 2 + i));
        }
    }

    const list<Position> &getBody() const {
        return body;
    }

    void UpdateDirection(Direction newDir) {
        switch (newDir) {
            case LEFT:
                curDir = curDir == RIGHT ? curDir : newDir;
                break;
            case RIGHT:
                curDir = curDir == LEFT ? curDir : newDir;
                break;
            case UP:
                curDir = curDir == DOWN ? curDir : newDir;
                break;
            case DOWN:
                curDir = curDir == UP ? curDir : newDir;
                break;
            default:
                break;
        }
    }

    Position NextPosition() {
        Position pos = body.front() + curDir;
        return pos;
    }

    bool In(const Position &position) {
        for (const auto &bodyPart : body) {
            if (bodyPart == position)
                return true;
        }
        return false;
    }

    void Move(bool becomeLonger = false) {
        body.push_front(NextPosition());
        if (!becomeLonger)
            body.pop_back();
    }

};

class Display {
public:
    void Draw(const Snake &snake, const Position &food) {
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
 */