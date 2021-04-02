#pragma once
#include "Sudoku.h"
class Sudoku_Gen : public Sudoku
{
public:
	square GenFinal_Violent(int tolerance = 22);
};