import java.util.Scanner;

class Main {
    public static void rotateArray(int[] arr, int d) {
        int n = arr.length;
        d = d % n;
        if (d == 0) {
            return;
        }
        swap(arr, 0, d - 1);
        swap(arr, d, n - 1);
        swap(arr, 0, n - 1);
    }

    public static void swap(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int size = s.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < size; i++) {
            arr[i] = s.nextInt();
        }
        System.out.print("Enter the number of rotations: ");
        int rotations = s.nextInt();
        rotateArray(arr, rotations);
        System.out.println("Array after rotation: ");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}

//TC- O(n)
//SC- O(1)
