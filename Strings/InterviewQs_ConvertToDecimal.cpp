/*
Here is about to introduce a new kind of number system. Where instead of 10 digits there is 20, from a to t, all in small. 
Now a means 1, b means 2 and t means 20, thenn aa means 21. Now for  a new number you have to print the decimal form it.
Note that the letters in the input string will be lower case and from a to t. 

Input Format:
Single line containing the string of new number system’s number

Output Format:
Single line denoting the integer with the same decimal value as the input string

Sample input 1: e

Sample Output: 5

Sample  Input 2: ac

Sample Output: 23

*/

#include <iostream>
#include <cmath>
using namespace std;

int convertToDecimal(string num) {
    int decimal = 0;
    int n = num.size();

    for (int i = 0; i < n; i++) {
        decimal += (num[i] - 'a' + 1) * pow(20, n - i - 1);
    }

    return decimal;
}

int main() {
    string num;
    cin >> num;

    cout << convertToDecimal(num) << endl;

    return 0;
}
