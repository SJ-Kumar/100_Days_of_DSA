/*(QS)
consider an array of A[1, 2, 3, ..., n] be an array of n distinct numbers. If i < j and A[i] > A[j], then we call the the pair (i, j) as
an inversion of A. For example, the five inversions in the array
A :< 2, 3, 8, 6, 1 > are (1, 5), (2, 5), (3, 4), (3, 5), (4, 5). Given an
array of numbers, design the pseudocode and the corresponding
code that follows ‘Divide-Conquer-Combine’ strategy for computing the number of inversions in the array and analyse the
same.

(CODE)
*/

#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    int count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            count += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return count;
}

int countInversions(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = (left + right) / 2;

    int leftInversions = countInversions(arr, left, mid);
    int rightInversions = countInversions(arr, mid + 1, right);
    int crossInversions = mergeAndCount(arr, left, mid, right);

    return leftInversions + rightInversions + crossInversions;
}

int main() {
    vector<int> arr = {2, 3, 8, 6, 1};
    int n =arr.size();
  int inversions = countInversions(arr, 0, n - 1);
  cout << "The array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "The number of inversions: " << inversions << endl;
  return 0;
}
