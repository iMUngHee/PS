/*
문제 : 2573번 빙산
등급 : 골드 4
링크 : https://www.acmicpc.net/problem/2573
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[302][302];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int esc = 1;
    while (esc) {
        esc = 0;
        int vis[302][302] = {0};
        int fr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0 && !vis[i][j]) {
                    fr++;
                    queue<pair<int, int>> Q;
                    vis[i][j] = 1;
                    Q.push({i, j});
                    while (!Q.empty()) {
                        auto cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 or nx >= n or ny < 0 or ny >= m)
                                continue;
                            if (board[nx][ny] == 0 or vis[nx][ny]) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        if (fr >= 2) {
            cout << ans << '\n';
            return 0;
        }
        ans++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]){
                    esc = 1;
                    continue;
                }
                else {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                        if (board[nx][ny] == 0) continue;
                        board[nx][ny]--;
                    }
                }
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}

/*
    <---!!! 곱게 풀려면 함수로 나눠서 풀자 !!!--->
    빙산
    바다는 0, 그 외는 빙산의 높이
    빙산은 1턴마다 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어듬
    한 덩어리 빙산이 주어진다 최초로 더 덩어리 이상으로 분리되는 턴 수는?
    전부 다 녹을 때 까지 두 덩어리가 안될 수도 있다
    
    input:
        n, m => 맵 세로 가로 ( 3 <= n, m <= 300) 배열 => 1 <= 빙산의 높이 <= 10, 바다는 0,
            배열의 첫 행과 열, 마지막 행과 열에는 항상 0으로 채워짐
            1 이상의 정수가 들어잇는 칸의 개수는 10,000개 이하 
    output:
        ans => 두 덩어리가 되는 최초의 턴 수, 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력
*/
