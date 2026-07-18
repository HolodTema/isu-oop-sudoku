#include "../include/GameField.hpp"

#include <ostream>

#include "../include/exceptions.hpp"

GameField& GameField::operator=(const GameField& other) {
	if (this != &other) {
		delete[] array_;
		array_ = new GameCell[81];
		for (int i = 0; i < 81; ++i) {
			array_[i] = other.array_[i];
		}
	}
	return *this;
}

GameField& GameField::operator=(GameField&& other) noexcept {
	if (this != &other) {
		delete[] array_;
		array_ = other.array_;
		other.array_ = nullptr;
	}
	return *this;
}

int GameField::getCellNumber(int row, int column) const {
	if (row < 0 || row > 8) {
		throw InvalidGameFieldRowException();
	}
	if (column < 0 || column > 8) {
		throw InvalidGameFieldColumnException();
	}
	return array_[row*9 + column].getValue();
}

void GameField::setCellNumber(int row, int column, int number) {
	if (row < 0 || row > 8) {
		throw InvalidGameFieldRowException();
	}
	if (column < 0 || column > 8) {
		throw InvalidGameFieldColumnException();
	}
	array_[row*9+column].setValue(number);
}

std::ostream& operator<<(std::ostream& os, const GameField& gameField) {
	std::ostream::sentry s(os);
	if (!s) {
		return os;
	}

	os << "-------------------------------------\n";
	for (int row = 0; row < 9; ++row) {
		os << "| ";
		for (int column = 0; column < 9; ++column) {
			os << gameField.array_[row*9 + column] << " | ";
		}
		os << "\n-------------------------------------\n";
	}
	return os;
}
