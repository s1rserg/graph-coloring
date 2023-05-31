#include "pch.h"
#include "Graph.h"


void Graph::setMatrix(vector<vector<int>>& matrix1, int size) {
	verticesNum = size;
	matrix = matrix1;
}

void Graph::setColors(vector<int>& colors1) {
	colors = colors1;
}

vector<vector<int>> Graph::getMatrix() {
	return matrix;
}

vector<int> Graph::getColors() {
	return colors;
}

int Graph::getElementColors(int n) {
	return colors[n];
}

bool Graph::fileoutput() {

	std::ofstream outputFile("result.txt");


	if (outputFile.is_open()) {

		outputFile << "Number of vertices: " << verticesNum << endl;

		outputFile << "Adjacency matrix: " << endl;
		for (int i = 0; i < verticesNum; i++) {
			for (int j = 0; j < verticesNum; j++) {
				outputFile << matrix[i][j] << " ";
			}
			outputFile << endl;
		}
		outputFile << endl;

		outputFile << "Assigned colors: " << endl;

		for (int i = 0; i < verticesNum; i++) {
			outputFile << "V" << (i + 1) << ": " << getElementColors(i) << " ";
		}
		outputFile << endl;


		outputFile.close();

	}
	else {
		return false;
	}
	return true;
}