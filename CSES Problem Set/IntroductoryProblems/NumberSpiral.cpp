#include <iostream>

using namespace std;
int main() {
    int t;
    cin>>t;
    while(t-- > 0) {
        long x; cin>>x;
        long y; cin>>y;
        long result = 0;

        if (x == y) {
            result = x * x - (x - 1);
        } else if (x > y) {
            if (x % 2 == 0) {
                result = x * x - (y - 1);
            } else {
                result = (x - 1) * (x - 1) + 1 + (y - 1);
            }
        } else {
            if (y % 2 == 1) {
                result = y * y - (x - 1);
            } else {
                result = (y - 1) * (y - 1) + 1 + (x - 1);
            }
        }

        cout<<result << "\n";
    }
    return 0;
}