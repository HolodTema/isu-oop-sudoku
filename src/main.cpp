#include <iostream>
#include "../include/GameFieldGenerator.hpp"

int main() {
    GameFieldGenerator generator(GameDifficulty::Hard);
    std::pair<GameField, GameField> pairFields = generator.generate();

    GameField gameFieldFilled = pairFields.first;
    GameField gameFieldPuzzle = pairFields.second;

    std::cout << gameFieldFilled << "\n\n";
    std::cout << gameFieldPuzzle;
    return 0;
}

