/*
Question

Let the pattern contains the occurence of empty space character, denoted for the purpose of understanding as ⋄. The pattern may look like ab⋄ba⋄c,
which is just ab ba c, in turn just abbac. Design an c++ code to compute the valid shifts of P . 

Algorithm

Initialize an empty vector to hold the valid shifts.
Determine the position of the empty space character in P. If P does not contain an empty space character, return the empty vector.
Iterate over the characters of P to the right of the empty space character.
For each character that is not an empty space character, compute the distance between its position and the position of the empty space character.
Add this distance to the vector of valid shifts.
Return the vector of valid shifts.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeValidShifts(string P) {
    vector<int> validShifts;
    int n = P.size();
    
    // Find the position of the empty space character
    int spacePos = -1;
    for (int i = 0; i < n; i++) {
        if (P[i] == '⋄') {
            spacePos = i;
            break;
        }
    }
    
    // Compute the valid shifts
    for (int i = spacePos + 1; i < n; i++) {
        if (P[i] != '⋄') {
            validShifts.push_back(i - spacePos);
        }
    }
    
    return validShifts;
}

int main() {
    // Example usage
    string P = "ab⋄ba⋄c";
    vector<int> validShifts = computeValidShifts(P);
    
    // Output the valid shifts
    cout << "Valid shifts: ";
    for (int i = 0; i < validShifts.size(); i++) {
        cout << validShifts[i] << " ";
    }
    cout << endl;
    
    return 0;
}
