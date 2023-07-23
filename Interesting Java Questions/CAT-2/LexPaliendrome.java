import java.util.Arrays;

public class LexicographicallyFirstPalindrome {

    public static String rearrangeToPalindrome(String input) {
        char[] chars = input.toCharArray();
        Arrays.sort(chars);

        int length = input.length();
        char[] result = new char[length];
        int left = 0;
        int right = length - 1;
        int oddCount = 0;
        char oddCharacter = '\0';

        for (char c : chars) {
            int frequency = countFrequency(chars, c);

            if (frequency % 2 == 0) {
                for (int i = 0; i < frequency / 2; i++) {
                    result[left++] = c;
                    result[right--] = c;
                }
            } else {
                oddCount++;
                oddCharacter = c;
            }
        }

        if (left <= right) {
            if (oddCount == 1) {
                result[length / 2] = oddCharacter;
            } else {
                return "Not possible to form a palindrome";
            }
        }

        return new String(result);
    }

    private static int countFrequency(char[] chars, char target) {
        int frequency = 0;
        for (char c : chars) {
            if (c == target) {
                frequency++;
            }
        }
        return frequency;
    }

    public static void main(String[] args) {
        String input = "aabbbccc";
        String palindrome = rearrangeToPalindrome(input);
        System.out.println("Lexicographically First Palindromic String: " + palindrome);
    }
}
