#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int editDistance(int i, int j, string s, string t, vector<vector<int>> &dp) {
    // best case
    if(i == s.length() && j == t.length()) {
        return 0;
    }

    // base cases
    if(i == s.length()) {
        return t.length() - j;
    }
    if(j == t.length()) {
        return s.length() - i;
    }

    // dp
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int same = INT_MAX;
    if(s[i] == t[j]) {
        same = editDistance(i + 1, j + 1, s, t, dp);
    }

    int add = 1 + editDistance(i, j + 1, s, t, dp);
    int remove = 1 + editDistance(i + 1, j, s, t, dp);
    int replace = 1 + editDistance(i + 1, j + 1, s, t, dp);

    int result = min(same, min(add, min(remove, replace)));

    return dp[i][j] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s;
    string t; cin>>t;
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));

    int result = editDistance(0, 0, s, t, dp);

    cout<<result;
    return 0;
}