import java.util.*;
public class IncreasingArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        long result = 0; 
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                int diff = Math.abs(nums[i - 1] - nums[i]);
                result += diff;
                nums[i] += diff;
            }
        }

        System.out.println(result);
        sc.close();
    }
}
