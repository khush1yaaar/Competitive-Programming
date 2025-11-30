#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minimizingCoins(int amount,vector<int> &coins, vector<int> &dp) {
    if(amount == 0) {
        return 0;
    }

    if(dp[amount] != -1) {
        return dp[amount];
    }

    int pick = INT_MAX - 1;

    for(int idx = 0; idx < coins.size(); idx++) {
        if(coins[idx] <= amount) {
            pick = min(1 + minimizingCoins(amount - coins[idx], coins, dp), pick);
        }
    }

    return dp[amount] = pick;
}

int main() {
    int n; cin>>n;
    int amount; cin>>amount;
    vector<int> dp(amount + 1, -1);
    vector<int> coins(n);

    for(int i = 0; i < n; i++) {
        cin>>coins[i];
    }

    int result = minimizingCoins(amount, coins, dp);

    if(result == INT_MAX - 1) {
        result = -1;
    }

    cout<<result;

    return 0;
}