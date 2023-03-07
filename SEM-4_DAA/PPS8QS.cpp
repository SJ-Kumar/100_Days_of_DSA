/*
Design a c++ code to output any two full parenthesizations (say), X1,
X2 of < A1, A2, ..., An > such that the total number of scalar multiplications involved in X1 and X2 are same. If the given matrix-chain does not
have two parenthesisations with same number of scalar multiplications, your pseudocode should retrun 0.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; // initialize to maximum integer value

int matrix_chain_order(int p[], int n, vector<vector<int>>& dp, vector<vector<vector<int>>>& brackets) {
    // dp[i][j] stores the optimal cost of multiplying Ai...Aj
    // brackets[i][j] stores the optimal parenthesization for Ai...Aj

    for (int len = 1; len < n; len++) {
        for (int i = 1; i <= n-len; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    brackets[i][j].clear();
                    brackets[i][j].push_back({i, k, j});
                } else if (cost == dp[i][j]) {
                    brackets[i][j].push_back({i, k, j});
                }
            }
        }
    }

    if (dp[1][n] == INF) {
        return 0; // no valid parenthesizations
    }

    // search for two parenthesizations with the same cost
    for (int x = 0; x < brackets[1][n].size(); x++) {
        for (int y = x+1; y < brackets[1][n].size(); y++) {
            vector<vector<int>> paren1 = brackets[1][n][x];
            vector<vector<int>> paren2 = brackets[1][n][y];
            int cost1 = p[paren1[0][0]-1] * p[paren1[0][1]] * p[paren1[1][1]];
            int cost2 = p[paren2[0][0]-1] * p[paren2[0][1]] * p[paren2[1][1]];
            if (cost1 == cost2) {
                cout << "Parenthesization 1:\n";
                print_parenthesization(paren1);
                cout << "Parenthesization 2:\n";
                print_parenthesization(paren2);
                return 1;
            }
        }
    }

    return 0; // no two parenthesizations with same cost
}

void print_parenthesization(vector<vector<int>>& brackets) {
    if (brackets.size() == 1) {
        cout << "A" << brackets[0][0];
    } else {
        cout << "(";
        print_parenthesization({brackets[0]});
        print_parenthesization({brackets[1]});
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int p[n+1];
    cout << "Enter the dimensions of the matrices:\n";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
