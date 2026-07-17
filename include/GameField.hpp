#ifndef GAME_FIELD_HPP
#define GAME_FIELD_HPP

#include <iosfwd>

class GameField {
public:

	explicit GameField() {
		array_ = new int[81];
	}

	~GameField() {
		delete[] array_;
	}

	friend std::ostream& operator<<(std::ostream& os, const GameField& gameField);

private:
	int * array_;

	int getCellNumber(int row, int column) const;

	void setCellNumber(int row, int column);
};

std::ostream& operator<<(std::ostream& os, const GameField& gameField);

#endif
