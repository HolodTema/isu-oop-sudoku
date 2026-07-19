#include "../include/GameHandler.hpp"

GameDifficulty GameHandler::getDifficulty() const {
	return difficulty_;
}

int GameHandler::getAmountMistakes() const {
	return amountMistakes_;
}

bool GameHandler::makeTurn(int row, int column, int value) {
	if (gameFieldFilled_.getCellNumber(row, column) != value) {
		amountMistakes_++;
		return false;
	}
	gameFieldPuzzle_.setCellNumber(row, column, value);
	return true;
}

bool GameHandler::isVictory() const {
	return gameFieldPuzzle_.isFilled();
}

void GameHandler::printGameFieldPuzzle(std::ostream& os) const {
	os << gameFieldPuzzle_;
}
