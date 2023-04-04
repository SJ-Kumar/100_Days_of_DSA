/*
Question

Given a non-empty set S of non-negative integers and a positive integer k, 
problem is to find a subset S′ of S such that sum of the integers of S′ is equal to k. Design a back-tracking c++ code to solve the above Problem.

Algorithm

Define a function subsetSum that takes a vector of non-negative integers S, a positive integer k, a vector currentSubset to store the current subset being processed, and an integer index representing the current index of the subset.

If k is 0, return true as the subset with the sum k has been found.

If the current index has reached the end of the set S, return false as no subset with the sum k has been found.

Add the element at the current index to the currentSubset vector.

Recursively call the subsetSum function with k reduced by the value of the current element and the index incremented by 1.

If the call to subsetSum returns true, it means a subset with the sum k has been found. Return true.

If the call to subsetSum returns false, remove the last element from the currentSubset vector and continue to the next element in the set by calling subsetSum with the same value of k and the index incremented by 1.

If the function reaches the end of the set and no subset with the sum k has been found, return false.

In the main function, prompt the user to input the size of the set, the set itself, and the target sum.

Call the subsetSum function with the set S, the target sum k, an empty currentSubset vector, and the index 0.

If subsetSum returns true, print the elements of the currentSubset vector that add up to the sum k.

If subsetSum returns false, print a message indicating that there is no subset with the sum k.

*/

#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int>& S, int k, vector<int>& currentSubset, int index) {
    if (k == 0) {
        return true;
    }
    if (index == S.size()) {
        return false;
    }
    currentSubset.push_back(S[index]);
    bool include = subsetSum(S, k - S[index], currentSubset, index + 1);
    if (include) {
        return true;
    }
    currentSubset.pop_back();
    return subsetSum(S, k, currentSubset, index + 1);
}

int main() {
    int n, k;
    cout << "Enter the size of the set: ";
    cin >> n;
    cout << "Enter the set: ";
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    cout << "Enter the target sum: ";
    cin >> k;
    vector<int> currentSubset;
    if (subsetSum(S, k, currentSubset, 0)) {
        cout << "A subset with sum " << k << " is found: ";
        for (int x : currentSubset) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "There is no subset with sum " << k << endl;
    }
    return 0;
}
