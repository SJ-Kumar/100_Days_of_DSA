import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int a[] = {1, 2, 2, 2, 2};
        int n = a.length;
        majority(a, n);
    }

    public static void majority(int a[], int n) {
        Arrays.sort(a);
        int max = 0;
        int index = 0;
        int count = 1;
        int flag = 0;
        int temp = a[0];
        int i;

        for (i = 1; i < n; i++) {
            if (a[i] == temp) {
                count++;
            } else {
                temp = a[i];
                count = 1;
            }

            if (max < count) {
                max = count;
                index = i;
                if (max > (n / 2)) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) {
            System.out.println(a[index]);
        } else {
            System.out.println("No majority element");
        }
    }
}

//TC = O(nlogn)
//SC = O(1)
