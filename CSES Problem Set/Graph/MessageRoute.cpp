#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

int main() {
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);

    for(int i = 0; i < m; i++) {
        int u; cin>>u;
        int v; cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    q.push(-1);
    vis[1] = true;

    bool found = false;
    int count = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(node == -1) {
            count++;
            if(q.empty()) {
                break;
            }

            else {
                q.push(-1);
                continue;
            }
        }


        if(node == n) {
            found = true;
            break;
        }

        for(int next: adj[node]) {
            if(!vis[next]) {
                parent[next] = node;
                vis[next] = true;
                q.push(next);
            }
        }
    }

    if(!found) {
        cout<<"IMPOSSIBLE"; 
        return 0;
    }

    cout<<count<<"\n";

    vector<int> path;
    int current = n;
    while(current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    for(int x : path) cout << x << " ";

    return 0;
}