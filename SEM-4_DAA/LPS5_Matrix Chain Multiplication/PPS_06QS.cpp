/*
The dynamic programming c++ code for MCM returns an optimal solution along with the optimal value (that is, the code returns a 
full parenthesization along with the minumum number of scalar multiplications).
Modify the dynamic programming pseudocodecode of MCM in such a way that the modified code returns all the possible full parenthesizations
that involves minimum number of scalar multiplications in computing the product A1 ∗ A2∗, ... ∗ An.
*/



#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // initialize to maximum integer value

int dp[101][101]; // memoization table for storing optimal solutions

vector<string> all_parenthesizations(int p[], int i, int j) {
    vector<string> result;
    if (i == j) {
        result.push_back(to_string(i));
        return result;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    vector<string> min_parenthesizations;
    int min_cost = INF;
    for (int k = i; k < j; k++) {
        vector<string> left = all_parenthesizations(p, i, k);
        vector<string> right = all_parenthesizations(p, k+1, j);
        int cost = p[i-1]*p[k]*p[j];
        if (cost + dp[i][k] + dp[k+1][j] < min_cost) {
            min_cost = cost + dp[i][k] + dp[k+1][j];
            min_parenthesizations.clear();
            for (string l : left) {
                for (string r : right) {
                    min_parenthesizations.push_back("(" + l + " " + r + ")");
                }
            }
        }
    }
    dp[i][j] = min_cost;
    return min_parenthesizations;
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
    vector<string> optimal_parenthesizations = all_parenthesizations(p, 1, n);
    cout << "All possible full parenthesizations with minimum cost:\n";
    for (string s : optimal_parenthesizations) {
        cout << s << endl;
    }
    return 0;
}
