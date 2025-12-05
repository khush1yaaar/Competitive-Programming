#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    unordered_set<int> st;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        st.insert(nums[i]);
    }
    
    set<int> sett;
    
    for(int i = 0; i < 1000000000; i++) {
        if(st.count(i)) {
            sett.insert(i);
        }
        else {
            sett.insert(i);
            break;
        }
    }
    
    unordered_map<int, int> map;
    vector<int> result;
    
    for(int i = 0; i < k; i++) {
        sett.erase(nums[i]);
        map[nums[i]]++;
    }
    
    result.push_back(*sett.begin());
    
    for(int i = k; i < n; i++) {
        if(map[nums[i - k]] == 1) {
            sett.insert(nums[i - k]);
        }
        
        map[nums[i - k]]--;
        
        sett.erase(nums[i]);
        map[nums[i]]++;
        
        result.push_back(*sett.begin());
    }
    
    for(int num : result) {
        cout << num << " ";
    }
    
    return 0;
}