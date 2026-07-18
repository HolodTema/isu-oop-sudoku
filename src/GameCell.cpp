#include "../include/GameCell.hpp"

int GameCell::getValue() const {
	return value_;
}

void GameCell::setValue(int value) {
	if (value < 1 || value > 9) {
		throw InvalidGameCellException();
	}
	value_ = value;
}

bool GameCell::isEmpty() const {
	return value_ == EMPTY_VALUE;
}
