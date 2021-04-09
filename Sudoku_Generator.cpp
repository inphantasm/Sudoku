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
 * ����һ�������վ�
 * �޷�����Ź�����
 * tolerance = 22��ԭ����Researchƪ�ἰ
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
			int t = rand() % 9 + 49;
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
square Sudoku_Gen::GenFinal_Elegant(int transform)
{
	/*
	 * ��ȡ��ʼ�վ�
	 * ����������д��һ���վ֣���������֤����ĵ���Ŀȫ��
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
	 * ���ݲ���transform��������仯�Ĵ�����ȱʡΪ1000��
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
	 * ����˳��
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
		 * �ڿ�Ψһ���ܵĵ�
		 * �������ھ�����Ӱ��ǰ��ĵ㣬����������˵������
		 * һ����������һ������ͷ�����������Ψһ���
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
 * ������**����֤**����һ���н��������
 * ���������Sudoku_Sol֮ǰ����֤��
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