#include "Sudoku_Generator.h"
/*
 * ����һ��
 * tolerance = 22��ԭ����Researchƪ�ἰ
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
			 * ��������������һ��
			*/
		retry:		tries++;
			if (curTries + tolerance == tries)
			{
				/*
				 * �ﵽ���̼��ޣ��жϱ������ɲ���������������
				 * �������ɱ���
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
					 * �������ظ��������
					*/
					goto retry;
				}
			}
			/*
			 * ���ɵ�������������������뷽��
			*/
			result[i][j] = t;
			curTries = tries;
		}
	}
	return result;
}