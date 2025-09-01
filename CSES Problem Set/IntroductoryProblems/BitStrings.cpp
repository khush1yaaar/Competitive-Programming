#include <iostream> 

using namespace std;

int main() {
    int n; cin>>n;
    int curr = 2;
    for(int i = 2; i <= n; i++) {
        curr = curr * 2;
        curr = curr % 1000000007;
    }

    cout<<curr;
    return 0;
}