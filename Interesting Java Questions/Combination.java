import java.util.*;

class Combination{
    public static int factorial(int number){
        int fact=1;
        for(int i=1;i<=number;i++){
            fact=fact*i;
        }
        return fact;
    }
    public static void main(String args[]){
        List <Integer> numbers = new ArrayList <Integer> ();
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        for(int i=0;i<n;i++){
            int num=s.nextInt();
            numbers.add(num);
        }
        int r=s.nextInt();
        int result=factorial(n)/(factorial(r)*factorial(n-r));
        System.out.println(result);
    }
}
