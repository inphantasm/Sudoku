#include "Sudoku.h"
Sudoku::Sudoku()
{
	matrix = square(9, vector<char>(9, '#'));
	blank = 81;
	// cout << "Sudoku Created." << endl;
}
Sudoku::~Sudoku()
{
	// cout << "Sudoku Destroyed." << endl;
}
vector<int> Sudoku::Possibility(int x, int y)
{
	bool exist[10];
	vector<int> result;
	memset(exist, 0, 10);
	for (int i = 0; i < 9; i++)
	{
		if (i == y) continue;
		int E = matrix[x][i] == '#' ? 0 : matrix[x][i] - '0';
		exist[E] = 1;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == x) continue;
		int E = matrix[i][y] == '#' ? 0 : matrix[i][y] - '0';
		exist[E] = 1;
	}
	for (int i = 1; i < 10; i++)
	{
		if (!exist[i])
			result.push_back(i);
	}
	return result;
}