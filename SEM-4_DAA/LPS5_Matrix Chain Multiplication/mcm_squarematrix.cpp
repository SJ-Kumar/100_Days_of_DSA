/*
Identify a matrix-chain of n square matrices such that the minimum number of scalar multiplications in the 
matrix chain multiplication is a multiple of the dimension (number of rows or the
number of columns ) of the matrices involved in the chain. Write a c++ code for the same
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int dp[101][101];

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
    int n = 5; // number of matrices
    int p[n+1] = {100, 100, 100, 100, 100}; // dimensions of matrices
    memset(dp, -1, sizeof(dp));
    int optimal_cost = matrix_chain_order(p, 1, n);
    if (optimal_cost % p[1] == 0 || optimal_cost % p[n] == 0) {
        cout << "Two full parenthesizations with the same number of scalar multiplications: " << endl;
        // output two full parenthesizations here
    } else {
        cout << "No two full parenthesizations with the same number of scalar multiplications exist." << endl;
    }
    return 0;
}
