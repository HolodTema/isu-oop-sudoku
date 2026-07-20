cmake_minimum_required(VERSION 3.15)

project(Sudoku VERSION 0.0.1 LANGUAGES CXX)

add_executable(sudoku src/main.cpp
        src/util/LogHelper.cpp
        src/game/GameField.cpp
        src/game/GameCell.cpp
        src/game/GameFieldGenerator.cpp
        src/game/GameHandler.cpp
        src/ui/ScreenHandler.cpp
)
