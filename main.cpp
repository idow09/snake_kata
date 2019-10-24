#include <ctime>
#include "Snake.h"
#include "Position.h"
#include "Display.h"
#include "ConsoleDisplay.h"
#include "SnakeEngine.h"
#include "ConsoleInputDevice.h"
#include "InputDevice.h"

using namespace std;


int main() {
    std::srand(std::time(nullptr)); // NOLINT(cert-msc32-c,cert-msc51-cpp)

    InputDevice *inputDev = new ConsoleInputDevice();
    Snake snake = Snake(RIGHT);
    Display *display = new ConsoleDisplay();
    SnakeEngine engine = SnakeEngine(&snake, inputDev, display);
    engine.StartGame();
    return 0;
}

/*
 * TODO
 * design better! no static functions
 * score
 * menus
 * set snake speed - tick only now & then
 */