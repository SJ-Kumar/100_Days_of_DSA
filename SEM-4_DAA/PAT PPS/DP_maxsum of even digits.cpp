/* Dynamic programming algorithm to solve the problem of finding the maximum sum of even digits in a number */

#include <iostream>
#include <cstring>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        int sum = digitSum(i);
        if (sum % 2 == 0) dp[i] = sum;
        else dp[i] = sum + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
