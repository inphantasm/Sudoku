#include "Sudoku.h"
Sudoku::Sudoku()
{
	matrix = square(9, vector<char>(9, '#'));
	blank = 81;
	// cout << "Sudoku Created." << endl;
}
Sudoku::~Sudoku()
{
	// cout << "Sudoku Destroyed." << endl;
}