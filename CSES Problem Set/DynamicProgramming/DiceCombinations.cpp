#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long countNumberofways(int target, vector<int> &dp) {
    if(target == 0) {
        return 1;
    }

    if(dp[target] != -1) {
        return dp[target];
    }  

    long pick = 0;

    for(int dice = 1; dice <= 6; dice++) {
        if(dice <= target) {
            pick = (pick + countNumberofways(target - dice, dp)) % MOD;
        }
    }

    return dp[target] = pick;
}

int main() {
    int n; cin>>n;
    vector<int> dp(n + 1, -1);

    long result = countNumberofways(n, dp);
    cout<<result;
    return 0;
}