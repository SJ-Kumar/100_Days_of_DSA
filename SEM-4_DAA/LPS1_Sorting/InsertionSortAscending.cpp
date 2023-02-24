#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int n;cin>>n;
    vector<int> arr;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        arr.push_back(element);
    }
    insertionSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}
