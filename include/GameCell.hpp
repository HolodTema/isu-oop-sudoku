#ifndef GAME_CELL_HPP
#define GAME_CELL_HPP

#include <iosfwd>
#include "exceptions.hpp"

class GameCell {
public:
	static constexpr int EMPTY_VALUE = 0;

	GameCell():
		value_(EMPTY_VALUE)
	{ }

	GameCell(int value) {
		if (value < 1 || value > 9) {
			throw InvalidGameCellException();
		}
		value_ = value;
	}

	int getValue() const;

	void setValue(int value);

	bool isEmpty() const;

private:
	int value_;
};

std::ostream& operator<<(std::ostream& os, const GameCell& gameCell);

#endif
