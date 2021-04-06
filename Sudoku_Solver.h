#pragma once
#include "Sudoku.h"
class Sudoku_Sol : public Sudoku
{
public:
	Sudoku_Sol(Sudoku S);
	void solve(int dfs = 0);
private:
	bool success;
};