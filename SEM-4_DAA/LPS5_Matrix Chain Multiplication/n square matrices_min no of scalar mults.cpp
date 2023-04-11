/*
Identify a matrix-chain of n square matrices
such that the minimum number of scalar multiplications in the matrix chain multiplication is a multiple of the dimension (number of rows or the
number of columns ) of the matrices involved in the chain. write c++ code

*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to calculate the minimum number of scalar multiplications
// required to multiply a chain of n matrices.
// Returns a matrix of size n x n where entry (i, j) gives the minimum
// number of scalar multiplications required to multiply the matrix chain
// from matrix i to matrix j.
vector<vector<int>> matrix_chain_multiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];

                // Check if the cost is a multiple of the number of rows or columns of the matrices involved
                if (cost % dimensions[i] == 0 || cost % dimensions[j + 1] == 0) {
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
    }

    return dp;
}

int main() {
    // Test the implementation with an example input
    vector<int> dimensions = {10, 20, 30, 40, 50};

    vector<vector<int>> dp = matrix_chain_multiplication(dimensions);

    cout << "Minimum number of scalar multiplications: " << dp[0][dimensions.size() - 2] << endl;

    return 0;
}
