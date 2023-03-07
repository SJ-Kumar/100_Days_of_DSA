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
    if (k == 1) { //If we only need to partition into one part, the revenue is simply the sum of the digits of n
        return calculatePrice(n);
    }

    int maxRev = 0; //Initialize the maximum revenue to 0
    for (int i = 1; i <= n - k + 1; i++) { //Iterate over all possible partition sizes
        int rev = calculatePrice(i) + maxRevenue(n - i, k - 1); //Calculate the revenue for the current partition size and recurse for the remaining parts
        if (rev > maxRev) { //If the revenue is greater than the current maximum revenue, update the maximum revenue
            maxRev = rev;
        }
    }
    return maxRev; //Return the maximum revenue

}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int revenue = maxRevenue(n, k);
    cout << revenue << endl;
    return 0;
}
