import java.util.*;
class Main {
    public static int flip(int a){
        int currLen=0,prevLen=0,maxLen=0;
        while(a!=0){
            if((a&1)==1){
                currLen++;
            }
            else if((a&1) == 0)
            {
                prevLen = (a&2)== 0 ? 0:currLen;
                currLen=0;
            }
            maxLen=Math.max(maxLen,prevLen+currLen);
            a>>=1;
        }
        return maxLen+1;
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        System.out.println(flip(n));
    }
}

//TC - O(n)
//SC - O(1)
