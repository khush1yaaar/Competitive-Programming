#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int coinCombinationII(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
    if(amount == 0) {
        return 1;
    }

    if(idx == coins.size()) {
        return 0;
    }

    if(dp[idx][amount] != -1) {
        return dp[idx][amount];
    }

    int pick = 0;
    if(coins[idx] <= amount) {
        pick = coinCombinationII(idx, amount - coins[idx], coins, dp);
    }

    int notPick = coinCombinationII(idx + 1, amount, coins, dp);

    return dp[idx][amount] = (pick + notPick) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // int result = coinCombinationII(0, amount, coins, dp);

    // cout<<result;

    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j <= amount; j++) {
            int pick = 0;
            if(coins[i] <= j) {
                pick = dp[i][j] + dp[i][j - coins[i]];
            }

            int notPick =  dp[i + 1][j];

            dp[i][j] = (pick + notPick) % MOD;
        }
    }

    cout<<dp[0][amount];

    return 0;
}