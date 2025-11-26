#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix(100, vector<int>(100, 0));
vector<int> pow = {0, 1, 2, 4, 8, 16, 32, 64, 128};

void build(int r, int c) {
    int i = 0; int j = 0;
    while(pow[i] <= r) i++;
    while(pow[j] <= c) j++;
    i--; j--;

    if(pow[i] == pow[j]) {
        matrix[r][c] = matrix[r - pow[i]][c - pow[j]]; 
    }
    else if(pow[i] > pow[j]) {
        matrix[r][c] = matrix[r - pow[i]][c] + pow[i]; 
    }
    else {
        matrix[r][c] = matrix[r][c - pow[j]] + pow[j]; 
    }
}

int main() {
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            build(i, j);
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}