#include <iostream> 
using namespace std;

int main() {
    int q; cin>>q;

    for(int i = 0; i < q; i++) {
        int n; cin>>n;

        int d = (n / 10) + 1;
        int a = n % 10;

        int r = a / d;

        cout<<r<<"\n";
    }

    return 0;
}