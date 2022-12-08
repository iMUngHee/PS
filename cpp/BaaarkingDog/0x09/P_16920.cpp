/*
문제 : 16920번 확장 게임
등급 : 골드 2
링크 : https://www.acmicpc.net/problem/16920
*/
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

queue<tuple<int,int,int>> Q[9];  // 세로 가로 이동 횟수

string board[1002];
int vis[1002][1002][9];

int pd[9];
int ans[9];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> p;
    for(int i = 0; i < p; i++){
        cin >> pd[i];
    }
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    for(int k = 0; k < p; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] - '1' == k){
                    vis[i][j][k] = 1;
                    Q[k].push({i, j, 0});
                }
            }
        }
    }
    while(true){
        int esc = 0;
        for(int k = 0; k < p; k++){
            queue<tuple<int,int,int>> nextQ;
            while(!Q[k].empty()){
                int x, y, turn;
                tie(x, y, turn) = Q[k].front(); Q[k].pop();
                if(turn >= pd[k]) {
                    nextQ.push({x, y, 0});
                    continue;
                }
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                    if(board[nx][ny] == '#') continue;
                    if(vis[nx][ny][k]) continue;
                    int chk = 0;
                    for(int i = 0; i < p; i++)
                        if(vis[nx][ny][i]) chk = 1;
                    if(chk) continue;
                    vis[nx][ny][k] = 1;
                    esc = 1;
                    Q[k].push({nx, ny, turn + 1});
                }
            }
            Q[k] = nextQ;
        }
        if(!esc) break;
    }
    for(int k = 0; k < p; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j][k]) ans[k]++;
            }
        }
    }
    for(int k = 0; k < p; k++){
        cout << ans[k] << ' ';
    }
    cout << '\n';
    return 0;
}

/*
    확장게임
    NxM 세로 가로
    각 칸은 비어있거나 막혀있음
    각 플레이어는 하나 이상의 성을 가지고 있음, 한 칸 위에 성이 두 개 이상인 경우는 없음
    플레이어 순서대로 각 라운드마다 확장
    플레이어 i는 자신의 성에서 Si칸 만큼 이동할 수 있는 모든 칸에 성을 동시에 만듬
    벽이나 다른 플레이어의 성이 있는 곳으로는 이동 불가
    모든 플레이어가 더 이상 확장할 수 없을 때 게임은 끝남
    input:
        n, m, p => 세로 가로 1 <= n, m <= 1000, 플레이어 1 <= p <= 9
        s1, s2, ... sp => 1 <= si <= 10^9
        배열 => .은 빈칸 #은 벽 '1', '2', ... '9'는 각 플레이어의 성
            모든 플레이어는 적어도 하나의 성을 가지고 있음, 게임에 참가하지 않는 플레이어의 성이 있는 경우는 없음
    output:
        ans => 각 플레이어가 가진 성의 수
*/
