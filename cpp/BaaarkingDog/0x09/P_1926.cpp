/*
문제 : 1926번 그림
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/1926
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[501][501];
int vis[501][501];

queue<pair<int,int>> Q;

int n, m, num, mx;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] && !vis[i][j]) {
                num++;
                int tmp = 0;
                vis[i][j] = 1;
                Q.push({i, j});
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                    tmp++;
                }
                if (mx < tmp) mx = tmp;
            }
        }
    }
    cout << num << '\n' << mx << '\n';
    return 0;
}

/*
    그림의 넓이: 상하좌우로 연결된 것. 대각선 포함 x
    input:
        n => 세로
        m => 가로
        n x m 크기의 배열
    output:
        num => 그림의 개수
        mx => 가장 넓은 그림의 넓이
*/
