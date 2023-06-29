import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        System.out.print("Enter the size of the array: ");
        int n = s.nextInt();
        
        int[] arr = new int[n];
        
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }
        
        int prefix = 1;
        int suffix = 1;
        int ans = 1;
        
        for (int i = 0; i < n; i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
            
            prefix = prefix * arr[i];
            suffix = suffix * arr[n - i - 1];
            ans = Math.max(ans, Math.max(prefix, suffix));
        }
        
        System.out.println("Maximum product subarray: " + ans);
    }
}


//TC-O(n)
//SC = O(1)
