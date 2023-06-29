
import java.util.Scanner;
class Main {
    public static long karatsuba(long x,long y){
        if(x<10 & y<10){
            return x*y;
        }
        long n=Math.max(String.valueOf(x).length(),String.valueOf(y).length());
        long n2=n/2;
        long a=x/(long)Math.pow(10,n2);
        long b=x%(long)Math.pow(10,n2);
        long c=y/(long)Math.pow(10,n2);
        long d=y%(long)Math.pow(10,n2);
        long ac=karatsuba(a,c);
        long bd=karatsuba(b,d);
        long ch = karatsuba(a+b,c+d);
        long ch1 = ch-bd-ac;
        long result=ac*(long)Math.pow(10,n)+bd+ch1*(long)Math.pow(10,n/2);
        return result;
        
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        long x=s.nextLong();
        long y=s.nextLong();
        long product=karatsuba(x,y);
        System.out.println(product);
    }
}

//TIME COMPLEXITY = 3*T(n/2)+O(n) or O(nlogn)
//SPACE COMPLEXITY = O(logn)
