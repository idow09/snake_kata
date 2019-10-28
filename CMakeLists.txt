cmake_minimum_required(VERSION 3.15)
project(IdoSnake)

set(CMAKE_CXX_STANDARD 14)

# Test:
#add_executable(IdoSnake Snake.cpp Snake.h Position.cpp Position.h Config.h Display.cpp Display.h ConsoleDisplay.cpp ConsoleDisplay.h SnakeEngine.cpp SnakeEngine.h InputDevice.h ConsoleInputDevice.cpp ConsoleInputDevice.h TestCases.cpp)
# Execute:
add_executable(IdoSnake main.cpp Snake.cpp Snake.h Position.cpp Position.h Config.h Display.cpp Display.h ConsoleDisplay.cpp ConsoleDisplay.h SnakeEngine.cpp SnakeEngine.h InputDevice.h ConsoleInputDevice.cpp ConsoleInputDevice.h)