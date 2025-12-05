#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;

string solve(int i, int j, vector<vector<char>> &grid, vector<vector<string>> &dp) {
    if(i == n - 1 && j == n - 1) {
        return string(1, grid[i][j]);
    }
    
    if(!dp[i][j].empty()) {
        return dp[i][j];
    }
    
    string result = "";
    
    if(i < n - 1 && j < n - 1) {
        string goDown = solve(i + 1, j, grid, dp);
        string goRight = solve(i, j + 1, grid, dp);
        result = grid[i][j] + min(goDown, goRight);
    }
    else if(i < n - 1) {
        result = grid[i][j] + solve(i + 1, j, grid, dp);
    }
    else if(j < n - 1) {
        result = grid[i][j] + solve(i, j + 1, grid, dp);
    }
    
    return dp[i][j] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }
    }
    vector<vector<string>> dp(n, vector<string>(n, ""));
    string result = solve(0, 0, grid, dp);

    cout<<result;

    return 0;
}