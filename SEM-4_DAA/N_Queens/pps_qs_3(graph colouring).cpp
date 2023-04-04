/*
Question

Graph coloring problem involves the assignment of colors to each vertex of a graph G such that no adjacent vertices get same color. The task is
to colour the graph G with minimum number of colours. Design a backtracking c++ code to solve the graph colouring Problem.

Algorithm

Start by defining constants and variables, including the maximum number of vertices MAXN, an adjacency list vector graph, the number of colors numColors, and a color array.
Implement a function canColor which checks if a vertex can be assigned a particular color by examining its neighbors.
Implement a recursive function colorGraph which attempts to color each vertex with a color that doesn't conflict with the color of its neighbors. It returns true if it is able to successfully color all vertices.
In the main function, take input for the number of vertices n and edges m and read in the edge pairs into the adjacency list graph.
Set the number of colors to 1 and repeatedly attempt to color the graph using colorGraph. If successful, print the minimum number of colors required and the coloring of each vertex. If unsuccessful, increment the number of colors and reset the color array.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100;

vector<int> graph[MAXN];
int numColors;
int color[MAXN];

bool canColor(int v, int c) {
    for (int u : graph[v]) {
        if (color[u] == c) {
            return false;
        }
    }
    return true;
}

bool colorGraph(int v, int n) {
    if (v == n) {
        return true;
    }
    for (int c = 1; c <= numColors; c++) {
        if (canColor(v, c)) {
            color[v] = c;
            if (colorGraph(v + 1, n)) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    cout << "Enter the edges (vertex numbering starts from 0):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    numColors = 1;
    while (true) {
        if (colorGraph(0, n)) {
            cout << "Minimum number of colors required: " << numColors << endl;
            for (int i = 0; i < n; i++) {
                cout << "Vertex " << i << " is colored with " << color[i] << endl;
            }
            break;
        }
        numColors++;
        for (int i = 0; i < n; i++) {
            color[i] = 0;
        }
    }
    return 0;
}
