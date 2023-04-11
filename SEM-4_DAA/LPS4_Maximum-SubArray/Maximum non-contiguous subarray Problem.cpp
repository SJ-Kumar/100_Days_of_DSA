#include <iostream>
#include <vector>

using namespace std;

int max_non_contiguous_subarray(vector<int>& arr) {
    int n = arr.size();
    int incl = arr[0];
    int excl = 0;

    for (int i = 1; i < n; i++) {
        int temp = incl;
        incl = max(incl, excl + arr[i]);
        excl = temp;
    }

    return incl;
}

int main() {
    // Test the implementation with some example inputs
    vector<int> arr = {1, 2, 3, 4, 5};

    int max_sum = max_non_contiguous_subarray(arr);

    cout << "Maximum non-contiguous subarray sum: " << max_sum << endl;

    return 0;
}
