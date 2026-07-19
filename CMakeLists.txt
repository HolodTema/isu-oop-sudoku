cmake_minimum_required(VERSION 3.15)

project(Sudoku VERSION 0.0.1 LANGUAGES CXX)

add_executable(sudoku ./src/main.cpp
    ./src/LogHelper.cpp
    ./src/GameField.cpp
    ./src/GameCell.cpp
    ./src/GameFieldGenerator.cpp
    ./src/GameHandler.cpp
)
