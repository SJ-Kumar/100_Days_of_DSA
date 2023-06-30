public class Main {
    public static void main(String[] args) {
        int n1 = 10;
        int n2 = 5;
        int result = booth(n1, n2);
        System.out.println("Result: " + result);
    }

    public static int booth(int n1, int n2) {
        int result=0;
        int A=n1;
        int S=-n1;
        int m=n1;
        int r=n2;
        int count=Integer.SIZE;
        while(count>0){
            if((r&1)==1){
                result+=A;
                S+=m;
            }
            A<<=1;
            S<<=1;
            m<<=1;
            r>>=1;
            count--;
        }
        return result;
    }
}

//TC = O(1)
//SC = O(1)
