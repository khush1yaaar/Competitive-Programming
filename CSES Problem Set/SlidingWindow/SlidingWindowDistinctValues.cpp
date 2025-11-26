#include <iostream> 
#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n; cin>>n;
    int k; cin>>k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    map<int, int> map;

    for(int i = 0; i < n; i++) {
        int val = arr[i];
        map[val]++;

        if(i == k - 1) {
            cout<<map.size()<<" ";
        } 

        if(i >= k) {
            map[arr[i - k]]--;
            if(map[arr[i - k]] == 0) {
                map.erase(arr[i - k]);
            }
            cout<<map.size()<<" ";
        }
    }
    
    return 0;
}