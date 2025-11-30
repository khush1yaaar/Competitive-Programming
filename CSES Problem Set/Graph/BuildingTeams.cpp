#include <bits/stdc++.h>

using namespace std; 

bool bfs(int start, vector<int> &teams, vector<vector<int>> &adj) {
    queue<int> q;
    q.push(start);
    teams[start] = 1;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int next : adj[curr]) {
            // uncolored
            if(teams[next] == -1) {
                teams[next] = 3 - teams[curr]; // flip 1↔2
                q.push(next);
            }
            // conflict
            else if(teams[next] == teams[curr]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>> adj(n + 1);
    vector<int> teams(n + 1, -1);

    for(int i = 0; i < m; i++) {
        int u; cin>>u;
        int v; cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(teams[i] == -1) {
            if(!bfs(i, teams, adj)) {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout<<teams[i]<<" ";
    }
    return 0;
}