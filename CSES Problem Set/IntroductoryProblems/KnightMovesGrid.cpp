#include <iostream> 
#include <queue>
#include <utility> 

using namespace std;

int main() {
    int n; cin>>n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (auto &row : grid) {
        fill(row.begin(), row.end(), -1);
    }

    grid[0][0] = 0;

    int dx[] = {-2, -2,  2,  2, -1,  1, -1,  1};
    int dy[] = { 1, -1,  1, -1,  2,  2, -2, -2};
    queue<pair<int, int>> q;
    q.push({0,0});

    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;
        int steps = grid[i][j];

        for (int k = 0; k < 8; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == -1) {
                grid[ni][nj] = steps + 1;
                q.push({ni, nj});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}