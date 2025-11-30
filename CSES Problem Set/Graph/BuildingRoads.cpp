#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[node] = true;

    for(int next: adj[node]) {
        if(!vis[next]) {
            dfs(next, vis, adj);
        }
    }
}

int main() {
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for(int i = 0; i < m; i++) {
        int u; cin>>u;
        int v; cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> nodes;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            nodes.push_back(i);
            dfs(i, vis, adj);
        }
    }

    cout<<(nodes.size() - 1)<<"\n";
    for(int i = 0; i < nodes.size() - 1; i++) {
        cout<<nodes[i]<<" "<<nodes[i + 1]<<"\n";
    }

    return 0;
}