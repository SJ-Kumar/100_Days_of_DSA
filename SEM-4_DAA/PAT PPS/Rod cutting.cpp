/* Find the maximum revenue that can be earned by selling a product with a given product number, n, 
and the number of times it can be split into smaller products, k. */

#include <iostream>
#include <cstring>

using namespace std;

int calculatePrice(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    if (sum % 2 == 0) {
        return sum;
    } else {
        return sum + 1;
    }
}

int maxRevenue(int n, int k) {
    if (k == 1) {
        return calculatePrice(n);
    }

    int maxRev = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        int rev = calculatePrice(i) + maxRevenue(n - i, k - 1);
        if (rev > maxRev) {
            maxRev = rev;
        }
    }

    return maxRev;
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int revenue = maxRevenue(n, k);
    cout << revenue << endl;
    return 0;
}
