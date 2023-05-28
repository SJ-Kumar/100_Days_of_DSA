//Euler's phi to print the count
import java.io.*;

class EthCode {
    // Function to return GCD of a and b
    static int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    static int phi(int n) {
        int result = 1;
        for (int i = 2; i < n; i++)
            if (gcd(i, n) == 1)
                result++;
        return result;
    }
    public static void main(String[] args) {
        int n;
        // Finding Phi for input n
        for (n = 1; n <= 10; n++)
            System.out.println(phi(n));
    }
}



// To print those elements itself
import java.util.*;

public class Euler {
    public static int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }

    public static List<Integer> getCoprimes(int n) {
        List<Integer> coprimes = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (gcd(i, n) == 1) {
                coprimes.add(i);
            }
        }
        return coprimes;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = s.nextInt();

        List<Integer> coprimes = getCoprimes(n);
        System.out.println("Coprimes to " + n + ": " + coprimes);
    }
}
