#pragma once
#include<algorithm>
#include<cstring> 
#include<ctime>
#include<fstream>
#include<iostream>
#include<ctime>
#include<vector>
#define square vector<vector<char>>
using namespace std;
class Sudoku
{
public:
	square matrix;
	int blank;
	Sudoku();
	~Sudoku();
	vector<int> Possibility(int x, int y);
	void output();
	void output2files(string filename);
};
