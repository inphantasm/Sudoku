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
	int blockx = x / 3, blocky = y / 3;
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
	for (int i = blockx * 3; i < blockx * 3 + 3; i++)
	{
		for (int j = blocky * 3; j < blocky * 3 + 3; j++)
		{
			if (i == x && j == y) continue;
			int E = matrix[i][j] == '#' ? 0 : matrix[i][j] - '0';
			exist[E] = 1;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		if (!exist[i])
			result.push_back(i);
	}
	return result;
}
void Sudoku::output()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << char(matrix[i][j]) << " ";
		}
		cout << endl;
	}
	cout << endl;
}