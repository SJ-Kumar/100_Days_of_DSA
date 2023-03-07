/* Given an array of integers representing the dimensions of a series of matrices, 
write a program to find the minimum number of scalar multiplications required to multiply these matrices together in a given order.

Algorithm 

1. Initialize an n x n 2D array m where n is the number of matrices in the chain.
2. Set the diagonal elements of m to 0 since a single matrix doesn't require any multiplication.
3. For every chain length L from 2 to n, and for every possible starting index i up to n-L+1, find the optimal cost of multiplying the matrices starting at i and ending at i+L-1.
4. To do this, loop through all possible split points k between i and i+L-2, and calculate the cost of multiplying the matrices from i to k, and from k+1 to i+L-1, and then adding the cost of multiplying the resulting matrices together.
5. Keep track of the minimum cost encountered for each starting index i and chain length L, and store it in m[i][i+L-1].
6. Return the minimum cost of multiplying the entire chain of matrices, which is stored in m[1][n-1].
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h> 
#include <limits.h>
#include <vector>
using namespace std; 
  
int MatrixChainOrder(int p[], int n) 
{ 
  
    int m[n][n]; 
  
    for (int i = 1; i < n; i++) 
        m[i][i] = 0; 

    for (int L = 2; L < n; L++) { 
        for (int i = 1; i < n - L + 1; i++) { 
            int j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++) { 
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
} 

int main() 
{ 
    int n, k;
    cin >> n >> k;
    int p[n+1];
    p[0] = k;
    for(int i=1; i<=n; i++){
        p[i] = k;
    }
    cout << MatrixChainOrder(p, n+1); 
    return 0; 
}
