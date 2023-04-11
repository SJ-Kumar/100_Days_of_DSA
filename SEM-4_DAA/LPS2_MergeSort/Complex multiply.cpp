/*
Design a Divide and conquer based C++ code to compute the product of two complex numbers aibi and c + id
*/

#include <iostream>
#include <complex>

using namespace std;

complex<double> complex_multiply(complex<double> a, complex<double> b) {
    // Base case: if either a or b is a real number, just return their product
    if (a.imag() == 0) {
        return a * b;
    }
    if (b.imag() == 0) {
        return b * a;
    }

    // Divide a and b into real and imaginary parts
    double a_real = a.real();
    double a_imag = a.imag();
    double b_real = b.real();
    double b_imag = b.imag();

    // Recursively compute the four partial products
    complex<double> ac = complex_multiply(complex<double>(a_real, 0), complex<double>(b_real, 0));
    complex<double> bd = complex_multiply(complex<double>(a_imag, 0), complex<double>(b_imag, 0));
    complex<double> ad = complex_multiply(complex<double>(a_real, 0), complex<double>(b_imag, 0));
    complex<double> bc = complex_multiply(complex<double>(a_imag, 0), complex<double>(b_real, 0));

    // Combine the four partial products to get the final product
    complex<double> result = ac - bd + complex<double>(0, 1) * (ad + bc);

    return result;
}

int main() {
    // Test the implementation with some example inputs
    complex<double> a(2, 3);
    complex<double> b(4, 5);
    complex<double> c(6, 7);
    complex<double> d(8, 9);

    complex<double> result = complex_multiply(a * b, c + d);
    cout << "Result: " << result << endl;

    return 0;
}
