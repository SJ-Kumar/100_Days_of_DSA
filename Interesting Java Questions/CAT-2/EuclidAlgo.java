import java.util.*;
class Main{
    public static int gcd(int a,int b){
        if(a==0){
            return b;
        }
        return gcd(b%a,a);
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n1=s.nextInt();
        int n2=s.nextInt();
        int result=gcd(n1,n2);
        System.out.println(result);
    }
}

//TC - O(log N)
//SC - O(log N)
