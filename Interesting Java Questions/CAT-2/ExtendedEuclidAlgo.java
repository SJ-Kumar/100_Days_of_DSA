import java.util.*;

class Main {
    public static int gcdextended(int a, int b, int x, int y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        int x1 = 1;
        int y1 = 1;
        int gcd = gcdextended(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        System.out.println("Coefficients: x = " + x + ", y = " + y);
        return gcd;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n1 = s.nextInt();
        int n2 = s.nextInt();
        int x = 1;
        int y = 1;
        int result = gcdextended(n1, n2, x, y);
        System.out.println("GCD: " + result);
    }
}

//TC - O(log(min(a, b))) 
//SC - O(log(min(a, b))) 
