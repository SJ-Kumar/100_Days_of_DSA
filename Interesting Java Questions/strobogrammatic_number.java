/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (upside down). 
In other words, a strobogrammatic number is a number that appears the same when viewed upside down

Programming Qs
Given number n, check if it is a Strobogrammatic Number.

Sample IO
Input:  "69"
Output: 69 is a strobogrammatic number

Input:  "88"
Output: 88 is a strobogrammatic number

Input:  "962"
Output: 962 is not a strobogrammatic number

*/

import java.util.*;

public class SN {
    public static boolean isSN(String num) {
        Map<Character, Character> SD = new HashMap<>();
        SD.put('0', '0');
        SD.put('1', '1');
        SD.put('8', '8');
        SD.put('6', '9');
        SD.put('9', '6');

        int left = 0;
        int right = num.length() - 1;

        while (left <= right) {
            char leftChar = num.charAt(left);
            char rightChar = num.charAt(right);

            if (!SD.containsKey(leftChar) || SD.get(leftChar) != rightChar) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter a number: ");
        String num = s.nextLine();

        if (isSN(num)) {
            System.out.println(num + " is a strobogrammatic number");
        } else {
            System.out.println(num + " is not a strobogrammatic number");
        }
    }
}
