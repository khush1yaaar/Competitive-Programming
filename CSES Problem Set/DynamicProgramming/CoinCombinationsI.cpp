#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }
    
    cout << dp[amount] << endl;
    return 0;
}