/*
Given a sequence of n numbers, X =< x1, x2, ..., xn >, write a pseudocode
and an appropriate algorithm to compute the longest monotnically increasing subsequence of X. Given X =< 10, 22, 9, 33, 21, 50, 41, 60, 80 >, the
longest monotonically increasing subsequence of X is 6 and the longest
subsequence is < 10,22,33, 50,60,80 >.write c++ code
*/

#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubsequence(vector<int>& X) {
    int n = X.size();
    vector<int> L(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (X[j] < X[i] && L[j] + 1 > L[i]) {
                L[i] = L[j] + 1;
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] > maxLen) {
            maxLen = L[i];
        }
    }

    return maxLen;
}

int main() {
    vector<int> X = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int longestLen = longestIncreasingSubsequence(X);
    cout << "Length of longest monotonically increasing subsequence: " << longestLen << endl;
    return 0;
}
