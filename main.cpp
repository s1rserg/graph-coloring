#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int vertex, vector<vector<int>> &matrix, vector<int> &colors, int color) {
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[vertex][i] && colors[i] == color) return false;
    }
    return true;
}

int getVertexWithMRV(vector<vector<int>> &matrix, vector<int> &colors) {
    int minRemaining = INT_MAX;
    int nextVertex = -1;

    for (int v = 0; v < matrix.size(); v++) {
        if (colors[v] == 0) {
            int remaining = 0;
            for (int color = 1; color <= colors.size(); color++) {
                if (isSafe(v, matrix, colors, color)) remaining++;
            }
            if (remaining < minRemaining) {
                minRemaining = remaining;
                nextVertex = v;
            }
        }
    }
    return nextVertex;
}

int getVertexWithDegree(vector<vector<int>> &matrix, vector<int> &colors) {
    int maxDegree = 0;
    int nextVertex = -1;

    for (int v = 0; v < matrix.size(); v++) {
        if (colors[v] == 0) {
            int degree = 0;
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[v][i]) degree++;
            }
            if (degree > maxDegree) {
                maxDegree = degree;
                nextVertex = v;
            }
        }
    }

    return nextVertex;
}

bool assignColors(vector<vector<int>> &matrix, vector<int> &colors, int vertex, int max_colors, char heuristics) {
    if (vertex == matrix.size()) return true;
    int nextVertex;
    if (heuristics == 'm') {
        nextVertex = getVertexWithMRV(matrix, colors);
    } else {
        nextVertex = getVertexWithDegree(matrix, colors);
    }

    for (int color = 1; color <= max_colors; color++) {
        if (isSafe(nextVertex, matrix, colors, color)) {
            colors[nextVertex] = color;
            if (assignColors(matrix, colors, vertex + 1, max_colors, heuristics)) return true;
            colors[nextVertex] = 0;
        }
    }
    return false;
}

vector<int> heuristicAlgorithm(vector<vector<int>> &matrix, char heuristics) {
    int n = matrix.size();
    vector<int> colors(n, 0);

    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (assignColors(matrix, colors, 0, mid, heuristics)) hi = mid;
        else lo = mid + 1;
    }
    assignColors(matrix, colors, 0, lo, heuristics);

    return colors;
}

int first_available(vector<int> &used_colors, int n) {
    int vertex = 1;
    while (true) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (used_colors[i] == vertex) {
                vertex++;
                flag = true;
                break;
            }
        }
        if (!flag) return vertex;
    }
}

vector<int> greedyAlgorithm(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<int> colors(n, 0);
    colors[0] = 1;

    for (int i = 1; i < n; i++) {
        int used_colors_count = 0;
        vector<int> used_colors(n, 0);
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] && colors[j] != 0) {
                used_colors[used_colors_count] = colors[j];
                used_colors_count++;
            }
        }
        colors[i] = first_available(used_colors, used_colors_count);
    }
    return colors;
}

int main() {
    vector<vector<int>> matrix = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 1, 0}
    };
    int choice;
    cout << "Greedy or Backtracking (0/1)";
    cin >> choice;
    cin.ignore();

    vector<int> colors;
    if (choice == 0) {
        colors = greedyAlgorithm(matrix);
        for (int i = 0; i < colors.size(); i++) {
            cout << "Vertex " << i + 1 << " : " << colors[i] << " ";
        }
    } else {
        cout << "MRV or Degree (0/1)";
        cin >> choice;
        cin.ignore();
        if (choice == 0) colors = heuristicAlgorithm(matrix, 'm');
        else colors = heuristicAlgorithm(matrix, 'd');
        for (int color: colors) cout << color << " ";
    }

    return 0;
}
