import java.util.*;
public class ArrivalOfTheGeneral {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        int max_idx = 0;
        int min_idx = n - 1;
        int result = 0;

        for(int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] <= nums[min_idx]) {
                min_idx = i;
            }
        }
        result =  max_idx + (n - 1 - min_idx);


        if(max_idx > min_idx) {
            result--;
        }

        System.out.println(result);

        sc.close();
    }
}