#include "../include/GameHandler.hpp"
#include <iostream>

void GameHandler::run() {
	while (true) {
		showMainMenuScreen();
	}
}

void GameHandler::showMainMenuScreen() {
	while (true) {
		os_ << "Sudoku CLI Game. Main menu.\n";
		os_ << "1. New game\n";
		os_ << "2. Exit\n";
		int option = 0;
		is_ >> option;
		if (option == 1) {
			showGameScreen();
			return;
		}
		if (option == 2) {
			os_ << "\nExit...\n";
			return;
		}
		os_ << "Invalid option. You need to press key 1 or key 2.\n";
	}
}
