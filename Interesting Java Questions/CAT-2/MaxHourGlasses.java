import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
        int r=s.nextInt();
        int c=s.nextInt();
        int[][] a=new int[r][c];
        int sum=0;int max=0;
        if(r<3 || c<3){
            System.exit(0);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                a[i][j]=s.nextInt();
            }
        }
        for(int i=0;i<r-2;i++){
            for(int j=0;i<c-2;j++){
                sum=(a[i][j]+a[i][j+1]+a[i][j+2])+(a[i+1][j+1])+(a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]);
                max=Math.max(sum,max);
            }
        }
        System.out.println(max);
        
    }
}


//TC - O(R*C)
//SC - O(1)
