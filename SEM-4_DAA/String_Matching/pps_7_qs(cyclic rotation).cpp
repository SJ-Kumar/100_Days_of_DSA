/*
Question

Given two texts T, T′ , design a linear-time c++ code to determine whether the T is a cyclic rotation of T′ . 
For example, ‘car’ is the cyclic rotation of ‘arc’ since ‘car’ can be obtained by a cyclic rotation of the symbols in ‘arc’.

Algorithm

Check if the length of T and T_prime are the same. If they are not the same, T cannot be a cyclic rotation of T_prime, so return false.
Concatenate T with itself to form a new string TT.
Use the find function to search for the substring T_prime in TT.
If T_prime is found in TT, return true, indicating that T is a cyclic rotation of T_prime. Otherwise, return false.

*/

#include <iostream>
#include <string>

using namespace std;

bool is_cyclic_rotation(string T, string T_prime) {
    if (T.length() != T_prime.length()) {
        return false;
    }
    string TT = T + T;
    if (TT.find(T_prime) != string::npos) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string T, T_prime;
    cout << "Enter the first string: ";
    getline(cin, T);
    cout << "Enter the second string: ";
    getline(cin, T_prime);
    if (is_cyclic_rotation(T, T_prime)) {
        cout << T << " is a cyclic rotation of " << T_prime << endl;
    } else {
        cout << T << " is not a cyclic rotation of " << T_prime << endl;
    }
    return 0;
}
