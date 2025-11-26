#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    long long result = 0;
    vector<long long> bit_count(31, 0);
    vector<long long> window(k);
    
    int idx = 0;
    long long prev = x;
    long long current_or = 0;

    for(long long i = 1; i <= n; i++) {
        long long val = (i == 1) ? x : ((a * prev) + b) % c;
        prev = val;

        // Remove old element if window is full
        if(i > k) {
            long long oldEl = window[idx];
            for(int bit = 0; bit < 31; bit++) {
                if(oldEl & (1LL << bit)) {
                    bit_count[bit]--;
                    if(bit_count[bit] == 0) {
                        current_or &= ~(1LL << bit);  // Clear the bit if count becomes 0
                    }
                }
            }
        }

        // Add new element
        window[idx] = val;
        for(int bit = 0; bit < 31; bit++) {
            if(val & (1LL << bit)) {
                bit_count[bit]++;
                current_or |= (1LL << bit);  // Set the bit
            }
        }

        // Update index
        idx = (idx + 1) % k;

        // Calculate result if window is full
        if(i >= k) {
            result ^= current_or;
        }
    }

    cout << result;
    return 0;
}