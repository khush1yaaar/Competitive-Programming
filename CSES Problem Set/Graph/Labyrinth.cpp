#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int sx, sy, ex, ey;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 'A') sx = i, sy = j;
            if (graph[i][j] == 'B') ex = i, ey = j;
        }
    }

    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveTaken(n, vector<char>(m, '?'));


    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};
    char move[] = {'L', 'R', 'U', 'D'};

    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while(!q.empty()) {
        pair curr = q.front();
        q.pop();

        int i = curr.first;
        int j = curr.second;

        if(i == ex && j == ey) {
            break;
        }

        for(int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && graph[ni][nj] != '#') {

                vis[ni][nj] = true;
                parent[ni][nj] = {i, j};
                moveTaken[ni][nj] = move[k];

                q.push({ni, nj});
            }
        }
    }

    if(!vis[ex][ey]) {
        cout<<"NO";
        return 0;
    }

    vector<char> path;

    int cx = ex, cy = ey;

    while(!(cx == sx && cy == sy)) {
        path.push_back(moveTaken[cx][cy]);

        pair p = parent[cx][cy];
        cx = p.first;
        cy = p.second;
    }

    reverse(path.begin(), path.end());

    cout<<"YES"<<"\n";
    cout<<path.size()<<"\n";
    for(char ch: path) cout<< ch;

    return 0;
}