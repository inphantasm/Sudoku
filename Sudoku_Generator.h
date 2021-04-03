#pragma once
#include "Sudoku.h"
class Sudoku_Gen : public Sudoku
{
public:
	vector<pair<int, int>> difficulty;

	Sudoku_Gen(bool Unique = false);
	bool Sudoku_Init(int diff);
private:
	square GenFinal_Violent(int tolerance = 22);
	square GenFinal_Elegant(int transform = 1000);
	bool unique_excision(int count = 81);
	bool random_excision(int count = 0);
	bool swap_row(int line1, int line2, bool ANY = false);
	bool swap_col(int line1, int line2, bool ANY = false);
	bool swap_row_chunk(int line1, int line2);
	bool swap_col_chunk(int line1, int line2);
};