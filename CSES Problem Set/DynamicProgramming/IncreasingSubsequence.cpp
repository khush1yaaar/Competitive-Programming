#include <bits/stdc++.h>
using namespace std;

int helper(int idx, int prev, vector<long long>& nums, vector<vector<int>>& dp) {
    if(idx == nums.size()) {
        return 0;
    }

    if(dp[idx][prev + 1] != -1) {
        return dp[idx][prev + 1];
    }

    int pick = INT_MIN;
    if(prev == -1 || nums[prev] < nums[idx]) {
        pick = 1 + helper(idx + 1, idx, nums, dp);
    }

    int notPick = helper(idx + 1, prev, nums, dp);

    return dp[idx][prev + 1] = max(pick, notPick);
}

int main() {
    long n;
    cin >> n;
    
    vector<long long> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    int result = helper(0, -1, nums, dp);

    cout << result << endl;

    return 0;
}