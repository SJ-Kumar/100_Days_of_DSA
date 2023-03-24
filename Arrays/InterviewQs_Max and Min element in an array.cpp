#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {5, 2, 9, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Sort the array
    sort(arr, arr+n);

    // Print the minimum and maximum elements
    cout << "Minimum element = " << arr[0] << endl;
    cout << "Maximum element = " << arr[n-1] << endl;

    return 0;
}
