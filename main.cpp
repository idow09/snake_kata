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

    auto *snake = new Snake(RIGHT);
    InputDevice *inputDev = new ConsoleInputDevice();
    Display *display = new ConsoleDisplay();
    SnakeEngine engine = SnakeEngine(snake, inputDev, display);
    engine.StartGame();
    return 0;
}
