#include "../include/ScreenHandler.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

void ScreenHandler::run() {
	isRunning_ = true;
	while (isRunning_) {
		clearScreen();

		switch (currentScreen_) {
			case Screen::MainMenu: {
				showMainMenuScreen();
				break;
			}
			case Screen::Game: {
				break;
			}
			case Screen::Victory: {
				break;
			}
		}
	}
}

void ScreenHandler::clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void ScreenHandler::repairInputStreamAndClearBuffer() {
	is_.clear();
	is_.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ScreenHandler::showMainMenuScreen() {
	os_ << "Sudoku CLI Game. Main menu.\n";
	os_ << "1. Play EASY difficulty sudoku\n";
	os_ << "2. Play MEDIUM difficulty sudoku\n";
	os_ << "3. Play HARD difficulty sudoku\n";
	os_ << "4. Exit\n";
	int option = 0;
	is_ >> option;
	if (!is_ || option < 1 || option > 4) {
		os_ << "Error. You need to enter number in range 1-4. Try again.\n";
		repairInputStreamAndClearBuffer();
		return;
	}

	if (option == 1) {

	}
	if (option == 2) {

	}
	if (option == 3) {
		currentScreen_ = Screen
	}
	if (option == 4) {
		os_ << "Exit...\n";
		isRunning_ = false;
	}
}

void ScreenHandler::showGameScreen(const GameDifficulty& difficulty) {
	os_ << "Sudoku CLI Game. ";
	if (difficulty == GameDifficulty::Easy) {
		os_ << "EASY difficulty level\n";
	}
	if (difficulty == GameDifficulty::Medium) {
		os_ << "MEDIUM difficulty level\n";
	}
	if (difficulty == GameDifficulty::Hard) {
		os_ << "HARD difficulty level\n";
	}
}

void ScreenHandler::showVictoryScreen(int amountMistakes) {
	os_ << "Sudoku CLI Game. Victory!\n";
	os_ << "You have solved this sudoku!\n";
	os_ << "Amount mistakes: " << amountMistakes << "\n\n";
	os_ << "Press any key to exit\n";
}