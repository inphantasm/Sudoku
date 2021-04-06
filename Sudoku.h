#pragma once
#include<algorithm>
#include<ctime>
#include<fstream>
#include<iostream>
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
};