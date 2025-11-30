#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

int removingDigits(int n, vector<int> &dp) {
    if(n == 0) {
        return 0;
    }
    if(n < 10) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    vector<int> digits;
    int temp = n; 
    while(temp > 0) {
        int digit = temp % 10;
        digits.push_back(digit);
        temp = temp / 10;
    }

    int ans = INT_MAX - 1;

    for(int i = 0; i < digits.size(); i++) {
        int digit = digits[i];
        if(digit == 0) continue;
        ans = min(ans, 1 + removingDigits(n - digit, dp));
    }

    return dp[n] = ans;
}

int main() {
    int n; cin>>n;
    vector<int> dp(n + 1, -1);

    int result = removingDigits(n, dp);

    cout<<result;
    return 0;
}