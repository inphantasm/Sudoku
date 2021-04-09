#include "Sudoku_Generator.h"

Sudoku_Gen::Sudoku_Gen(bool Unique):
	Sudoku()
{
	ifstream fin("Difficulty.ini");
	for (int i = 0; i < 4; i++)
	{
		int x, y;
		fin >> x >> y;
		if (Unique) y = 0;
		difficulty.push_back(make_pair(x, y));
	}
}
bool Sudoku_Gen::Sudoku_Init(int diff)
{
	GenFinal_Elegant();
	unique_excision(difficulty[diff].first);
	random_excision(difficulty[diff].second);
	return true;
}
Sudoku Sudoku_Gen::Sudokize()
{
	Sudoku result;
	result.blank = this->blank;
	result.matrix = this->matrix;
	return result;
}
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
	 * 您可以自行写入一个终局，本方法保证将其改得面目全非
	*/
	srand(unsigned int(time(NULL)));
	ifstream fin("Starting.ini");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fin >> matrix[i][j];
		}
	}
	/*
	 * 根据参数transform决定随机变化的次数，缺省为1000次
	*/
	while (transform--)
	{
		int method = rand() % 4;
		int arg1 = rand() % 9, arg2 = rand() % 9;
		switch (method)
		{
		case 0:
			transform += swap_row(arg1, arg2);
			break;
		case 1:
			transform += swap_col(arg1, arg2);
			break;
		case 2:
			transform += swap_row_chunk(arg1 % 3, arg2 % 3);
			break;
		case 3:
			transform += swap_col_chunk(arg1 % 3, arg2 % 3);
			break;
		default:
			break;
		}
	}
	return matrix;
}
bool Sudoku_Gen::unique_excision(int count)
{
	srand(unsigned int(time(NULL)));
	/*
	 * 打乱顺序
	*/
	vector<pair<int, int>> pos;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			pos.push_back(make_pair(i, j));
		}
	}
	random_shuffle(pos.begin(), pos.end());
	for(auto p : pos)
	{
		/*
		 * 挖空唯一可能的点
		 * 后续的挖掘工作会影响前面的点，但是理论上说这样挖
		 * 一定会有至少一个“线头”，因此是有唯一解的
		*/
		int i = p.first, j = p.second;
		if (matrix[i][j] == '#') continue;
		if (Possibility(i, j).size() == 1)
		{
			matrix[i][j] = '#';
			blank++;
			if (!(--count))
				return true;
		}
	}
	return false;
}
bool Sudoku_Gen::random_excision(int count)
/*
 * 本方法**不保证**生成一个有解的数独！
 * 至少在完成Sudoku_Sol之前不保证。
*/ 
{
	if (count == 0) return true;
	vector<pair<int, int>> pos;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			pos.push_back(make_pair(i, j));
		}
	}
	random_shuffle(pos.begin(), pos.end());
	for (auto p : pos)
	{
		int i = p.first, j = p.second;
		if (matrix[i][j] == '#') continue;
		matrix[i][j] = '#';
		blank++;
		if (!(--count))
			return true;
	}
	return false;
}
bool Sudoku_Gen::swap_row(int line1, int line2, bool ANY)
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
bool Sudoku_Gen::swap_col(int line1, int line2, bool ANY)
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
bool Sudoku_Gen::swap_row_chunk(int line1, int line2)
{
	for (int i = 0; i < 3; i++)
	{
		swap_row(line1 * 3 + i, line2 * 3 + i, true);
	}
	return 0;
}
bool Sudoku_Gen::swap_col_chunk(int line1, int line2)
{
	for (int i = 0; i < 3; i++)
	{
		swap_col(line1 * 3 + i, line2 * 3 + i, true);
	}
	return 0;
}