#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <algorithm>
using namespace std;

class Algorithm {
protected:
    int chromaticNumber;
    vector<int> order;
public:
    int getChromaticNumber();
    int getElementOrder(int i);
    virtual vector<int> solve(vector<vector<int>>& matrix) = 0;
};

class GreedyAlgorithm: public Algorithm {
    int colorsTried;
public:
    int getColorsTried();
    vector<int> solve(vector<vector<int>>& matrix);
};

class BacktrackingAlgorithm : public Algorithm {
    bool heuristic; //true = mrv, false = degree
    int comebacks;
    int verticesAssigned;
    bool success;
public:
    void setHeuristic(bool h);
    int getVerticesAssigned();
    int getComebacks();
    vector<int> solve(vector<vector<int>>& matrix);
    bool isSafe(int vertex, vector<vector<int>>& matrix, vector<int>& colors, int color);
    int getVertexWithMRV(vector<vector<int>>& matrix, vector<int>& colors);
    int getVertexWithDegree(vector<vector<int>>& matrix, vector<int>& colors);
    bool assignColors(vector<vector<int>>& matrix, vector<int>& colors, int vertex, int max_colors, vector<int>& testOrder);
    bool getSuccess();
};
