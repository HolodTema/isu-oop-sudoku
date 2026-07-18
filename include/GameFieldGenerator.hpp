#ifndef GAME_FIELD_GENERATOR_HPP
#define GAME_FIELD_GENERATOR_HPP

#include "GameDifficulty.hpp"
#include "GameField.hpp"

class GameFieldGenerator {
public:

	GameFieldGenerator(const GameDifficulty& difficulty):
		difficulty_(difficulty)
	{ }

	std::pair<GameField, GameField> generate() const;

private:
	GameDifficulty difficulty_;
};
#endif
