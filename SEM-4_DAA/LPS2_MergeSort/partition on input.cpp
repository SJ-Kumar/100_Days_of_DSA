/*
Merge-sort algorithm works by partitioning the input array A recursively into two halves. 
Here, the partition is based on the position in the array. Instead, design a new
c++ code where partioning is based on the values in the input array
*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    // Test the implementation with some example inputs
    vector<int> arr = {10, 5, 2, 7, 8, 3, 1, 6, 4, 9};

    merge_sort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
