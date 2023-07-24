import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class DistinctPermutations {

    public static void main(String[] args) {
        String input = "aab";
        printDistinctSortedPermutations(input);
    }

    public static void printDistinctSortedPermutations(String input) {
        char[] charArray = input.toCharArray();
        Arrays.sort(charArray); // Sort the characters to generate permutations in sorted order
        Set<String> permutations = new HashSet<>();
        generatePermutations(charArray, 0, permutations);
        for (String permutation : permutations) {
            System.out.println(permutation);
        }
    }

    private static void generatePermutations(char[] charArray, int currentIndex, Set<String> permutations) {
        if (currentIndex == charArray.length - 1) {
            permutations.add(new String(charArray));
        } else {
            for (int i = currentIndex; i < charArray.length; i++) {
                swap(charArray, currentIndex, i);
                generatePermutations(charArray, currentIndex + 1, permutations);
                swap(charArray, currentIndex, i); // Backtrack
            }
        }
    }

    private static void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
