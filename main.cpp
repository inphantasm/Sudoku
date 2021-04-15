#include "Sudoku_Generator.h"
#include "Sudoku_Solver.h"
bool unique_flag = 0;
int main(int argc, char** argv)
{
	int temp = argc;
	bool argv_flag = 0;
	int fina_sudo_num;
	string  sudo_file;
	// ���� 4.15
	int game_num = 0;
	// Ĭ����Ϸ�Ѷ�Ϊ1-��
	int game_level = 1;
	//int blank_num;
	vector<string> argvs;

	int j = 1;
	while (temp-- != 1) {
		argvs.push_back(string(argv[j++]));
	}

	if (argvs[0] == "-c") {
		string  str(argvs[1]);
		fina_sudo_num = atoi(str.c_str());
		Sudoku_Gen Gen;
		square tempmatrix = Gen.matrix;
		while (fina_sudo_num) {
			Gen.GenFinal_Elegant();
			cout << endl << "end: " << fina_sudo_num << endl << endl;
			Gen.output();
			Gen.matrix = tempmatrix;
			fina_sudo_num--;
		}
		return 0;
	}
	if (argvs[0] == "-s") {
		sudo_file = string(argvs[1]);
		Sudoku_Sol Solve;
		Solve.ReadSudoku(sudo_file);
		//Solve.output();
		//Solve.solve();
		return 0;
		//InvalidCheck() ���������⡣���������
		//if (Solve.InvalidCheck()) {
		//	Solve.solve();
		//	return 0;
		//}

		//else {
		//	cout << endl << "��ǰ������Ч" << endl;
		//	return 0;
		//}
	}

	//���-n���������������������ֵĳ������
	for (auto arg : argvs) {
		if (arg == "-n")
			argv_flag = true;
	}

	//for (auto x : argvs) {
	//	cout << x << " ";
	//}
	//cout << endl;

	if (!argv_flag) {
		auto ite = argvs.begin();
		for (ite; ite != argvs.end(); ite++) {
			if (*ite == "-m" || *ite == "-r" || *ite == "-u") {
				cout << endl << "�Ƿ�����" << endl;
				return 0;
			}
		}
	}
	else {
		auto ite = argvs.begin();
		for (ite; ite != argvs.end(); ite++) {
			if (*ite == "-n") {
				string  str(*(ite + 1));
				game_num = atoi(str.c_str());
				ofstream fout("gamenum.txt");
				fout << game_num;
				fout.close();
				ite += 1;
			}
			// �Ѷ��趨-difficulty.ini
			else if (*ite == "-m") {
				string  str(*(ite + 1));
				game_level = atoi(str.c_str());
				ite += 1;
			}

			else if (*ite == "-u") {
				unique_flag = true;
			}
		}
		// ��ʼִ��
		Sudoku_Gen Gen;
		square tempmatrix = Gen.matrix;
		while (game_num--) {
			cout << endl << "game: " << game_num + 1 << endl;
			Gen.Sudoku_Init(game_level, unique_flag);
			Gen.matrix = tempmatrix;
		}

		//ofstream fopen("game.txt");
		//fopen.close();
		return 0;
	}
	return 0;
}