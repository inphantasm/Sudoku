#pragma once
#include<iostream>
using namespace std;
class Sudoku
{
public:
	char matrix[9][9];
	int blank;
	Sudoku();
	~Sudoku();
};