/*
문제 : 2178번 미로 탐색
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

string board[102];
int dist[101][101];

queue<pair<int, int>> Q;

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    Q.push({0, 0});
    dist[0][0] = 0;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1] + 1 << '\n';
    return 0;
}

/*
    미로 : (1, 1) => (n , m)
    input:
        n => 세로
        m => 가로
        n x m 크기의 배열
    output:
        ans => 거리
*/
