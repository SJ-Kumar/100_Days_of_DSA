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
