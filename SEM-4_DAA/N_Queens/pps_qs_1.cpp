/*
Question

A positive integer n can be partitioned into a sequence of distinct positive integers a1, a2, ..., an such that n = a1+a2+...+ak. 
We call a1+a2+...+ak as k−size distinct partition of n. Here, none of the positive integers ai ,i =1, 2..., n are same. 
Distinct partitions of 3 are 2+1 and 3. We consider the partition 2 + 1 and the partition 1 + 2, as the same partition. 
Maximum size distinct partition of 3 is 2 + 1. Similarly, distinct partitions of 6 are 1 + 5, 2 + 4, 3 + 2 + 1, 6. 
Maximum-size distinct partition of 6 is 3 + 2 + 1. Given a positive integer n, design a back-tracking c++ code to compute a maximum-size distinct partition of n. 


Algorithm

1. Import the necessary libraries: iostream and vector.
2. Define a function called "partition" which takes four arguments: "n", "k", "currentPartition", and "result". 
3. If "n" is equal to 0, push the "currentPartition" vector into the "result" vector and return.
4. Iterate through all possible partition sizes starting from "k" up to "n".
5. Append the current partition size to the "currentPartition" vector.
6. Recursively call the "partition" function with updated "n" and "k" values and the "currentPartition" and "result" vectors.
7. Remove the last element from the "currentPartition" vector using "pop_back()".
8. Define a function called "maxPartition" which takes one argument: "n".
9. Create a vector of vectors called "partitions" to store all possible partitions and a vector called "currentPartition" to store the current partition.
10. Call the "partition" function with "n", "1", "currentPartition", and "partitions" as arguments.
11. Initialize a variable called "maxSize" to 0 and a vector called "maxPartition" to store the partition with the maximum number of elements.
12. Iterate through each partition in the "partitions" vector.
13. If the size of the current partition is greater than "maxSize", set "maxSize" to the size of the current partition and set "maxPartition" to the current partition.
14. Return "maxPartition".
15. In the "main" function, prompt the user to enter a positive integer "n".
16. Call the "maxPartition" function with "n" as an argument to compute the maximum-size distinct partition of "n".
17. Output the partition to the console.
18. End the program.

*/

#include <iostream>
#include <vector>

using namespace std;

void partition(int n, int k, vector<int>& currentPartition, vector<vector<int>>& result) {
    if (n == 0) {
        result.push_back(currentPartition);
        return;
    }
    for (int i = k; i <= n; i++) {
        currentPartition.push_back(i);
        partition(n - i, i + 1, currentPartition, result);
        currentPartition.pop_back();
    }
}

vector<int> maxPartition(int n) {
    vector<vector<int>> partitions;
    vector<int> currentPartition;
    partition(n, 1, currentPartition, partitions);
    int maxSize = 0;
    vector<int> maxPartition;
    for (vector<int>& partition : partitions) {
        if (partition.size() > maxSize) {
            maxSize = partition.size();
            maxPartition = partition;
        }
    }
    return maxPartition;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    vector<int> maxPartition = maxPartition(n);
    cout << "Maximum-size distinct partition of " << n << " is: ";
    for (int i : maxPartition) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
