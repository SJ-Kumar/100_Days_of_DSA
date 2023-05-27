/*The following Java program checks if an integer has a binary palindrome representation. 
It converts the entered integer to its binary format and determines if the binary representation is a palindrome.
*/

import java.util.*;

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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        // Convert integer to binary string
        String binaryString = Integer.toBinaryString(x);
        System.out.println("Binary format of " + x + ": " + binaryString);

        if (isBinaryPalindrome(x)) {
            System.out.println(binaryString + " has a binary palindrome representation.");
        } else {
            System.out.println(binaryString + " does not have a binary palindrome representation.");
        }
    }
}
