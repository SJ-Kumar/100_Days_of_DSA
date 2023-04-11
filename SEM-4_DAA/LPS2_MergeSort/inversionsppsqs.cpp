/*
Consider an array of A[1, 2, 3, ..., n] be an array of n distinct numbers. If i < j and A[i] > A[j], then we call the the pair (i, j) as
an inversion of A. For example, the five inversions in the array
A :< 2, 3, 8, 6, 1 > are (1, 5), (2, 5), (3, 4), (3, 5), (4, 5). Given an
array of numbers, design the pseudocode and the corresponding
code that follows ‘Divide-Conquer-Combine’ strategy for computing the number of inversions in the array . write c++ code
*/

#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    long long count = 0;
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1); // increment the count of inversions
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

    return count;
}

long long merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = (left + right) / 2;

    long long count = merge_sort(arr, left, mid);
    count += merge_sort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);

    return count;
}

int main() {
    // Test the implementation with some example inputs
    vector<int> arr = {2, 3, 8, 6, 1};

    long long inversions = merge_sort(arr, 0, arr.size() - 1);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
