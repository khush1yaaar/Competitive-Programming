#include <iostream> 
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;

int calculate(int i, int j, vector<int> &count) {
    int ans = 0;
    for(int k = i; k <= j; k++) {
        ans += count[k];
    }

    return ans;
}

int main() {
    cin>>n>>k;
    vector<ll> nums(n);
    vector<int> result;
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
        maxi = max(maxi, nums[i]);
    }

    vector<int> count(maxi + 1);
    int inv = 0;
    for(int i = 0; i < k; i++) {
        int greater_num = calculate(nums[i] + 1, maxi, count);
        inv += greater_num;
        count[nums[i]]++;
    }

    result.push_back(inv);

    for(int i = k; i < n; i++) {
        count[nums[i - k]]--;
        int prev = calculate(0, nums[i - k] - 1, count);
        inv -= prev;
    
        int greater_num = calculate(nums[i] + 1, maxi, count);
        inv += greater_num;
        count[nums[i]]++;

        result.push_back(inv);
    }

    for(int i = 0; i < (int) result.size(); i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}