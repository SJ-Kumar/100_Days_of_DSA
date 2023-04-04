/*
Question

Consider the pattern P and the text T. Given the ‘Prefix-function Table‘
of the string P T (π table for the string PT ), design an c++ code to
compute the valid shifts of P in T

Algorithm

Compute the prefix-function table pi for the string P+T.
Set q to 0.
For each character T[i] in the text T, do the following:
a. While q > 0 and P[q] != T[i], set q = pi[q-1].
b. If P[q] == T[i], increment q by 1.
c. If q == length of P, then a valid shift is found:
i. Set s = i - length of P + 1.
ii. Output the valid shift s.
iii. Set q = pi[q-1].
Repeat step 3 until all characters in T are processed.
Exit.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> compute_prefix_function(string P) {
    int m = P.length();
    vector<int> pi(m, 0);
    int k = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && P[k] != P[q]) {
            k = pi[k-1];
        }
        if (P[k] == P[q]) {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

void find_valid_shifts(string T, string P, vector<int> pi) {
    int n = T.length();
    int m = P.length();
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q-1];
        }
        if (P[q] == T[i]) {
            q++;
        }
        if (q == m) {
            int s = i - m + 1;
            cout << "Valid shift: " << s << endl;
            q = pi[q-1];
        }
    }
}

int main() {
    string T, P;
    cout << "Enter the text: ";
    getline(cin, T);
    cout << "Enter the pattern: ";
    getline(cin, P);
    vector<int> pi = compute_prefix_function(P + T);
    find_valid_shifts(T, P, pi);
    return 0;
}
