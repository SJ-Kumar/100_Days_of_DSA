/*
Two sequences X and Y are said to be k-similar if k-number of changes
are needed in X to make X, same as that of Y . For eg, If X=ATTGC,
Y=AGGGC, then X and Y are 2-similar since there are two chnages are
required to make x as Y. Given two equal-length sequences X and Y of
symbols from A, T, G, C and a number k, design a dynamic programming c++ code to check whether X and Y are 2-similar or not

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int levenshteinDistance(const string& word1, const string& word2, int k) {
    const int n = word1.length();
    const int m = word2.length();

    if (abs(n - m) > k) {
        return -1; // Strings cannot be k-similar
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
    }

    return dp[n][m] <= k ? dp[n][m] : -1;
}

int main() {
    string X, Y;
    int k;

    cin >> X >> Y >> k;

    int distance = levenshteinDistance(X, Y, k);

    if (distance == -1) {
        cout << "X and Y are not " << k << "-similar" << endl;
    }
    else {
        cout << "X and Y are " << distance << "-similar" << endl;
    }

    return 0;
}
