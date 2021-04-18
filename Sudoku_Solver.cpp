#include "Sudoku_Solver.h"
Sudoku_Sol::Sudoku_Sol(Sudoku S)
// 意外地：不能用冒号赋值
{
	blank = S.blank;
	matrix = S.matrix;
	success = false;
}
Sudoku_Sol::Sudoku_Sol() :
	Sudoku()
{
	success = false;
}
void Sudoku_Sol::ReadSudoku(string filename)
{
	square tempmatrix = matrix;
	ifstream fin(filename);
	while (!fin.eof()/*.peek() != EOF*/) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fin >> matrix[i][j];
			}
		}
		if (matrix == tempmatrix)
			return;
		output();
		if (InvalidCheck())
			solve();
		else cout << "-----the Sudoku is invalid-----" << endl;
		matrix = tempmatrix;
	}
}
bool Sudoku_Sol::InvalidCheck()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			vector<int> n = Possibility(i, j);
			if (n.size() == 0) return false;
			bool flag = true;
			if (matrix[i][j] == '$') continue;
			for (auto num : n)
			{
				if (num == matrix[i][j] - '0')
				{
					flag = false;
				}
			}
			if (flag) return false;
		}
	}
	return true;
}
void Sudoku_Sol::solve(int dfs)
{
	if (dfs == 81)
	{
		success = true;
		output();
		return;
	}
	if (matrix[dfs / 9][dfs % 9] != '$')
	{
		solve(dfs + 1);
		return;
	}
	vector<int> available = Possibility(dfs / 9, dfs % 9);
	for (auto num : available)
	{
		matrix[dfs / 9][dfs % 9] = num + '0';
		solve(dfs + 1);
		if (success) return;
		matrix[dfs / 9][dfs % 9] = '$';
	}
}