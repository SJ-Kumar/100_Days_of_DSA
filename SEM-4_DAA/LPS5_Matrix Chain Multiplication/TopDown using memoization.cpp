#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // initialize to maximum integer value

int dp[101][101]; // memoization table for storing optimal solutions

int matrix_chain_order(int p[], int i, int j) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int min_cost = INF;
    for (int k = i; k < j; k++) {
        int cost = matrix_chain_order(p, i, k) + matrix_chain_order(p, k+1, j) + p[i-1]*p[k]*p[j];
        min_cost = min(min_cost, cost);
    }
    dp[i][j] = min_cost;
    return dp[i][j];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int p[n+1];
    cout << "Enter the dimensions of the matrices:\n";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    memset(dp, -1, sizeof(dp)); // initialize memoization table to -1
    int optimal_cost = matrix_chain_order(p, 1, n);
    cout << "Minimum cost of multiplication: " << optimal_cost << endl;
    return 0;
}
