#include "Sudoku_Generator.h"
int main()
{
	square t;
	Sudoku_Gen Gen;
	Gen.Sudoku_Init(3);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << char(Gen.matrix[i][j]) << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}