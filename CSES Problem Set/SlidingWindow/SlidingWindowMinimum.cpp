#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long k; cin >> k;
    long long x; cin >> x;
    long long a; cin >> a;
    long long b; cin >> b;
    long long c; cin >> c;

    deque<pair<long long, long long>> dq;
    long long ans = 0;

    long long prev = x;

    for(long long i = 1; i <= n; i++) {
        long long val;
        
        if(i == 1) val = x;
        else {
            val = ((a * prev) + b) % c;
            prev = val;
        }

        while(!dq.empty() && dq.back().first >= val) {
            dq.pop_back();
        }

        dq.push_back({val, i});

        while(!dq.empty() && dq.front().second <= i - k) {
            dq.pop_front();
        }

        long long min = dq.front().first;

        if(i >= k) {
            ans = ans ^ min;
        }
    }

    cout<<ans;
    return 0;
}