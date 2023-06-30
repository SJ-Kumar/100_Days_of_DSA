import java.util.*;

class Main {
    public static int flip(int a, int k) {
        int currLen=0;int maxLen=0;int prevLen=0;
        int flips=0;
        while(a!=0){
            if((a&1)==1){
                currLen++;
            }
            else if((a&1)==0){
                prevLen=((a&2)==0) ? 0:currLen;
                currLen=0;
                if(flips<k){
                    currLen++;
                    flips++;
                }
                else{
                    break;
                }
            }
            maxLen=Math.max(maxLen,prevLen+currLen);
            a>>=1;
        }
        return maxLen +1;
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int k=s.nextInt();
        System.out.println(flip(n,k));
    }
}


//TC - O(n)
//SC - O(1)
