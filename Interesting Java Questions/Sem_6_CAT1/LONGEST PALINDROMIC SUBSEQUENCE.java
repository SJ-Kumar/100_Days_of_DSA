// TC-O(n^2)
// SC-O(n^2)

class Main {
    public static int findLongestPalindrome(String X, int i, int j) {
        if (i > j) {
            return 0;
        }

        if (i == j) {
            return 1;
        }

        if (X.charAt(i) == X.charAt(j)) {
            return findLongestPalindrome(X, i + 1, j - 1) + 2;
        }

        return Integer.max(findLongestPalindrome(X, i, j - 1),
                findLongestPalindrome(X, i + 1, j));
    }

    public static void main(String[] args) {
        String X = "ABBDCACB";
        int n = X.length();

        System.out.print(findLongestPalindrome(X, 0, n - 1));
    }
}
