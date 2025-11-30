#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int gridpath1(int i, int j, int n, vector<vector<char>> &grid, vector<vector<bool>> &vis, vector<vector<int>> &dp) {
    if(i == n - 1 && j == n - 1) {
        return 1;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    vis[i][j] = true;

    int right = 0;
    if(j < n - 1 && !vis[i][j + 1] && grid[i][j + 1] == '.') {
        right = gridpath1(i, j + 1, n, grid, vis, dp) % MOD;
    }

    int down = 0;

    if(i < n - 1 && !vis[i + 1][j] && grid[i + 1][j] == '.') {
        down = gridpath1(i + 1, j, n, grid, vis, dp) % MOD;
    }

    vis[i][j] = false;

    return dp[i][j] = (right + down) % MOD;
}

int main() {
    int n; cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }
    }

    if(grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        cout<<0;
        return 0;
    }

    int result = gridpath1(0, 0, n, grid, vis, dp);

    cout<<result;

    return 0;
}