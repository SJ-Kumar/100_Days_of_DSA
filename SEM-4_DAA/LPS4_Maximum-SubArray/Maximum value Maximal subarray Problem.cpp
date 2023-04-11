#include <iostream>
#include <vector>

using namespace std;

pair<int, int> max_value_maximal_subarray(vector<int>& arr) {
    int n = arr.size();
    int max_sum = 0;
    int current_sum = 0;
    int start = 0;
    int end = 0;
    int current_start = 0;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = current_start;
            end = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            current_start = i + 1;
        }
    }

    return make_pair(start, end);
}

int main() {
    // Test the implementation with some example inputs
    vector<int> arr = {1, 2, 3, 4, 5};

    pair<int, int> max_subarray = max_value_maximal_subarray(arr);

    cout << "Maximum value maximal subarray: [" << max_subarray.first << ", " << max_subarray.second << "]" << endl;

    return 0;
}
