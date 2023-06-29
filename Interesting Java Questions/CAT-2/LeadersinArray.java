import java.util.*;

class Main {
    public static ArrayList<Integer> leaders(int[] arr, int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            boolean leader = true;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    leader = false;
                    break;
                }
            }
            if (leader)
                ans.add(arr[i]);
        }
        return ans;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }
        ArrayList<Integer> ans = leaders(arr, n);
        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i) + " ");
        }
    }
}

//TC - O(n^2)
//SC - O(n)
