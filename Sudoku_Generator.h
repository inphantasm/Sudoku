#pragma once
#include "Sudoku.h"
class Sudoku_Gen : public Sudoku
{
public:
	square GenFinal_Violent(int tolerance = 22);
	square GenFinal_Elegant(int transform = 1000);
	bool unique_excision(int count = 81);
private:
	bool swap_row(int line1, int line2, bool ANY = false);
	bool swap_col(int line1, int line2, bool ANY = false);
	bool swap_row_chunk(int line1, int line2);
	bool swap_col_chunk(int line1, int line2);
};