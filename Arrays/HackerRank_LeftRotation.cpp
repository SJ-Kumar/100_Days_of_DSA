#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    vector<int> rotated(n);
    for (int i = 0; i < n; i++) {
        rotated[(i + n - d) % n] = arr[i];
    }
    return rotated;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> rotated_arr = rotateLeft(d, arr);
    for (int i = 0; i < n; i++) {
        cout << rotated_arr[i] << " ";
    }
    cout << endl;
    return 0;
}
