#pragma once
#include "Sudoku.h"
class Sudoku_Gen : public Sudoku
{
public:
	square GenFinal_Violent(int tolerance = 22);
	square GenFinal_Elegant(int transform = 100);
private:
	bool swap_row(square& matrix, int line1, int line2, bool ANY = false);
	bool swap_col(square& matrix, int line1, int line2, bool ANY = false);
	bool swap_row_chunk(square& matrix, int line1, int line2);
	bool swap_col_chunk(square& matrix, int line1, int line2);
};