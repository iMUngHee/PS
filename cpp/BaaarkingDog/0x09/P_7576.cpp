/*
문제 : 7576번 토마토
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/7576
*/
#include <algorithm>
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[1001][1001];
int dist[1001][1001];

int n, m, ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i, j});
            }
            if (board[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {
                cout << -1 << '\n';
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
    토마토토토
    상하좌우 인접한 익은 토마토가 있으면 익음
    -1은 빈칸

    input:
        n => 세로
        m => 가로
        n x m 크기의 배열
    output:
        ans => 최소 일수
*/
