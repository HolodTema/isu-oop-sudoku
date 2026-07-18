#ifndef GAME_FIELD_HPP
#define GAME_FIELD_HPP

#include <iosfwd>
#include "../include/GameCell.hpp"

class GameField {
public:

	explicit GameField() {
		array_ = new GameCell[81];
	}

	~GameField() {
		delete[] array_;
	}

	int getCellNumber(int row, int column) const;

	void setCellNumber(int row, int column, int number);

	friend std::ostream& operator<<(std::ostream& os, const GameField& gameField);

private:
	GameCell* array_;
};

std::ostream& operator<<(std::ostream& os, const GameField& gameField);

#endif
