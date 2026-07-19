#include "../include/GameHandler.hpp"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include "../include/GameDifficulty.hpp"
#include "../include/GameFieldGenerator.hpp"

void GameHandler::run() {
	showMainMenuScreen();
}

void GameHandler::showMainMenuScreen() {
	while (true) {
		os_ << "Sudoku CLI Game. Main menu.\n";
		os_ << "1. Play EASY difficulty sudoku\n";
		os_ << "2. Play MEDIUM difficulty sudoku\n";
		os_ << "3. Play HARD difficulty sudoku\n";
		os_ << "4. Exit\n";
		int option = 0;
		is_ >> option;
		if (option == 1) {
			os_ << "\n\n";
			showGameScreen(GameDifficulty::Easy);
			return;
		}
		if (option == 2) {
			os_ << "\n\n";
			showGameScreen(GameDifficulty::Medium);
			return;
		}
		if (option == 3) {
			os_ << "\n\n";
			showGameScreen(GameDifficulty::Hard);
			return;
		}
		if (option == 4) {
			os_ << "\nExit...\n";
			return;
		}
		os_ << "Invalid option. You need to press keys 1-4.\n";
	}
}

void GameHandler::showGameScreen(const GameDifficulty& difficulty) {
	GameFieldGenerator generator(difficulty);
	auto pairGameFields = generator.generate();
	GameField gameFieldFilled = pairGameFields.first;
	GameField gameFieldPuzzle = pairGameFields.second;
	countMistakes_ = 0;

	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
		os_ << "\033[2J\033[H" << std::flush;
		os_ << "Sudoku: ";
		if (difficulty == GameDifficulty::Easy) {
			os_ << "EASY difficulty level\n";
		}
		if (difficulty == GameDifficulty::Medium) {
			os_ << "MEDIUM difficulty level\n";
		}
		if (difficulty == GameDifficulty::Hard) {
			os_ << "HARD difficulty level\n";
		}
		os_ << "Count mistakes you made: " << countMistakes_ << "\n";
		os_ << gameFieldPuzzle;
		os_ << "Enter ROW, COLUMN and VALUE you want to set into the cell.\n";
		os_ << "You need to enter three numbers, every number is in range 1-9.\n";
		os_ << "Or enter 'q' to go to Main Menu.\n";
		int row = 0;
		int column = 0;
		int value = 0;
		char ch = is_.peek();
		if (ch == 'q') {

		}
		is_ >> row >> column >> value;
		if (is_.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			os_ << "Error: you need to enter 3 numbers in range 1-9. Try again.\n\n";
			continue;
		}
		if (row < 1 || row > 9) {
			os_ << "Error: ROW must be in range 1-9. Try again.\n\n";
			continue;
		}
		if (column < 1 || column > 9) {
			os_ << "Error: COLUMN must be in range 1-9. Try again.\n\n";
			continue;
		}
		if (value < 1 || value > 9) {
			os_ << "Error: VALUE must be in range 1-9. Try again.\n\n";
			continue;
		}
		if (value == gameFieldFilled.getCellNumber(row-1, column-1)) {
			gameFieldPuzzle.setCellNumber(row-1, column-1, value);
			os_ << "Good!\n\n";
			continue;
		}
		else {
			countMistakes_++;
			os_ << "Mistake...\n\n";
			continue;
		}
	}
}