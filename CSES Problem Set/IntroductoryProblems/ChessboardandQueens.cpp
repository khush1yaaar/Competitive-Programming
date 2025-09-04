#include <iostream> 
using namespace std;

bool valid(int row, int col, char board[8][8]) {
    int r = row;
    int c = col;

    while(r >= 0 && c >= 0) {
        if(board[r][c] == 'Q') return false;
        r--; c--;
    }

    r = row;
    c = col;

    while(r < 9 && c >= 0) {
        if(board[r][c] == 'Q') return false;
        r++; c--;
    }

    r = row;
    c = col;


    while(c >= 0) {
        if(board[r][c] == 'Q') return false;
        c--;
    }

    return true;
}

int helper(int col, char board[8][8]) {
    if(col == 8) {
        return 1;
    }

    int ans = 0;

    for(int row = 0; row < 8; row++) {
        if(board[row][col] == '.' && valid(row, col, board)) {
            board[row][col] = 'Q';
            ans += helper(col + 1, board);
            board[row][col] = '.';
        }
    }

    return ans;
}
int main() {
    char board[8][8];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin>>board[i][j];
        }
    }

    int result = helper(0, board);

    cout<<result;
    return 0;
}