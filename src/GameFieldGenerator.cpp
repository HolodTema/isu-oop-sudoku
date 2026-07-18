#include "../include/GameFieldGenerator.hpp"
#include <vector>
#include <algorithm>

std::pair<GameField, GameField> GameFieldGenerator::generate() const {

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
			return false;
		}
	}
	return false;
}

int GameFieldGenerator::countBoardSolutions(int* board, int limitOfSolutionsToStop) {
	int countSolutions = 0;
	

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
		if (countRemovedCells > difficulty_) {
			break;
		}

		int cellBackup = board[row*9 + column];
		if (countBoardSolutions(board, 2) == 1) {
			++countRemovedCells;
		}
		else {
			board[row*9 + column] = cellBackup;
		}
	}
}
