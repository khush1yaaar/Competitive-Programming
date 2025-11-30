#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int bookShop(int idx, int amount, int n, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp) {
    if(idx == n || amount == 0) {
        return 0;
    }

    if(dp[idx][amount] != -1) {
        return dp[idx][amount];
    }

    int pick = 0;
    if(prices[idx] <= amount) {
        pick = pages[idx] + bookShop(idx + 1, amount - prices[idx], n, prices, pages, dp);
    }

    int notPick = bookShop(idx + 1, amount, n, prices, pages, dp);

    return dp[idx][amount] = max(pick, notPick);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    int amount; cin>>amount;

    vector<int> prices(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for(int i = 0; i < n; i++) {
        cin>>prices[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>pages[i];
    }

    // int result = bookShop(0, amount, n, prices, pages, dp);

    // cout<<result;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= amount; j++) {
            int notPick = dp[i + 1][j];
            int pick = 0;

            if(prices[i] <= j) {
                pick = pages[i] + dp[i + 1][j - prices[i]];
            }

            dp[i][j] = max(pick, notPick);
        }
    }

    cout<<dp[0][amount];
    
    return 0;
}