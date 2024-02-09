//TC - O(n^2)
//SC - O(n)
import java.util.*;
public class Main{
    public static class StockSpan{
        public int[] stocks(int[] prices){
            int n=prices.length;
            int[] span = new int[n];
            span[0]=1;
            for(int i=1;i<n;i++){
                int j=i-1;
                while(j>=0 && prices[i]>=prices[j]){
                    span[i]++;
                    j--;
                }
            }
            return span;
        }
    }
    public static void main(String args[]){
        Scanner s= new Scanner(System.in);
        int n=s.nextInt();
        int[] prices = new int[n];
        for(int i=0;i<n;i++){
            prices[i]=s.nextInt();
        }
        int[] result = new StockSpan().stocks(prices);
        System.out.println("Span:"+Arrays.toString(result));
        
    }
}
