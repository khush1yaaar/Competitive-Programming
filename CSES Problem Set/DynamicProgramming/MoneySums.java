import java.util.*;

public class MoneySums {
    static int[] coins;
    static int n;
    static Boolean[][] DP; // DP[index][sum] = can we make 'sum' using coins from index to n-1
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        coins = new int[n];
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
            totalSum += coins[i];
        }
        
        // Initialize memoization table
        DP = new Boolean[n + 1][totalSum + 1];
        
        // Find all possible sums
        Set<Integer> possibleSums = new TreeSet<>();
        for (int sum = 1; sum <= totalSum; sum++) {
            if (canMakeSum(0, sum)) {
                possibleSums.add(sum);
            }
        }
        
        // Output
        System.out.println(possibleSums.size());
        boolean first = true;
        for (int sum : possibleSums) {
            if (!first) System.out.print(" ");
            System.out.print(sum);
            first = false;
        }
        System.out.println();
        
        sc.close();
    }
    
    // Recursive function with memoization
    // Returns true if we can make 'sum' using coins from index 'idx' onwards
    static boolean canMakeSum(int idx, int sum) {
        // Base cases
        if (sum == 0) return true;  // We can always make sum 0
        if (idx == n) return false; // No more coins left
        if (sum < 0) return false;  // Invalid sum
        
        // Check if already computed
        if (DP[idx][sum] != null) {
            return DP[idx][sum];
        }
        
        // Recursive case: either take current coin or skip it
        boolean take = canMakeSum(idx + 1, sum - coins[idx]); // Take current coin
        boolean skip = canMakeSum(idx + 1, sum);               // Skip current coin
        
        // Memoize and return
        DP[idx][sum] = take || skip;
        return DP[idx][sum];
    }
}