// TC - O(n^2)
// SC - O(1)

import java.util.Scanner;

public class Main {

    static boolean checkCount(int[] arr, int n, int k) {
        int count;
        // Start traversing the elements
        for (int i = 0; i < n; i++) {
            // Count occurrences of current element
            count = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i])
                    count++;
                // If count of any element is greater than 2*k then return false
                if (count > 2 * k)
                    return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();
        
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();
        
        scanner.close();
        
        System.out.println("Result: " + checkCount(arr, n, k));
    }
}
