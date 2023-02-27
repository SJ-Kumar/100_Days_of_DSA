/*
Develop an algorithm and implement it to solve maximum sum subarray problem in linear time to 
print the starting index, end index and sum of the subarray whose sum is maximum. 
Compare the performance of this algorithm with naive algorithm and divide and conquer algorithm 
for size of inputs 100, 1000, 10000, 50000, 100000, 500000, 1000000. For example, consider an array with 16 elements, 
13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7. Maximum subarray starts at index 8 and ends at index 11 (human indices) and sum is 43

Input Format

First line contains the number of elements, n

Next line contains 'n' elements separated by a space

Output Format

Print the start index, end index and sum of subarray that has got maximum sum

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int n, max_sum = 0, start_idx = 0, end_idx = 0, sum = 0, curr_start = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (sum + arr[i] > 0) {
      sum += arr[i];
    } else {
      sum = 0;
      curr_start = i + 1;
    }
    if (sum > max_sum) {
      max_sum = sum;
      start_idx = curr_start;
      end_idx = i;
    }
  }
  cout << start_idx + 1 << " " << end_idx + 1 << " " << max_sum << endl;
  return 0;
}
