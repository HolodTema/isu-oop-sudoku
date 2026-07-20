#include "../../include/game/GameCell.hpp"

#include <ostream>

int GameCell::getValue() const {
	return value_;
}

void GameCell::setValue(int value) {
	if (value < 1 || value > 9) {
		throw InvalidGameCellException();
	}
	if (!isEmpty()) {
		throw UnableToSetNumberToBusyGameCellException();
	}
	value_ = value;
}

bool GameCell::isEmpty() const {
	return value_ == EMPTY_VALUE;
}

std::ostream& operator<<(std::ostream& os, const GameCell& gameCell) {
	std::ostream::sentry s(os);
	if (!s) {
		return os;
	}

	if (gameCell.isEmpty()) {
		os << " ";
	}
	else {
		os << gameCell.getValue();
	}
	return os;
}
