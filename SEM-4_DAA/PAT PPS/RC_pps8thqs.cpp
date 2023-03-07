#include <bits/stdc++.h>
using namespace std;

int maxRevenue(int price[], int n, int rodLength) {
    int dp[rodLength + 1];
    memset(dp, -1, sizeof(dp)); // Initialize dp array to -1

    dp[0] = 0; // Base case

    for (int i = 1; i <= rodLength; i++) {
        int revenue = -1;
        for (int j = 1; j <= i; j++) {
            if (j == 3 || j == 5) {
                int leftover = i - j;
                if (leftover < 3) {
                    revenue = max(revenue, price[j-1] + (leftover >= 0 ? price[leftover-1] : -1));
                }
                else {
                    revenue = max(revenue, price[j-1] + dp[leftover]);
                }
            }
        }
        dp[i] = revenue;
    }
    return dp[rodLength];
}

int main() {
    int n;
    cout << "Enter the number of prices: ";
    cin >> n;

    int price[n];
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    int rodLength;
    cout << "Enter the length of the rod: ";
    cin >> rodLength;

    int maxRev = maxRevenue(price, n, rodLength);
    if (maxRev == -1) {
        cout << "Rod of given length cannot be cut into pieces of length 3 or 5.";
    }
    else {
        int wastage = rodLength - (maxRev % 3);
        if (wastage < 3) {
            maxRev += wastage - 1;
        }
        else {
            maxRev += wastage;
        }
        cout << "Maximum revenue: " << maxRev;
    }
    return 0;
}
