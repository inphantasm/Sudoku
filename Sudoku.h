#pragma once
#include<iostream>
#include<vector>
#include<ctime>
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