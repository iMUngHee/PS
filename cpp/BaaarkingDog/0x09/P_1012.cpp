/*
문제 : 1012번 유기농 배추
등급 : 실버 2
링크 : https://www.acmicpc.net/problem/1012
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int board[52][52] = { 0 };
        int vis[52][52] = { 0 };
        int n, m, k;
        int ans = 0;
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] && !vis[i][j]){
                    ans++;
                    queue<pair<int, int>> Q;
                    vis[i][j] = 1;
                    Q.push({i, j});
                    while(!Q.empty()){
                        auto cur = Q.front();
                        Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
                            if(board[nx][ny] == 0 or vis[nx][ny]) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
    BFS 시작점 찾기
    <--- !!! 가로 세로 구분 잘해라!!! --->
    input:
        tc => test case
        n, m => 배추밭 가로 세로 1 <= n, m <= 50
        k => 배추 개수 1 <= k <= 2500
        x, y => 배추가 심어진 곳 0 <= x, y <= m - 1, n - 1
    output:
        ans => 배추밭에 필요한 지렁이 수
*/
