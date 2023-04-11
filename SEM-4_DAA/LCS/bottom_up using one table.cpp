/*
Modify the bottom-up dynamic programming algorithm to compute the
longest common subsequence of the two sequences X and Y such that the
modified algorithm uses only one table (i.e., the c-table ) and out put the
maximum-length common subsequence along with the subsequence
write c++ code
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;

    int m = X.length(), n = Y.length();
    int c[m+1][n+1];

    // Initialize c-table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    // Find the longest common subsequence
    int len = c[m][n];
    string lcs(len, ' ');
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[--len] = X[i-1];
            i--;
            j--;
        } else if (c[i-1][j] > c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    // Output the maximum-length common subsequence
    cout << "Length of longest common subsequence: " << c[m][n] << endl;
    cout << "Longest common subsequence: " << lcs << endl;

    return 0;
}
