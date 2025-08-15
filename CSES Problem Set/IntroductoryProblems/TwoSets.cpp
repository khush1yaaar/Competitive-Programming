#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin>>n;

    int nums[n + 1];
    for(int i = 1; i < n + 1; i++) {
        nums[i] = i;
    }
    int total_sum = n * (n + 1) / 2;
    bool can = false;
    vector<int> v1;
    vector<int> v2;

    if(total_sum % 2 == 0) {
        if(n % 4 == 0) {
            for(int i = 1; i <= n / 4; i++) {
                v1.push_back(i);
            }

            for(int i = 0; i < n / 4; i++) {
                v1.push_back(nums[n - i]);
            }

            for(int i = (n /4) + 1; i < v1[v1.size() - 1]; i++) {
                v2.push_back(i);
            }
            can = true;
        }

        else if(n % 4 == 3) {
            vector<int> v;
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            for(int i = 4; i < n + 1; i++) {
                v.push_back(i);
            }

            for(int i = 0; i < (n - 3) / 4; i++) {
                v1.push_back(v[i]);
                v1.push_back(v[v.size() - i - 1]);
            }
            for(int i = 4 + (n - 3)/ 4; i <= n - (n - 3) / 4; i++) {
                v2.push_back(i);
            }
            can = true;
        }
    }
    else {
        can = false;
    }

    if(!can) {
        cout<<"NO"<<"\n";
        return 0;
    }

    cout<<"YES"<< "\n";

    cout<<v1.size()<<"\n";
    for(int curr: v1) {
        cout<<curr<<" ";
    }
    cout<<"\n";
    cout<<v2.size()<<"\n";
    for(int curr: v2) {
        cout<<curr<<" ";
    }
    return 0;
}