//TC-O(2^n)
//SC-O(n)

import java.util.*;
public class Main{
    public static void Hanoi(int n,char source,char destination,char auxiliary){
        if(n==1){
            System.out.println("Move disk "+n+" from "+source+" to "+destination);
            return;
        }
        Hanoi(n-1,source,auxiliary,destination);
        System.out.println("Move disk "+n+" from "+source+" to "+destination);
        Hanoi(n-1,auxiliary,destination,source);
        
    }
    public static void main(String args[]){
        Scanner s= new Scanner(System.in);
        int n=s.nextInt();
        char a=s.next().charAt(0);
        char b=s.next().charAt(0);
        char c=s.next().charAt(0);
        Hanoi(n,a,b,c);
    }
}
