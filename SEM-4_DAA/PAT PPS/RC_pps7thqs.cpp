#include <iostream>
#include <vector>

using namespace std;

// Function to compute the maximum revenue for a given rod length
// and price array
int rodCutting(int n, vector<int> prices) {
    vector<int> revenue(n+1, 0);  // initialize revenue array to 0
    vector<int> lengths(n+1, 0);  // initialize lengths array to 0

    // Compute the maximum revenue for each possible length of the rod
    for (int i = 1; i <= n; i++) {
        int maxRevenue = -1;
        for (int j = 1; j <= i; j++) {
            if (prices[j-1] + revenue[i-j] > maxRevenue) {
                maxRevenue = prices[j-1] + revenue[i-j];
                lengths[i] = j;
            }
        }
        revenue[i] = maxRevenue;
    }

    // Print the lengths of the smaller pieces
    cout << "Lengths: ";
    while (n > 0) {
        cout << lengths[n] << " ";
        n -= lengths[n];
    }
    cout << endl;

    // Return the maximum revenue
    return revenue[prices.size()];
}

int main() {
    int n = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int maxRevenue = rodCutting(n, prices);
    cout << "Maximum revenue: " << maxRevenue << endl;

    return 0;
}
