import java.util.*;

public class Main{
    public static int[] maxsliding(int[] nums,int k){
        if(nums == null || nums.length==0){
            return new int[0];
        }
        int n=nums.length;
        int[] result = new int[n-k+1];
        for(int i=0;i<n-k+1;i++){
            int maxi=Integer.MIN_VALUE;
            for(int j=i;j<i+k;j++){
                maxi=Math.max(maxi,nums[j]);
            }
            result[i]=maxi;
        }
        return result;
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int k=s.nextInt();
        int[] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=s.nextInt();
        }
        int[] result = maxsliding(nums,k);
        for(int i : result){
            System.out.println(i+" ");
        }
    }
}
