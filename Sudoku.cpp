#include "Sudoku.h"
Sudoku::Sudoku()
{
	memset(matrix, '#', 81);
	blank = 81;
}
Sudoku::~Sudoku()
{
	// cout << "Sudoku Destroyed." << endl;
}