#include <iostream>

using namespace std;

void TowerOfHanoi(int n, int a, int b, int c) {
    if(n == 0) {
        return;
    }

    TowerOfHanoi(n - 1, a, c, b);
    cout<<a<<" "<<c<<"\n";
    TowerOfHanoi(n - 1, b, a, c);
}

int main() {
    int n; cin>>n;

    cout<<(1<<n) - 1<<"\n";
    TowerOfHanoi(n, 1, 2, 3);

    return 0;
}