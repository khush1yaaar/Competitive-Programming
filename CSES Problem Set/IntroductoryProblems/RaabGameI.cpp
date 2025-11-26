#include <iostream>

using namespace std;

int main() {
    int t; cin>>t;

    while(t-- > 0) {
        int n; cin>>n;
        int a; cin>>a;
        int b; cin>>b;

        if((a + b) > n) {
            cout<<"NO\n";
            continue;
        }

        if((a + b) > 0 && (a == 0 || b == 0)) {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";

        int draw = n - (a + b);
        int s2 = n - draw;

        for(int i = (b + 1); i <= s2; i++) {
            cout<<i<<" ";
        }

        for(int i = 1; i <= b; i++) {
            cout<<i<<" ";
        }

        for(int i = 1; i <= draw; i++) {
            cout<<(s2+i)<<" ";
        }

        cout<<"\n";

        for(int i = 0; i < n; i++) {
            cout<<(i + 1)<<" ";
        }
    }
    return 0;
}