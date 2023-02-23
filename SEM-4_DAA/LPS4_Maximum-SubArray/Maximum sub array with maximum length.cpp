/*Given an array of positive and negative numbers, develop a linear algorithm and write a C++ code to print the start index, end index and sum of subarray which is having maximum sum and maximum length. Consider an array with 13 elements 4, -12, 3, 10, 4, 5, -100, 6, 7, 1, 3, 1, 4. There are two subarrays having sum as 22, that is starting at 2 and ending at 5 with elements 3, 10, 4, 5 and another subarray that starts at 8 and end at 13 with elements 6, 7, 1, 3, 1, 4

Input Format

First line contains the number of elements in array, n

Next line contains the elements in the array separated by a space

Output Format

Print the start index, end index and sum of array having maximum sum and having maximum number of elements
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int n, max_sum = 0, max_length = 0, start_idx = 0, end_idx = 0, sum = 0, length = 0, curr_start = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (sum + arr[i] > 0) {
      sum += arr[i];
      length++;
    } else {
      sum = 0;
      length = 0;
      curr_start = i + 1;
    }
    if (sum > max_sum || (sum == max_sum && length > max_length)) {
      max_sum = sum;
      max_length = length;
      start_idx = curr_start;
      end_idx = i;
    }
  }
  cout << start_idx + 1 << " " << end_idx + 1 << " " << max_sum << endl;
  return 0;
}
