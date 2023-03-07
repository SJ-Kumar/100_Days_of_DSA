#include <iostream>
#include <vector>
using namespace std;

int maxRevenue(int n, vector<int>& prices) {
    vector<int> dp(n+1, 0); // initialize dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + prices[i-j]);
        }
        dp[i] = max(dp[i], prices[i]); // no cut
    }
    return dp[n];
}

int maxRevenueK(int n, vector<int>& prices, int k) {
    vector<int> dp(n+1, 0); // initialize dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
        dp[i] = max(dp[i], prices[i]); // no cut
    }
    int max_rev = 0;
    for (int j = 1; j < n; j++) {
        max_rev = max(max_rev, dp[j] + dp[n-j]);
    }
    return max_rev;
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> prices(n+1);
    cout << "Enter the prices for each length (1 to " << n << "): ";
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    for (int k = 1; k <= n; k++) {
        cout << "Max revenue for k=" << k << " is " << maxRevenueK(n, prices, k) << endl;
    }
    return 0;
}
