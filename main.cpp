#include "Sudoku_Generator.h"
#include "Sudoku_Solver.h"
bool unique_flag = 0;
int main(int argc, char** argv)
{
	int temp = argc;
	bool argv_flag = 0;
	int fina_sudo_num;
	string  sudo_file;
	// 调试 4.15
	int game_num = 0;
	// 默认游戏难度为1-简单
	int game_level = 1;
	vector<string> argvs;
	try {
		int j = 1;
		while (temp-- != 1) {
			argvs.push_back(string(argv[j++]));
		}
		if (argvs[0] == "-c") {
			if (argvs.size() <= 1)
				throw "-c: less argument";
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
			if (argvs.size() <= 1)
				throw "-s: less argument";
			sudo_file = string(argvs[1]);
			Sudoku_Sol Solve;
			Solve.ReadSudoku(sudo_file);
			return 0;
		}
		//检查-n，这是另外三个参数出现的充分条件
		for (auto arg : argvs) {
			if (arg == "-n")
				argv_flag = true;
		}
		if (!argv_flag) {
			auto ite = argvs.begin();
			for (ite; ite != argvs.end(); ite++) {
				if (*ite == "-m" || *ite == "-r" || *ite == "-u") {
					cout << endl << "非法参数" << endl;
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
				// 难度设定-difficulty.ini
				else if (*ite == "-m") {
					if (*ite != "1" || *ite != "2" || *ite != "3")
						throw "-m: invalid arguments";
					string  str(*(ite + 1));
					game_level = atoi(str.c_str());
					ite += 1;
				}

				else if (*ite == "-u") {
					unique_flag = true;
				}
			}
			// 开始执行
			Sudoku_Gen Gen;
			square tempmatrix = Gen.matrix;
			while (game_num--) {
				cout << endl << "game: " << game_num + 1 << endl;
				Gen.Sudoku_Init(game_level, unique_flag);
				Gen.matrix = tempmatrix;
			}
			return 0;
		}
	}
	catch (const char* s) {
		if (s == "game.txt open failed") {
			cout << "Sudoku_Sol::ReadSudoku(string filename) : game.txt open failed" << endl;
			return 1;
		}
		if (s == "-c: less argument") {
			cout << "-c: less argument" << endl;
			return 2;
		}
		if (s == "-s: less argument") {
			cout << "-s: less argument" << endl;
			return 3;
		}
		if (s == "-m: invalid arguments") {
			cout << "-m: invalid arguments" << endl;
			return 4;
		}
		if (s == "file create falied") {
			cout << "file create falied" << endl;
			return 5;
		}
	}
	return 0;
}