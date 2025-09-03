#include <iostream>
#include <set>

using namespace std;

void helper(string curr, bool vis[], string s, set<string>& result) {
    if(curr.length() == s.length()) {
        result.insert(curr);
        return;
    }

    for(int i = 0; i < s.length(); i++) {
        if(!vis[i]) {
            curr.push_back(s[i]);
            vis[i] = true;

            helper(curr, vis, s, result);

            curr.pop_back();
            vis[i] = false;
        }
    }
}

int main() {
    string s; cin>>s;
    set<string> result;
    string curr;
    int n = s.length();
    bool vis[n];
    for(int i = 0; i < n; i++) {
        vis[i] = false;
    }

    helper(curr, vis, s, result);

    cout<<result.size()<<"\n";

    for(string curr: result) {
        cout<<curr<<"\n";
    }
    return 0;
}