import java.util.*;

class Main{
    public static int lis(int arr[],int i,int n,int prev){
        if(i==n){
            return 0;
        }
        int excl=lis(arr,i+1,n,prev);
        int incl=0;
        if(arr[i]>prev){
            incl=1+lis(arr,i+1,n,arr[i]);
        }
        return Integer.max(incl,excl);
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=s.nextInt();
        }
        System.out.println(lis(arr,0,n,Integer.MIN_VALUE));
    }
}
