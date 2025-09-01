#include <iostream> 
using namespace std;

int main() {
    int t; cin>>t;
    while(t-- > 0) {
        int a; cin>>a;
        int b; cin>>b;
        if(b > a) {
            std::swap(a, b);
        }
        if(a > 2 * b || (a + b) % 3 != 0) {
            cout<<"NO"<<"\n";
        }
        else {
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}