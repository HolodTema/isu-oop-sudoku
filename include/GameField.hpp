#ifndef GAME_FIELD_HPP
#define GAME_FIELD_HPP

#include <iosfwd>
#include "../include/GameCell.hpp"

class GameField {
public:

	explicit GameField() {
		array_ = new GameCell[81];
	}

	GameField(const GameField& other) {
		array_ = new GameCell[81];
		for (int i = 0; i < 81; ++i) {
			array_[i] = other.array_[i];
		}
	}

	GameField(GameField&& other) noexcept {
		array_ = other.array_;
		other.array_ = nullptr;
	}

	GameField& operator=(const GameField& other);

	GameField& operator=(GameField&& other) noexcept;

	~GameField() {
		delete[] array_;
	}

	int getCellNumber(int row, int column) const;

	void setCellNumber(int row, int column, int number);

	bool isFilled() const;

	std::string toString() const;

	friend std::ostream& operator<<(std::ostream& os, const GameField& gameField);

private:
	GameCell* array_;
};

std::ostream& operator<<(std::ostream& os, const GameField& gameField);

#endif
