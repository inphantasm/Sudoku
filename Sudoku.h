#pragma once
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
};