/*
문제 : 7569번 토마토
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/7569
*/
#include <iostream>
#include <tuple>
#include <queue>

#define Z 0
#define X 1
#define Y 2

using namespace std;

int board[102][102][102];  // 높이 | 세로 | 가로
int dist[102][102][102];

queue<tuple<int, int, int>> Q;

int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};
int dz[3] = {-1, 0, 1};

int n, m, h, mx = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> h;  // 가로 | 세로 | 높이
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){
                    Q.push({i, j, k});
                }
                if(board[i][j][k] == 0){
                    dist[i][j][k] = -1;
                }
            }
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int z = 0; z < 3; z++){
            int nz = get<Z>(cur) + dz[z];
            if(nz < 0 or nz >= h) continue;
            for(int dir = 0; dir < 5; dir++){
                int nx = get<X>(cur) + dx[dir];
                int ny = get<Y>(cur) + dy[dir];
                if(dz[z] != 0 and (dx[dir] != 0 or dy[dir] != 0)) continue; // 대각선 검사 방지
                if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                if(dist[nz][nx][ny] >= 0) continue;
                dist[nz][nx][ny] = dist[get<Z>(cur)][get<X>(cur)][get<Y>(cur)] + 1;
                Q.push({nz, nx, ny});
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(dist[i][j][k] == -1){
                    cout << -1 << '\n';
                    return 0;
                }
                if(dist[i][j][k] > mx) mx = dist[i][j][k];
            }
        }
    }
    cout << mx << '\n';
    return 0;
}

/*
    토오오마토오오오
    상하좌우앞뒤
    input:
        n, m, h => 배추밭 가로 세로 2 <= m <= 100 | 2 <= n <= 100 | 1 <= h <= 100
        배열
    output:
        ans => 토마토가 다 익는 최소 일수
*/
