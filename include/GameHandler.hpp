#ifndef GAME_HANDLER_HPP
#define GAME_HANDLER_HPP

#include <iosfwd>
#include "GameDifficulty.hpp"

class GameHandler {
public:

	GameHandler(std::istream& is, std::ostream& os):
		is_(is),
		os_(os),
		countMistakes_(0)
	{ }

	void run();

private:
	std::istream& is_;
	std::ostream& os_;
	int countMistakes_;

	void showMainMenuScreen();

	void showGameScreen(const GameDifficulty& difficulty);

	void showVictoryScreen();

};

#endif
