#ifndef GAME_HANDLER_HPP
#define GAME_HANDLER_HPP

#include "GameDifficulty.hpp"
#include "GameField.hpp"
#include "GameFieldGenerator.hpp"

class GameHandler {
public:

	GameHandler(const GameDifficulty& difficulty):
		difficulty_(difficulty),
		amountMistakes_(0)
	{
		GameFieldGenerator generator(difficulty);
		auto pairGameFields = generator.generate();
		gameFieldFilled_ = pairGameFields.first;
		gameFieldPuzzle_ = pairGameFields.second;
	}

	GameDifficulty getDifficulty() const;

	int getAmountMistakes() const;

	bool makeTurn(int row, int column, int value);

	bool isVictory() const;

	void printGameFieldPuzzle(std::ostream& os) const;

private:
	GameDifficulty difficulty_;
	int amountMistakes_;
	GameField gameFieldFilled_;
	GameField gameFieldPuzzle_;
};

#endif
