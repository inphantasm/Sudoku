#include "Sudoku_Generator.h"
#include "Sudoku_Solver.h"
int main(int argc, char** argv)
{
	int temp = argc;
	bool argv_flag = 0;
	bool unique_flag = 0;
	int fina_sudo_num;
	string  sudo_file;
	int game_num;
	int game_level;
	int blank_num;
	vector<string> argvs;

	int j = 1;
	while (temp-- != 1) {
		argvs.push_back(string(argv[j++]));
	}
	//检查-n，这是另外三个参数出现的充分条件
	for (auto arg : argvs) {
		if (arg == "-n")
			argv_flag = true;
	}

	//for (auto x : argvs) {
	//	cout << x << " ";
	//}

	if (!argv_flag) {
		auto ite = argvs.begin();
		for (ite; ite != argvs.end(); ite++) {
			if (*ite == "-c") {
				string  str(*(ite + 1));
				fina_sudo_num = atoi(str.c_str());
				ite += 1;
			}
			else if (*ite == "-s") {
				sudo_file = string(*(ite + 1));
				ite += 1;
			}
			if (*ite == "-m" || *ite == "-r" || *ite == "-u") {
				cout << endl << "非法参数" << endl;
				return 0;
			}
		}
	}
	else {
		auto ite = argvs.begin();
		for (ite; ite != argvs.end(); ite++) {
			if (*ite == "-c") {
				string  str(*(ite + 1));
				fina_sudo_num = atoi(str.c_str());
				ite += 1;
			}
			else if (*ite == "-s") {
				sudo_file = string(*(ite + 1));
				ite += 1;
			}
			else if (*ite == "-n") {
				string  str(*(ite + 1));
				game_num = atoi(str.c_str());
				ite += 1;
			}
			else if (*ite == "-m") {
				string  str(*(ite + 1));
				game_level = atoi(str.c_str());
				ite += 1;
			}
			else if (*ite == "-r") {
				string  str(*(ite + 1));
				blank_num = atoi(str.c_str());
				ite += 1;
			}
			else if (*ite == "-u") {
				unique_flag = true;
			}
		}
	}

	square t;
	Sudoku_Sol Solve;
	if (sudo_file == "")
		Solve.ReadSudoku("Starting.ini");
	else Solve.ReadSudoku(sudo_file);
	Solve.output();
	cout << Solve.InvalidCheck();
	return 0;
}