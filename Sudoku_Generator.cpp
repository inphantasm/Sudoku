#include "Sudoku_Generator.h"

square Sudoku_Gen::GenFinal_Violent(int tolerance)
/*
 * 生成一个数独终局
 * 无法满足九宫格法则
 * tolerance = 22的原因在Research篇提及
*/
{
	srand(unsigned int(time(NULL)));
	square result(9, vector<char>(9, '#'));
	int tries = 0;
	for (int i = 0; i < 9; i++)
	{
		int curTries = tries;
		for (int j = 0; j < 9; j++)
		{
			/*
			 * 重新启动，再试一次
			*/
		retry:		tries++;
			if (curTries + tolerance == tries)
			{
				/*
				 * 达到容忍极限，判断本行生成不能满足数独条件
				 * 重新生成本行
				*/
				result[i] = vector<char>(9, 0);
				i--;
				break;
			}
			int t = rand() % 9 + 49;
			for (int k = 0; k < 9; k++)
			{
				if (result[k][j] == t || result[i][k] == t)
				{
					/*
					 * 生成了重复的随机数
					*/
					goto retry;
				}
			}
			/*
			 * 生成的随机数满足条件，填入方阵
			*/
			result[i][j] = t;
			curTries = tries;
		}
	}
	return result;
}
square Sudoku_Gen::GenFinal_Elegant(int transform)
{
	/*
	 * 读取初始终局
	 * 您可以自行写入一个终局，本程序保证将其改得面目全非
	*/
	srand(unsigned int(time(NULL)));
	ifstream fin("Starting.ini");
	square result(9, vector<char>(9, '#'));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fin >> result[i][j];
		}
	}
	/*
	 * 根据参数transform决定随机变化的次数，缺省为100次
	*/
	while (transform--)
	{
		int method = rand() % 4;
		int arg1 = rand() % 9, arg2 = rand() % 9;
		switch (method)
		{
		case 0:
			transform += swap_row(result, arg1, arg2);
			break;
		case 1:
			transform += swap_col(result, arg1, arg2);
			break;
		case 2:
			transform += swap_row_chunk(result, arg1 % 3, arg2 % 3);
			break;
		case 3:
			transform += swap_col_chunk(result, arg1 % 3, arg2 % 3);
			break;
		default:
			break;
		}
	}
	return result;
}
bool Sudoku_Gen::swap_row(square& matrix, int line1, int line2, bool ANY)
{
	if (ANY || line1 / 3 == line2 / 3)
	{
		for (int i = 0; i < 9; i++)
		{
			int temp = matrix[line1][i];
			matrix[line1][i] = matrix[line2][i];
			matrix[line2][i] = temp;
		}
		return 0;
	}
	else
		return 1;
}
bool Sudoku_Gen::swap_col(square& matrix, int line1, int line2, bool ANY)
{
	if (ANY || line1 / 3 == line2 / 3)
	{
		for (int i = 0; i < 9; i++)
		{
			int temp = matrix[i][line1];
			matrix[i][line1] = matrix[i][line2];
			matrix[i][line2] = temp;
		}
		return 0;
	}
	else
		return 1;
}
bool Sudoku_Gen::swap_row_chunk(square& matrix, int line1, int line2)
{
	for (int i = 0; i < 3; i++)
	{
		swap_row(matrix, line1 * 3 + i, line2 * 3 + i, true);
	}
	return 0;
}
bool Sudoku_Gen::swap_col_chunk(square& matrix, int line1, int line2)
{
	for (int i = 0; i < 3; i++)
	{
		swap_col(matrix, line1 * 3 + i, line2 * 3 + i, true);
	}
	return 0;
}