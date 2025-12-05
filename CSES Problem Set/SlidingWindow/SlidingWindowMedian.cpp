#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void adding(int val, multiset<int>& minHalf, multiset<int>& maxHalf, int k) {
    if (minHalf.empty()) {
        minHalf.insert(val);
        return;
    }
    
    int curr = *minHalf.rbegin();
    if (curr < val) {
        maxHalf.insert(val);
        if ((int)maxHalf.size() > k / 2) {
            minHalf.insert(*maxHalf.begin());
            maxHalf.erase(maxHalf.begin());
        }
    }
    else {
        minHalf.insert(val);
        if ((int)minHalf.size() > (k + 1) / 2) {
            maxHalf.insert(*minHalf.rbegin());
            auto it = minHalf.end();
            --it;
            minHalf.erase(it);
        }
    }
} 

void removing(int val, multiset<int>& minHalf, multiset<int>& maxHalf) {
    if (maxHalf.find(val) != maxHalf.end()) {
        maxHalf.erase(maxHalf.find(val));
    }
    else if (minHalf.find(val) != minHalf.end()) {
        minHalf.erase(minHalf.find(val));
    }

    if (minHalf.empty() && !maxHalf.empty()) {
        minHalf.insert(*maxHalf.begin());
        maxHalf.erase(maxHalf.begin());
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result;
    multiset<int> minHalf;
    multiset<int> maxHalf;

    minHalf.insert(nums[0]);
    for (int i = 1; i < k; i++) {
        adding(nums[i], minHalf, maxHalf, k);
    }
    result.push_back(*minHalf.rbegin());

    for (int i = k; i < n; i++) {
        removing(nums[i - k], minHalf, maxHalf);
        adding(nums[i], minHalf, maxHalf, k);
        result.push_back(*minHalf.rbegin());
    }

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}