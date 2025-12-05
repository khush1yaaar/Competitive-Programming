#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rectangleCutting(int l, int b, vector<vector<int>> &dp) {
    if(l == b) {
        return 0;
    }

    if(dp[l][b] != -1) {
        return dp[l][b];
    }

    int mini = INT_MAX;

    for(int i = 1; i < b; i++) {
        mini = min(mini, 1 + rectangleCutting(l, i, dp) + rectangleCutting(l, b - i, dp));
    }

    for(int i = 1; i < l; i++) {
        mini = min(mini, 1 + rectangleCutting(i, b, dp) + rectangleCutting(l - i, b, dp));
    }

    return dp[l][b] = mini;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a; cin>>a;
    int b; cin>>b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    // int result = rectangleCutting(a, b, dp);

    // cout<<result;

    for(int l = 1; l <= a; l++) {
        for(int w = 1; w <= b; w++) {
            if(l == w) {
                dp[l][w] = 0;
                continue;
            }

            int mini = INT_MAX;

            for(int i = 1; i < w; i++) {
                mini = min(mini, 1 + dp[l][i] + dp[l][w - i]);
            }

            for(int i = 1; i < l; i++) {
                mini = min(mini, 1 + dp[i][w] + dp[l - i][w]);
            }

            dp[l][w] = mini;
        }
    }

    cout << dp[a][b] << "\n";

    return 0;
}