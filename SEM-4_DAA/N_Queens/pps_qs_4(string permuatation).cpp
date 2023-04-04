/*
Question

Consider the ‘String Permutation Problem’ where the input is a string of symbols S and the output is all the permutations of the symbols of the string S, 
in an alphabetical order. If S is abc, then the c++ code should output abc, acb, bac, bca, cab, cba. 
Design a back-tracking c++ code for the String Permutation Problem

Algorithm

Start by including the necessary libraries and defining the permute function which takes in a string s, a left index l, and a right index r.
If l is equal to r, then the permutation is complete and we print out the string s.
Otherwise, for each index i from l to r inclusive, we swap the characters at index l and i, sort the substring s[l+1:r+1], and recursively call permute with l incremented by 1.
After the recursive call, we swap the characters back to their original positions to continue with the next iteration of the loop.
In the main function, take input for the string s and sort it in alphabetical order.
Call permute with l set to 0 and r set to the length of the string minus 1.

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permute(string& s, int l, int r) {
    if (l == r) {
        cout << s << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            sort(s.begin() + l + 1, s.end());
            permute(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    sort(s.begin(), s.end());
    permute(s, 0, s.length() - 1);
    return 0;
}
