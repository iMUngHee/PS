/*
문제 : 4179번 불!
등급 : 골드 4
링크 : https://www.acmicpc.net/problem/4179
*/
#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

string board[1002];

int distJ[1002][1002];
int distF[1002][1002];

queue<pair<int, int>> J;
queue<pair<int, int>> F;

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == '.'){
                distJ[i][j] = -1;
                distF[i][j] = -1;
            }
            if(board[i][j] == 'J'){
                J.push({i, j});
            }
            if(board[i][j] == 'F'){
                F.push({i, j});
            }
        }
    }
    while(!F.empty()){
        auto cur = F.front();
        F.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if(distF[nx][ny] >= 0) continue;
            distF[nx][ny] = distF[cur.X][cur.Y] + 1;
            F.push({nx, ny});
        }
    }
    while(!J.empty()){
        auto cur = J.front();
        J.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m){
                cout << distJ[cur.X][cur.Y] + 1 << '\n';
                return 0;
            }
            if(distJ[nx][ny] >= 0) continue;
            if(distF[nx][ny] != -1 && distF[nx][ny] <= distJ[cur.X][cur.Y] + 1) continue;
            distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
            J.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}

/*
    불이야! 불이야!
    불과 지훈이는 1분에 한칸씩 상하좌우로 이동
    지훈이는 배열 밖으로 나가면 탈출
    둘 다 벽 통과는 못함
    #: 벽
    .: 지나갈 수 있는 공간
    J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
    F: 불이 난 공간
    input:
        n => 세로
        m => 가로
        n x m 크기의 배열
    output:
        ans => 시간
*/
