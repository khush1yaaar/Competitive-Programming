#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k;
multiset<ll> min_half;
multiset<ll> max_half;
ll min_sum;
ll max_sum;

ll calculateMedian() {
    if(k % 2 == 0) {
        return 0;
    }

    return *min_half.rbegin();
}

void adding(ll value) {
    if(min_half.empty()) {
        min_half.insert(value);
        min_sum += value;
        return;
    }
    ll current_median = *min_half.rbegin();
    if (current_median < value) {
        max_half.insert(value);
        max_sum += value;
        if((ll) max_half.size() > k / 2) {
            ll moving = *max_half.begin();

            min_half.insert(moving);
            min_sum += moving;

            max_sum -= moving;
            max_half.erase(max_half.find(moving));
        }
    }
    else {
        min_half.insert(value);
        min_sum += value;
        if((ll) min_half.size() > (k + 1) / 2) {
            ll moving = *min_half.rbegin();

            max_half.insert(moving);
            max_sum += moving;

            min_sum -= moving;
            min_half.erase(min_half.find(moving));
        }
    }
}

void removing(ll value) {
    if(max_half.find(value) != max_half.end()) {
        max_half.erase(max_half.find(value));
        max_sum -= value;
    }
    else {
        min_half.erase(min_half.find(value));
        min_sum -= value;
    }

    if(min_half.empty()) {
        ll moving = *max_half.begin();

        min_half.insert(moving);
        min_sum += moving;

        max_sum -= moving;
        max_half.erase(max_half.find(moving));
    }
}

int main() {
    cin>>n;cin>>k;
    vector<ll> nums(n);
    vector<ll> result;
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    for(int i = 0; i < k; i++) {
        adding(nums[i]);
    }

    result.push_back(max_sum - min_sum + calculateMedian());

    for(int i = k; i < n; i++) {
        if (k == 1) {
            adding(nums[i]);
            removing(nums[i - (int)k]);
        } else {
            removing(nums[i - (int)k]);
            adding(nums[i]);
        }

        result.push_back(max_sum - min_sum + calculateMedian());
    }

    for(int i = 0; i < (int)result.size(); i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}