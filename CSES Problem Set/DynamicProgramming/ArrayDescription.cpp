#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int arrayDescription(int idx, int prev, int n, int m, vector<int> &nums, vector<vector<int>> &dp) {
    // Base case: reached the end
    if(idx == n) {
        return 1;
    }
    
    // Memoization check
    if(dp[idx][prev] != -1) {
        return dp[idx][prev];
    }
    
    long long ans = 0;
    
    if(nums[idx] == 0) {
        // Try all valid values (within distance 1 from prev)
        for(int val = 1; val <= m; val++) {
            if(abs(val - prev) <= 1) {
                ans = (ans + arrayDescription(idx + 1, val, n, m, nums, dp)) % MOD;
            }
        }
    } else {
        // Value is fixed, check if it's valid
        if(abs(nums[idx] - prev) <= 1) {
            ans = arrayDescription(idx + 1, nums[idx], n, m, nums, dp);
        } else {
            ans = 0; // Invalid, no way to continue
        }
    }
    
    return dp[idx][prev] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    
    long long result = 0;
    
    if(nums[0] == 0) {
        // First element can be any value from 1 to m
        for(int val = 1; val <= m; val++) {
            result = (result + arrayDescription(1, val, n, m, nums, dp)) % MOD;
        }
    } else {
        // First element is fixed
        result = arrayDescription(1, nums[0], n, m, nums, dp);
    }
    
    cout << result << endl;
    
    return 0;
}