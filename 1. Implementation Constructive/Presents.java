import java.util.*;

public class Presents {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int[] result = new int[n];
        for(int i = 0; i < n; i++) {
            result[nums[i] - 1] = i + 1;
        }

        for(int i = 0; i < n; i++) {
            if(i == n-1) {
                System.out.println(result[i]);
                continue;
            }
            System.out.print(result[i] + " ");
        }

        sc.close();
    }
}
