/*
the task is to find the minimum number of apples to be collected from the trees to guarantee M red apples.
*/

import java.util.*;
public class Apples{
    public static int minApples(int M,int K,int N,int S,int W,int E){
        if(M<=S*K){
            return M;
        }
        else if(M<=S*K+E+W){
            return ((S*K)-(M-S*K));
        }
        else{
            return -1;
        }
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int M=s.nextInt();
        int K=s.nextInt();
        int N=s.nextInt();
        int S=s.nextInt();
        int W=s.nextInt();
        int E=s.nextInt();
        int ans=minApples(M,K,N,S,W,E);
        System.out.println(ans);
    }
}
