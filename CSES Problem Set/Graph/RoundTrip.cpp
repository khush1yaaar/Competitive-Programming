#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

int cycle_start = -1, cycle_end = -1;

bool dfs(int node, int parent, vector<int> &parents, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[node] = true;
    parents[node] = parent;

    for(int next: adj[node]) {
        if(!vis[next]) {
            if(dfs(next, node, parents, vis, adj)) return true;
        }

        else if(next != parent) {
            cycle_start = next;
            cycle_end = node;
            return true;
        }
    }

    return false;
} 

int main() {
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> parents(n + 1, -1);

    for(int i = 0; i < m; i++) {
        int u; cin>>u;
        int v; cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool found = false;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, parents, vis, adj)) {
                found = true;
                break;
            }
        }
    }

    if(!found) {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycle_start);

    for (int v = cycle_end; v != cycle_start; v = parents[v])
        cycle.push_back(v);

    cycle.push_back(cycle_start);

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";

    return 0;
}