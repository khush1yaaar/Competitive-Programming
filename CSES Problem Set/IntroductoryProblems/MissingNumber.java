import java.util.*;

public class MissingNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i = 0; i < n - 1; i++) {
            int num = sc.nextInt();
            nums[num - 1] = num;
        }

        int result = n;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == 0) {
                result = i + 1;
                break;
            }
        }

        System.out.println(result);
        sc.close();
    }
}
