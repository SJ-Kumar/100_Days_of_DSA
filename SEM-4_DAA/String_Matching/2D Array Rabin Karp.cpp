/*
Algorithm
Define a constant MAX_SIZE to represent the maximum size of the input array T.
Define a function valueOf() to convert a character to an integer.
Define a function check_characters() to check if a pattern P matches a substring of T starting from a specific row and column.
Define the main function rabin_karp_matcher() that takes T, P, d and q as input parameters.
Calculate the value of h using the formula (d^(m-1)) % q, where m is the length of P.
Initialize p and t0 to 0.
Calculate the values of p and t0 using the formulas (dp + valueOf(P[i])) % q and (dt0 + valueOf(T[0][i])) % q, respectively, for i from 0 to m-1.
For each row in T, do the following:
a. For each s from -1 to m-1, do the following:
i. If p is equal to t0, call the check_characters() function to check if P matches the substring of T starting from the current row and column s+1. If there is a match, print the index of the occurrence.
ii. Update the value of t0 using the formula (d*(t0-valueOf(T[row][s+1])*h) + valueOf(T[row][s+m+1])) % q.
Exit the function.

*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int MAX_SIZE = 1000;

int valueOf(char ch) {
    return (ch-'0');
}

bool check_characters(char T[MAX_SIZE][MAX_SIZE], string P, int row, int col) {
    int m = P.length();
    for (int i = 0; i < m; i++) {
        if (P[i] != T[row][col+i]) {
            return false;
        }
    }
    return true;
}

void rabin_karp_matcher(char T[MAX_SIZE][MAX_SIZE], string P, int d, int q) {
    int n, m, h, p, t0, s;
    n = m = MAX_SIZE; // set n and m to the maximum size of the array
    h = (int)pow(d, m-1) % q;
    cout << "h value is " << h << endl;
    p = 0;
    t0 = 0;
    for (int i = 0; i < m; i++) {
        p = (d*p + valueOf(P[i])) % q;
        t0 = (d*t0 + valueOf(T[0][i])) % q;
    }
    for (int row = 0; row < n; row++) {
        for (s = -1; s < m-1; s++) {
            if (p == t0) {
                if (check_characters(T, P, row, s+1)) {
                    cout << "Pattern occurs at index (" << row+1 << ", " << s+1 << ")" << endl;
                }
            }
            if (s < n-m) {
                t0 = (d*(t0-valueOf(T[row][s+1])*h) + valueOf(T[row][s+m+1])) % q;
                if (t0 < 0) {
                    t0 += q;
                }
            }
        }
    }
}

int main() {
    char T[MAX_SIZE][MAX_SIZE], c;
    string P;
    int d, q;

    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    cout << "Enter the array elements (in row-major order): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            T[i][j] = c;
        }
    }

    cout << "Enter the pattern: ";
    cin >> P;

    cout << "Enter base and prime number: ";
    cin >> d >> q;

    rabin_karp_matcher(T, P, d, q);

    return 0;
}
