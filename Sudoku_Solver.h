#pragma once
#include "Sudoku.h"
class Sudoku_Sol : public Sudoku
{
public:
	Sudoku_Sol(Sudoku S);
	Sudoku_Sol();
	void ReadSudoku(string filename);
	bool InvalidCheck();
	void solve(int dfs = 0);
private:
	bool success;
};