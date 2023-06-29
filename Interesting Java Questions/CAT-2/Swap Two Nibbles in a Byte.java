import java.util.Scanner;
class Main {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int swapn;
        swapn=((n & 0x0F) << 4 | (n & 0xF0) >> 4);
        System.out.println(swapn);
        s.close();
    }
}

//TIME COMPLEXITY = O(1)
//SPACE COMPLEXITY = O(1)
