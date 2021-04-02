#include "Sudoku_Generator.h"
/*
 * 生成一个
 * tolerance = 22的原因在Research篇提及
*/
square Sudoku_Gen::GenFinal_Violent(int tolerance = 22)
{
	srand(time(NULL));
	square result(9, vector<char>(9, 0));
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
			int t = rand() % 9 + 1;
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