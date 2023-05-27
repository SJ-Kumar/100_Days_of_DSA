// Simple Seive is used for Finding Prime Nos upto n

import java.util.*;
public class SieveMain {
    public static void simpleSieve(int n) {
        boolean[] prime = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            prime[i] = true;
        }
    
        // Mark all the multiples of the prime numbers
        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
    
        // Print all prime numbers
        for (int p = 2; p <= n; p++) {
            if (prime[p] == true) {
                System.out.print(p + " ");
            }
        }
    }    
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        simpleSieve(n);     
    }
}
