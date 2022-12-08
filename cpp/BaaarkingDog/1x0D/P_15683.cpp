/*
문제 : 15683번 감시
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/15683
*/
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int board[10][10];

vector<pair<int, int>> cctv;

int n, m;
int mn = 100;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void overwatch(int x, int y, int dir) {
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (board[x][y] == 6) return;
        if (board[x][y] != 0) continue;
        board[x][y] = -1;
    }
}

void reset(int tmp[10][10]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) board[i][j] = tmp[i][j];
}

void solve(int k) {
    if (k == cctv.size()) {
        int val = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) val += board[i][j] == 0;
        if (val < mn) mn = val;
        return;
    }

    int tmp[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    if (board[cctv[k].X][cctv[k].Y] == 1) {
        for (int i = 0; i < 4; i++) {
            overwatch(cctv[k].X, cctv[k].Y, i);
            solve(k + 1);
            reset(tmp);
        }
    } else if (board[cctv[k].X][cctv[k].Y] == 2) {
        overwatch(cctv[k].X, cctv[k].Y, 0);
        overwatch(cctv[k].X, cctv[k].Y, 2);
        solve(k + 1);
        reset(tmp);

        overwatch(cctv[k].X, cctv[k].Y, 1);
        overwatch(cctv[k].X, cctv[k].Y, 3);
        solve(k + 1);
        reset(tmp);

    } else if (board[cctv[k].X][cctv[k].Y] == 3) {
        overwatch(cctv[k].X, cctv[k].Y, 0);
        overwatch(cctv[k].X, cctv[k].Y, 1);
        solve(k + 1);
        reset(tmp);

        overwatch(cctv[k].X, cctv[k].Y, 1);
        overwatch(cctv[k].X, cctv[k].Y, 2);
        solve(k + 1);
        reset(tmp);

        overwatch(cctv[k].X, cctv[k].Y, 2);
        overwatch(cctv[k].X, cctv[k].Y, 3);
        solve(k + 1);
        reset(tmp);

        overwatch(cctv[k].X, cctv[k].Y, 3);
        overwatch(cctv[k].X, cctv[k].Y, 0);
        solve(k + 1);
        reset(tmp);

    } else if (board[cctv[k].X][cctv[k].Y] == 4) {
        overwatch(cctv[k].X, cctv[k].Y, 0);
        overwatch(cctv[k].X, cctv[k].Y, 1);
        overwatch(cctv[k].X, cctv[k].Y, 2);
        solve(k + 1);
        reset(tmp);

        overwatch(cctv[k].X, cctv[k].Y, 1);
        overwatch(cctv[k].X, cctv[k].Y, 2);
        overwatch(cctv[k].X, cctv[k].Y, 3);
        solve(k + 1);
        reset(tmp);

        overwatch(cctv[k].X, cctv[k].Y, 2);
        overwatch(cctv[k].X, cctv[k].Y, 3);
        overwatch(cctv[k].X, cctv[k].Y, 0);
        solve(k + 1);
        reset(tmp);

        overwatch(cctv[k].X, cctv[k].Y, 3);
        overwatch(cctv[k].X, cctv[k].Y, 0);
        overwatch(cctv[k].X, cctv[k].Y, 1);
        solve(k + 1);
        reset(tmp);

    } else if (board[cctv[k].X][cctv[k].Y] == 5) {
        for (int i = 0; i < 4; i++) overwatch(cctv[k].X, cctv[k].Y, i);
        solve(k + 1);
        reset(tmp);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6) cctv.push_back({i, j});
        }
    }
    solve(0);
    cout << mn << '\n';
    return 0;
}
