#include "../include/ScreenHandler.hpp"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <sstream>

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
				showGameScreen();
				break;
			}
			case Screen::Victory: {
				showVictoryScreen();
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
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
		repairInputStreamAndClearBuffer();
		os_ << "Error. You need to enter number in range 1-4. Try again.\n";
		return;
	}
	repairInputStreamAndClearBuffer();

	if (option == 1) {
		gameHandler_ = new GameHandler(GameDifficulty::Easy);
		currentScreen_ = Screen::Game;
	}
	if (option == 2) {
		gameHandler_ = new GameHandler(GameDifficulty::Medium);
		currentScreen_ = Screen::Game;
	}
	if (option == 3) {
		gameHandler_ = new GameHandler(GameDifficulty::Hard);
		currentScreen_ = Screen::Game;
	}
	if (option == 4) {
		os_ << "Exit...\n";
		isRunning_ = false;
	}
}

void ScreenHandler::showGameScreen() {
	os_ << "Sudoku CLI Game. ";
	if (gameHandler_->getDifficulty() == GameDifficulty::Easy) {
		os_ << "EASY difficulty level\n";
	}
	if (gameHandler_->getDifficulty() == GameDifficulty::Medium) {
		os_ << "MEDIUM difficulty level\n";
	}
	if (gameHandler_->getDifficulty() == GameDifficulty::Hard) {
		os_ << "HARD difficulty level\n";
	}
	os_ << "Amount mistakes you made: " << gameHandler_->getAmountMistakes() << "\n";
	gameHandler_->printGameFieldPuzzle(os_);
	os_ << "Enter ROW, COLUMN and VALUE you want to set into the cell.\n";
	os_ << "Or enter 'q' to go to Main Menu.\n";

	std::string line;
	std::getline(is_, line);
	if (line == "q" || line == "Q") {
		delete gameHandler_;
		gameHandler_ = nullptr;
		currentScreen_ = Screen::MainMenu;
		return;
	}

	std::istringstream iss(line);
	int row = 0;
	int column = 0;
	int value = 0;

	iss >> row >> column >> value;
	if (!iss || row < 1 || column < 1 || value < 1 || row > 9 || column > 9 || value > 9) {
		os_ << "You need to enter three numbers, every number is in range 1-9. Try again.\n";
		return;
	}

	bool isRightTurn = false;
	try {
		isRightTurn = gameHandler_->makeTurn(row - 1, column - 1, value);
	}
	catch (const UnableToSetNumberToBusyGameCellException& e) {
		os_ << "The cell you chose to put value is already busy. It is not mistake, just choose another game cell. Try again.\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		return;
	}

	if (isRightTurn) {
		os_ << "Right!\n";
		if (gameHandler_->isVictory()) {
			currentScreen_ = Screen::Victory;
		}
	}
	else {
		os_ << "Mistake!\n";
	}
}

void ScreenHandler::showVictoryScreen() {
	os_ << "Sudoku CLI Game. Victory!\n";
	os_ << "You have solved this sudoku!\n";
	os_ << "Amount mistakes: " << gameHandler_->getAmountMistakes() << "\n\n";
	os_ << "Press 'q' to go to Main Menu\n";
	std::string line;
	std::getline(is_, line);
	if (line == "q" || line == "Q") {
		delete gameHandler_;
		gameHandler_ = nullptr;
		currentScreen_ = Screen::MainMenu;
	}
}