#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int findMode(const unordered_map<int, int>& freq) {
    int maxFreq = 0;
    int mode = 0;
    
    for (const auto& [num, count] : freq) {
        if (count > maxFreq || (count == maxFreq && num < mode)) {
            maxFreq = count;
            mode = num;
        }
    }
    return mode;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        // Add current element to frequency map
        freq[arr[i]]++;
        
        if (i >= k - 1) {
            // Window is complete, find mode
            int mode = findMode(freq);
            cout << mode << " ";
            
            // Remove the element going out of window
            freq[arr[i - k + 1]]--;
            if (freq[arr[i - k + 1]] == 0) {
                freq.erase(arr[i - k + 1]);
            }
        }
    }
    
    return 0;
}