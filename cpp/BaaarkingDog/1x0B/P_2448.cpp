/*
문제 : 2448번 별 찍기 - 11
등급 :  골드 4
링크 : https://www.acmicpc.net/problem/2448
*/
#include <iostream>

using namespace std;

const int MAX = 1024 * 3 + 2;
char board[MAX][MAX * 2];

int n;

void solve(int k, int x, int y){
    if(k == 3){
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for(int i = y - 2; i < y + 3; i++) 
            board[x + 2][i] = '*';
        return;
    }
    k /= 2;
    solve(k, x, y);
    solve(k, x + k, y - k);
    solve(k, x + k, y + k);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;
    solve(n, 0, n - 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n; j++){
            if(board[i][j])
                cout << board[i][j];
            else
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}