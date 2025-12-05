import java.util.*;

public class IncreasingSubsequenceII {

    static long MOD = 1000000007;

    public static long helper(int idx, int prev, int[] nums, long[][] dp) {
        if(idx == nums.length) {
            return 1;
        }

        if(dp[idx][prev + 1] != -1) {
            return dp[idx][prev + 1];
        }

        long pick = 0;

        if(prev == -1 || nums[prev] < nums[idx]) {
            pick = helper(idx + 1, idx, nums, dp) % MOD;
        } 

        long notPick = helper(idx + 1, prev, nums, dp) % MOD;

        return dp[idx][prev + 1] = pick + notPick;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        long[][] dp = new long[n + 1][n + 1];
        for(long[] d: dp) {
            Arrays.fill(d, -1);
        }

        long result = helper(0, -1, nums, dp);

        System.out.println(result - 1);
        sc.close();
    }
}