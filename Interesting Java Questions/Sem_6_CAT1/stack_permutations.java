import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static boolean isStackPermutation(int[] original, int[] target) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        for (int element : original) {
            stack.push(element);
            while (!stack.isEmpty() && stack.peek() == target[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the length of the arrays:");
        int length = scanner.nextInt();
        
        int[] original = new int[length];
        int[] target = new int[length];
        
        System.out.println("Enter the elements of the original array:");
        for (int i = 0; i < length; i++) {
            original[i] = scanner.nextInt();
        }
        
        System.out.println("Enter the elements of the target array:");
        for (int i = 0; i < length; i++) {
            target[i] = scanner.nextInt();
        }
        
        boolean result = isStackPermutation(original, target);
        System.out.println("Is it a stack permutation? " + result);
        
        scanner.close();
    }
}
