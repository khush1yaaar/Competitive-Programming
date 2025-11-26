#include <iostream> 
#include <set>
#include <vector>

using namespace std;

int main() {
    int n; cin>>n;
    int m; cin>>m;
    vector<string> a(n);
    for(string& row: a) {
        cin>>row;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            set<char> s;
            if(i != 0) {
                s.insert(a[i-1][j]);
            }

            if(j != 0) {
                s.insert(a[i][j-1]);
            }

            s.insert(a[i][j]);

            for(char x = 'A'; x <= 'D'; x++) {
                if(!s.count(x)) {
                    a[i][j] = x;
                    break;
                }
            }
        }

        cout<<a[i]<<"\n";
    }
    return 0;
}