#ifndef SCREEN_HANDLER_HPP
#define SCREEN_HANDLER_HPP

#include <iosfwd>
#include "Screen.hpp"
#include "GameDifficulty.hpp"

class ScreenHandler {
public:

	ScreenHandler(std::istream& is, std::ostream& os):
		is_(is),
		os_(os),
		isRunning_(false),
		currentScreen_(Screen::MainMenu)
	{ }

	void run();

private:
	std::istream& is_;
	std::ostream& os_;
	bool isRunning_;
	Screen currentScreen_;

	void clearScreen();

	void repairInputStreamAndClearBuffer();

	void showMainMenuScreen();

	void showGameScreen(const GameDifficulty& difficulty);

	void showVictoryScreen(int amountMistakes);
};
#endif
