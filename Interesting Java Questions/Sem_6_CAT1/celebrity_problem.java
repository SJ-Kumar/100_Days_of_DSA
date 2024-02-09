import java.util.*;

public class Main {
    public static class Solution {
        int findCelebrity(int M[][], int N) {
            int candidate = 0;
            for (int i = 1; i < N; i++) {
                if (M[candidate][i] == 1) {
                    candidate = i;
                }
            }
            for (int i = 0; i < N; i++) {
                if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
                    return -1;
                }
            }
            return candidate;
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        int[][] relation = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                relation[i][j] = s.nextInt();
            }
        }
        int celebrityId = new Solution().findCelebrity(relation, N);
        if (celebrityId != -1) {
            System.out.println("Celebrity id is: " + celebrityId);
        } else {
            System.out.println("Celebrity not found");
        }
    }
}
