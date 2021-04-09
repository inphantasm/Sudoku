#include "Sudoku_Solver.h"
Sudoku_Sol::Sudoku_Sol(Sudoku S)
// 意外地：不能用冒号赋值
{
	blank = S.blank;
	matrix = S.matrix;
	success = false;
}
void Sudoku_Sol::solve(int dfs)
{
	if (dfs == 81)
	{
		success = true;
		output();
		return;
	}
	if (matrix[dfs / 9][dfs % 9] != '#')
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
		matrix[dfs / 9][dfs % 9] = '#';
	}
}