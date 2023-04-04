/*
Question

Let y^i denote the concatenation of a string y with itself i times. For example (ab)^3 is ababab. 
A string x ∈ Σ∗ is said to have a repetitive factor r if x = y^r , for some string y ∈ Σ∗, r > 0. 
Let ρ(x) denote the largest r such that x has a repetition factor r. Given P[1, 2, ..., m], design
an efficient c++ code to compute the ρ(Pi), i = 1, 2, ...m. Here, Pi is the i − th symbol in P.

Algorithm

Define a function compute_failure that takes a string pattern as input and returns the failure table of the pattern, computed using the KMP algorithm.

Initialize a vector fail of size n (the length of pattern) with all values set to -1.
Initialize a variable j to -1.
Loop through each index i in the pattern, starting from index 1.
While j is greater than or equal to 0 and the character at index j+1 in pattern does not match the character at index i, update j to be the value at index j in fail.
If the character at index j+1 in pattern matches the character at index i, increment j.
Set the value at index i in fail to j.
Return the fail vector.
Define a function largest_repetitive_factor that takes a string s as input and returns the largest repetitive factor of s.

Compute the failure table fail for s using the compute_failure function.
Loop through each index i in s, starting from index n-1 and going down to 1.
If the value at index i in fail is not -1 and n (the length of s) is divisible by n-i-fail[i], return n divided by n-i-fail[i].
If no repetitive factor is found, return 1.
In the main function:

Read a string P from standard input.
Compute the length m of P.
Loop through each index i in P, starting from 0.
Print the largest repetitive factor of the substring of P starting at index i and of length 1, using the largest_repetitive_factor function.
Print a newline character.

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_failure(string pattern) {
    int n = pattern.size();
    vector<int> fail(n, -1);
    int j = -1;
    for (int i = 1; i < n; i++) {
        while (j >= 0 && pattern[j+1] != pattern[i]) {
            j = fail[j];
        }
        if (pattern[j+1] == pattern[i]) {
            j++;
        }
        fail[i] = j;
    }
    return fail;
}

int largest_repetitive_factor(string s) {
    int n = s.size();
    vector<int> fail = compute_failure(s);
    for (int i = n-1; i >= 1; i--) {
        if (fail[i] != -1 && n % (n-i-fail[i]) == 0) {
            return n / (n-i-fail[i]);
        }
    }
    return 1;
}

int main() {
    string P;
    cin >> P;
    int m = P.size();
    for (int i = 0; i < m; i++) {
        cout << largest_repetitive_factor(P.substr(i, 1)) << " ";
    }
    cout << endl;
    return 0;
}
