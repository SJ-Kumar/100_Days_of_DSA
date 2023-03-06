/* Given an array of integers representing the dimensions of a series of matrices, 
write a program to find the minimum number of scalar multiplications required to multiply these matrices together in a given order.
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
