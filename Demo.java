
import java.util.*;

class Demo {

    public static void main(String arg[]) {

        Scanner sc = new Scanner(System.in);
        System.out.println("ENETR HOW MANY NUMBER DO YOU WANT TO ENTER IN ARRAY=");
        int N = sc.nextInt();
        int arr1[] = new int[N];

        for (int i = 0; i < N; i++) {
            arr1[i] = sc.nextInt();
        }

        for (int i = 0; i < N; i++) {
            System.out.println(arr1[i]);
        }

        for (int i = N - 1; i >= 0; i++) {
            System.out.println(arr1[i]);
        }

    }
}
