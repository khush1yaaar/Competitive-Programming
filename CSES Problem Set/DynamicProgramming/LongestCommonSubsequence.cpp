#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LCS(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
    if(i == nums1.size() || j == nums2.size()) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(nums1[i] == nums2[j]) {
        return dp[i][j] = 1 + LCS(i + 1, j + 1, nums1, nums2, dp);
    } else {
        int skip1 = LCS(i + 1, j, nums1, nums2, dp);
        int skip2 = LCS(i, j + 1, nums1, nums2, dp);
        return dp[i][j] = max(skip1, skip2);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    int m; cin>>m;

    vector<int> nums1(n);
    vector<int> nums2(m);

    for(int i = 0; i < n; i++) {
        cin>>nums1[i];
    }

    for(int i = 0; i < m; i++) {
        cin>>nums2[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
    // Calculate LCS length
    int result = LCS(0, 0, nums1, nums2, dp);
    cout << result << "\n";


    // Reconstruct the actual LCS sequence
    vector<int> lcsSequence;

    int i = 0;
    int j = 0;
    
    while(i < n && j < m) {
        if(nums1[i] == nums2[j]) {
            lcsSequence.push_back(nums1[i]);
            i++;
            j++;
        }

        else if(dp[i + 1][j] > dp[i][j + 1]) {
            i++;
        }
        else {
            j++;
        }
    }
    
    for(int num : lcsSequence) {
        cout << num << " ";
    }
    
    return 0;
}