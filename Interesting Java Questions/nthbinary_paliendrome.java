/*Find the nth number whose binary representation is a palindrome

Sample IO

Input : 1
Output : 1
1st Number whose binary representation 
is palindrome is 1 (1)

Input : 9
Output : 27
9th Number whose binary representation
is palindrome is 27 (11011)
*/

import java.util.Scanner;

public class BinaryPalindromeChecker {
    public static boolean isBinaryPalindrome(int x) {
        int reversed = 0;
        int original = x;
        while (x > 0) {
            reversed <<= 1;          // Left shift by 1 bit
            reversed |= (x & 1);     // Add the least significant bit of 'x' to 'reversed'
            x >>= 1;                 // Right shift by 1 bit
        }
        return reversed == original;
    }

    public static int findNthPalindrome(int n) {
        int count = 0;
        int number = 1;

        while (count < n) {
            if (isBinaryPalindrome(number)) {
                count++;
            }
            number++;
        }

        return number - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of 'n': ");
        int n = sc.nextInt();

        int nthPalindrome = findNthPalindrome(n);
        String binaryString = Integer.toBinaryString(nthPalindrome);

        System.out.println("The " + n + "th number whose binary representation is a palindrome is: " + nthPalindrome + " (" + binaryString + ")");
    }
}

