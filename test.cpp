#include "Sudoku_Generator.h"
int main()
{
	square t;
	Sudoku_Gen Gen;
	t = Gen.GenFinal_Elegant(50);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << char(t[i][j]) << " ";
		}
		cout << endl;
	}
	return 0;
}