/*
The recursive function forsolving LCS is based on the fact: first we check
whether the last symbols in X and Y are same or not and accordingly
construct the subproblems to proceed further. we call this algorithm as
‘last-position-check recursive ’ algorithm Instead of checking whether the
last symbol of X and Y are same or not. develop a recursive function
by checking whether the first symbols of X and Y are same or not and x
and construct the subproblems to proceed further. Based on the recursive
function developed by you, design a recursive c++ code for LCS. We call
this algorithm as ‘ first-position-checkrecursive ’ c++ code 

*/

#include <iostream>
#include <string>
using namespace std;

int lcs(string X, string Y, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    } else if (X[0] == Y[0]) {
        return 1 + lcs(X.substr(1), Y.substr(1), m-1, n-1);
    } else {
        return max(lcs(X.substr(1), Y, m-1, n), lcs(X, Y.substr(1), m, n-1));
    }
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int m = X.length();
    int n = Y.length();
    cout << "Length of LCS is " << lcs(X, Y, m, n);
    return 0;
}
