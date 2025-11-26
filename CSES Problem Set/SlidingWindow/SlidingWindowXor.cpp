#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    int x; cin >> x;
    int a; cin >> a;
    int b; cin >> b;
    int c; cin >> c;

    int xr = 0;              // replaced "xor" (illegal keyword)
    int prev = x;

    vector<int> arr(k);      // store window
    arr[0] = prev;
    xr ^= prev;

    // generate first k numbers
    for (int i = 1; i < k; i++) {
        prev = (1LL * a * prev + b) % c;
        arr[i] = prev;
        xr ^= prev;
    }

    int result = xr;

    int idx = 0;             // circular index

    // sliding window
    for (int i = k; i < n; i++) {
        // generate next element
        int next = (1LL * a * prev + b) % c;
        prev = next;

        // remove oldest element
        xr ^= arr[idx];

        // add new element
        xr ^= next;

        // replace oldest in buffer
        arr[idx] = next;

        idx++;
        if (idx == k) idx = 0;

        result ^= xr;
    }

    cout << result;
    return 0;
}
