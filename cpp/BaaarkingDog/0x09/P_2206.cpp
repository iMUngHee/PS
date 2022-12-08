/*
문제 : 2206번 벽 부수고 이동하기
등급 : 골드 4
링크 : https://www.acmicpc.net/problem/2206
*/
#include <iostream>
#include <tuple>
#include <queue>

#define X 0
#define Y 1
#define P 2

using namespace std;

string board[1002];
int dist[1002][1002][2];
// dist[1002][1002][0]: 벽 뚫기 전
// dist[1002][1002][1]: 벽 뚫은 후

queue<tuple<int,int,int>> Q;  // (x, y, 벽뚫 가능 여부)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    dist[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int x, y, broken;
        tie(x, y, broken) = cur;
        if(x == n - 1 && y == m - 1){
            cout << dist[x][y][broken] << '\n';
            return 0;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!dist[nx][ny][broken] && board[nx][ny] == '0'){
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                Q.push({nx,ny,broken});
            }
            if(!broken && !dist[nx][ny][broken] && board[nx][ny] == '1'){
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                Q.push({nx,ny,1});
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}

/*
    벽뚫탈
    0은 이동 가능
    1은 이동 불가
    (1, 1)에서 (n, m)까지 이동
    최단 경로 => 시작 칸 끝 칸 포함
    벽 한 개 까지 뿌수기 가능
    input:
        n, m => 맵 세로 가로 1 <= n, m <= 1000
        배열 => 0은 이동 가능, 1은 이동 불가
    output:
        ans => 최단 경로 / 도달 불가 시 -1 출력
*/
