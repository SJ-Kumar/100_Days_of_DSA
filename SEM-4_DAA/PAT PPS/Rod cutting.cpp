/* Find the maximum revenue that can be earned by selling a product with a given product number, n, 
and the number of times it can be split into smaller products, k.


Algorithm for maxRevenue function:

Define a function named "calculatePrice" that takes an integer argument x and returns the sum of its digits, rounded up to the nearest even number.
If k equals 1, return the result of calling the "calculatePrice" function on n.
Initialize a variable named "maxRev" to 0.
Loop over all possible values of i from 1 to n-k+1:
a. Calculate the revenue of cutting the rope at position i as the sum of "calculatePrice(i)" and "maxRevenue(n-i, k-1)".
b. If the revenue is greater than "maxRev", update "maxRev" to the revenue.
Return "maxRev".
The main function reads in the values of n and k, calls the "maxRevenue" function with these values, and prints the resulting revenue.


*/

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
