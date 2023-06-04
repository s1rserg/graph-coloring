#include "pch.h"
#include "Algorithm.h"

bool BacktrackingAlgorithm::isSafe(int vertex, vector<vector<int>>& matrix, vector<int>& colors, int color) {
    for (int c = 0; c < matrix.size(); c++) if (matrix[vertex][c] && colors[c] == color) return false;
    return true;
}

int BacktrackingAlgorithm::getVertexWithMRV(vector<vector<int>>& matrix, vector<int>& colors) {
    int minRemaining = INT_MAX, nextVertex = -1;

    for (int i = 0; i < matrix.size(); i++) {
        if (colors[i] == 0) {
            int remaining = 0;
            for (int j = 1; j <= colors.size(); j++) if (isSafe(i, matrix, colors, j)) remaining++;
            if (remaining < minRemaining) {
                minRemaining = remaining;
                nextVertex = i;
            }
        }
    }
    return nextVertex;
}

int BacktrackingAlgorithm::getVertexWithDegree(vector<vector<int>>& matrix, vector<int>& colors) {
    int maxDegree = 0, nextVertex = -1;

    for (int i = 0; i < matrix.size(); i++) {
        if (colors[i] == 0) {
            int degree = 0;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j]) degree++;
            }
            if (degree > maxDegree) {
                maxDegree = degree;
                nextVertex = i;
            }
            if (degree == 0 && maxDegree == 0) {
                nextVertex = i;
            }
        }
    }

    return nextVertex;
}

bool BacktrackingAlgorithm::assignColors(vector<vector<int>>& matrix, vector<int>& colors, int vertex, int max_colors, vector<int>& testOrder) {
    if (vertex == matrix.size()) return true;
    int nextVertex;
    if (heuristic) nextVertex = getVertexWithMRV(matrix, colors);
    else nextVertex = getVertexWithDegree(matrix, colors);
    if (nextVertex == -1) return false;
    testOrder.push_back(nextVertex);
    verticesAssigned++;
    if (verticesAssigned > 10000000) {
        success = false;
        return false;
    }

    for (int color = 1; color <= max_colors; color++) {
        if (isSafe(nextVertex, matrix, colors, color)) {
            colors[nextVertex] = color;
            if (assignColors(matrix, colors, vertex + 1, max_colors, testOrder)) return true;
            colors[nextVertex] = 0;
            testOrder.pop_back();
            comebacks++;
        }
    }
    return false;
}

vector<int> BacktrackingAlgorithm::solve(vector<vector<int>>& matrix) {
    int n = int(matrix.size());
    int numColors = int(matrix.size());
    comebacks = 0;
    verticesAssigned = 0;
    success = true;
    vector<int> colors(n, 0);
    vector<int> testColors(n, 0);
    vector<int> testOrder;

    while (numColors > 0) {
        if (assignColors(matrix, testColors, 0, numColors, testOrder)) {
            colors = testColors;
            order = testOrder;

            chromaticNumber = 1;
            for (int color: colors) {
                if (color > chromaticNumber) {
                    chromaticNumber = color;
                }
            }
            numColors = chromaticNumber - 1;
        }
        else {
            chromaticNumber = 1;
            for (int color: colors) {
                if (color > chromaticNumber) {
                    chromaticNumber = color;
                }
            }
            return colors;
        }
        testColors = vector<int>(n, 0);
        testOrder.clear();
    }
    return colors;
}

vector<int> GreedyAlgorithm::solve(vector<vector<int>>& matrix) {
    colorsTried = 1;
    int n = int(matrix.size());
    vector<int> colors(n, 0);
    colors[0] = 1;

    for (int i = 1; i < n; i++) {
        order.push_back(i);
        unordered_set<int> used_colors(n);
        for (int j = 0; j < n; j++) if (matrix[i][j] && colors[j] != 0) used_colors.insert(colors[j]);
        colors[i] = 1;
        while (used_colors.count(colors[i]) > 0) {
            colors[i]++;
            colorsTried++;
        }
        colorsTried++;
    }
    chromaticNumber = 1;
    for (int color : colors) {
        if (color > chromaticNumber) {
            chromaticNumber = color;
        }
    }
    return colors;
}

int BacktrackingAlgorithm::getVerticesAssigned() {
    return verticesAssigned;
}

int BacktrackingAlgorithm::getComebacks() {
    return comebacks;
}

int Algorithm::getChromaticNumber() {
    return chromaticNumber;
}

int Algorithm::getElementOrder(int i) {
    if (i < order.size()) {
        return order[i];
    }
    return 0;
}

int GreedyAlgorithm::getColorsTried() {
    return colorsTried;
}

bool BacktrackingAlgorithm::getSuccess() {
    return success;
}

void BacktrackingAlgorithm::setHeuristic(bool h) {
    heuristic = h;
}