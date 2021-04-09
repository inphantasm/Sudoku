#include "Sudoku_Generator.h"
#include "Sudoku_Solver.h"
int main()
{
	square t;
	Sudoku_Gen Gen;
	Gen.Sudoku_Init(3);
	Sudoku_Sol Sol(Gen.Sudokize());
	Sol.solve();
	return 0;
}