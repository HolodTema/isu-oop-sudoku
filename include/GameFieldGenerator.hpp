#ifndef GAME_FIELD_GENERATOR_HPP
#define GAME_FIELD_GENERATOR_HPP

#include <random>
#include <chrono>
#include "GameDifficulty.hpp"
#include "GameField.hpp"

class GameFieldGenerator {
public:

	GameFieldGenerator(const GameDifficulty& difficulty):
		difficulty_(difficulty)
	{ }

	std::pair<GameField, GameField> generate() const;

private:
	static std::mt19937 randomNumberGenerator = std::mt19937(
		std::chrono::steady_clock::now().time_since_epoch().count()
	);

	GameDifficulty difficulty_;

	bool isPossibleToSetNumberToCell(const int* board, int row, int column, int number) const;

	bool fillBoardRecursiveBacktracking(int* board);

	int countBoardSolutions(int* board);

	void removeCellsFromFilledBoard(int* board);
};
#endif
