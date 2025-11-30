#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &graph) {
    vis[i][j] = true;
    int n = graph.size();
    int m = graph[0].size();

    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};

    for(int k = 0; k < 4; k++) {
        int ni = i + dr[k];
        int nj = j + dc[k];

        if(ni >= 0 && nj >= 0 && ni < n && nj < m &&
           !vis[ni][nj] && graph[ni][nj] == '.') {

            dfs(ni, nj, vis, graph);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && graph[i][j] == '.') {
                count++;
                dfs(i, j, vis, graph);
            }
        }
    }

    cout << count;
    return 0;
}
