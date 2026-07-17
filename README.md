## SUDOKU Terminal Game. Version 0.1

#### Key features:

1. generate 9x9 sudoku field of several difficulty levels: easy, normal, hard.

2. user can solve sudoku and put some numbers into cells. Errors and score are monitored.

3. autoplay mode, when a bot solves sudoku automatically with several approaches.

4. TUI or GUI are coming soon.

#### Key classes:

exceptions.hpp - internal exception classes, which we handle via try-catch blocks

LogHelper - to write logs of the game into the text file

GameField - 9x9 cells field with numbers

GameGenerator - generates sudoku GameField objects of several difficulty levels

GameHandler - controls game process: counts errors, victory situation etc.

