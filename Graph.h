#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Graph {
	int verticesNum;
	vector<vector<int>> matrix;
	vector<int> colors;
public:
	void setMatrix(vector<vector<int>>& matrix1, int size);

	void setColors(vector<int>& colors1);

	vector<vector<int>> getMatrix();

	vector<int> getColors();

	int getElementColors(int n);

	bool fileoutput();

};
