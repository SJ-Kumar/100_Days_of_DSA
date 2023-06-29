import java.util.Scanner;

class Main {
    public static int eqb(int[] arr,int n){
        int res=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int prefix_sum=arr[i];
            for(int j=0;j<i;j++){
                prefix_sum+=arr[j];
            }
            int suffix_sum=arr[i];
            for(int j=n-1;j>i;j--){
                suffix_sum+=arr[j];
            }
            res=Math.max(res,prefix_sum);
        }
        return res;
    }
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=s.nextInt();
        }
        System.out.println(eqb(arr,n));
    }
}

//TC = O(n^2)
//SC = O(1)
