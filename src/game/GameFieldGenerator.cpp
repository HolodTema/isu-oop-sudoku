#include "../../include/game/GameFieldGenerator.hpp"
#include <vector>
#include <algorithm>
#include <functional>


std::pair<GameField, GameField> GameFieldGenerator::generate() {
	int* boardFilled = new int[81];
	std::fill_n(boardFilled, 81, 0);

	fillBoardRecursiveBacktracking(boardFilled);

	int* boardPuzzle = new int[81];
	std::fill_n(boardPuzzle, 81, 0);

	for (int i = 0; i < 81; ++i) {
		boardPuzzle[i] = boardFilled[i];
	}

	removeCellsFromFilledBoard(boardPuzzle);

	GameField gameFieldFilled;
	GameField gameFieldPuzzle;

	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			gameFieldFilled.setCellNumber(row, column, boardFilled[row*9 + column]);
			if (boardPuzzle[row*9 + column] != 0) {
				gameFieldPuzzle.setCellNumber(row, column, boardPuzzle[row*9 + column]);
			}
		}
	}
	delete[] boardFilled;
	delete[] boardPuzzle;

	return {gameFieldFilled, gameFieldPuzzle};
}

bool GameFieldGenerator::isPossibleToSetNumberToCell(const int* board, int row, int column, int number) const {
	for (int i = 0; i < 9; ++i) {
		if (board[row*9 + i] == number) {
			return false;
		}
		if (board[i*9 + column] == number) {
			return false;
		}
	}

	int sectorTopLeftRow = row - (row % 3);
	int sectorTopLeftColumn = column - (column % 3);
	for (int r = sectorTopLeftRow; r < sectorTopLeftRow + 3; ++r) {
		for (int c = sectorTopLeftColumn; c < sectorTopLeftColumn + 3; ++c) {
			if (board[r*9 + c] == number) {
				return false;
			}
		}
	}
	return true;
}

bool GameFieldGenerator::fillBoardRecursiveBacktracking(int* board) {
	int firstEmptyRow = -1;
	int firstEmptyColumn = -1;
	for (int r = 0; (r < 9 && firstEmptyRow == -1); ++r) {
		for (int c = 0; c < 9; ++c) {
			if (board[r*9 + c] == 0) {
				firstEmptyRow = r;
				firstEmptyColumn = c;
				break;
			}
		}
	}

	if (firstEmptyRow == -1 || firstEmptyColumn == -1) {
		return true;
	}

	std::vector<int> vecRowNums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::shuffle(vecRowNums.begin(), vecRowNums.end(), randomNumberGenerator);

	for (int num : vecRowNums) {
		if (isPossibleToSetNumberToCell(board, firstEmptyRow, firstEmptyColumn, num)) {
			board[firstEmptyRow*9 + firstEmptyColumn] = num;

			bool isRecursiveFillingSuccess = fillBoardRecursiveBacktracking(board);
			if (isRecursiveFillingSuccess) {
				return true;
			}
			board[firstEmptyRow*9 + firstEmptyColumn] = 0;
		}
	}
	return false;
}

int GameFieldGenerator::countBoardSolutions(int* board, int limitOfSolutionsToStop) {
	int countSolutions = 0;

	std::function<void(int*)> countBoardSolutionsRecursive = [&](int* b) -> void {
		if (countSolutions >= limitOfSolutionsToStop) {
			return;
		}

		int firstEmptyRow = -1;
		int firstEmptyColumn = -1;
		for (int r = 0; (r < 9 && firstEmptyRow == -1); ++r) {
			for (int c = 0; c < 9; ++c) {
				if (b[r*9 + c] == 0) {
					firstEmptyRow = r;
					firstEmptyColumn = c;
					break;
				}
			}
		}

		if (firstEmptyRow == -1 || firstEmptyColumn == -1) {
			++countSolutions;
			return;
		}

		for (int num = 1; num <= 9; ++num) {
			if (isPossibleToSetNumberToCell(b, firstEmptyRow, firstEmptyColumn, num)) {
				b[firstEmptyRow*9 + firstEmptyColumn] = num;
				countBoardSolutionsRecursive(b);
				b[firstEmptyRow*9 + firstEmptyColumn] = 0;
				if (countSolutions >= limitOfSolutionsToStop) {
					return;
				}
			}
		}
	};

	int* tempBoard = new int[81];
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			tempBoard[row*9 + column] = board[row*9 + column];
		}
	}

	countBoardSolutionsRecursive(tempBoard);
	delete[] tempBoard;
	return countSolutions;
}

void GameFieldGenerator::removeCellsFromFilledBoard(int* board) {
	std::vector<std::pair<int, int>> vecAllCellPositions(81);
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			vecAllCellPositions[row*9 + column] = std::make_pair(row, column);
		}
	}
	std::shuffle(vecAllCellPositions.begin(), vecAllCellPositions.end(), randomNumberGenerator);

	int countRemovedCells = 0;
	for (auto [row, column] : vecAllCellPositions) {
		if (countRemovedCells >= static_cast<int>(difficulty_)) {
			return;
		}

		int cellBackup = board[row*9 + column];
		board[row*9 + column] = 0;
		if (countBoardSolutions(board, 2) == 1) {
			++countRemovedCells;
		}
		else {
			board[row*9 + column] = cellBackup;
		}
	}
}
