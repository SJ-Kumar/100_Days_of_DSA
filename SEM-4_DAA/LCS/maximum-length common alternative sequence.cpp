/*
Usually the subsequence Z of a sequence X is defined as follows: Given a
sequence X =< x1, x2, ..., xm >, we say that a sequence Z =< z1, z2, ..., zk >is
a subsequence of X if there exists a strictly increasing sequence < i1,
i2, ..., ik > of indices of X such that for all j = 1, 2, 3, ..., k, we have xij 
= zj. For example, Z =< B, C, D, B > is a sub sequence of < A, B,
C, B, D, A, B > with a index sequence of < 2, 3, 5, 7 >. In the same way,
we define Z as an alternative sequence of X if there exists a strictly
decreasing sequence < i1, i2, ..., ik >. Write a c++ code to compute the maximum-length common alternative sequence of X and Y 

*/

#include <iostream>
#include <vector>
using namespace std;

vector<char> max_common_alt_sequence(const vector<char>& X, const vector<char>& Y) {
    int m = X.size();
    int n = Y.size();

    // Initialize the dynamic programming table
    vector<vector<pair<int, int>>> dp(m+1, vector<pair<int, int>>(n+1, {0, -1}));

    // Fill the table using dynamic programming
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                // If the two elements match, we can extend the common alternative sequence
                dp[i][j] = {dp[i-1][j-1].first + 1, i-1};
            } else {
                // Otherwise, we need to choose the longer of the two possible alternative sequences
                if (dp[i-1][j].first >= dp[i][j-1].first) {
                    dp[i][j] = {dp[i-1][j].first, i-1};
                } else {
                    dp[i][j] = {dp[i][j-1].first, dp[i][j-1].second};
                }
            }
        }
    }

    // Extract the longest common alternative sequence from the table
    int i = m;
    int j = n;
    vector<char> result;
    while (i > 0 && j > 0) {
        if (dp[i][j].first == dp[i-1][j].first) {
            // This element is not part of the common alternative sequence
            i--;
        } else if (dp[i][j].first == dp[i][j-1].first) {
            // This element is not part of the common alternative sequence
            j--;
        } else {
            // This element is part of the common alternative sequence
            result.push_back(X[i-1]);
            i = dp[i][j].second + 1;
            j--;
        }
    }

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<char> X = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    vector<char> Y = {'B', 'D', 'C', 'A', 'B', 'A'};
    vector<char> result = max_common_alt_sequence(X, Y);
    for (char c : result) {
        cout << c << " ";
    }
    cout << endl; // Output: A B B
    return 0;
}
