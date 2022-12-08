/*
문제 : 2468번 안전 영역
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/2468
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[102][102];
queue<pair<int, int>> Q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int mxh = -1;
int ans = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (mxh < board[i][j]) mxh = board[i][j];
        }
    }
    for (int i = 0; i <= mxh; i++) {
        int tmp = 0;
        int vis[102][102] = {0};
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(board[j][k] <= i){
                    vis[j][k] = -1;
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(board[j][k] > i && vis[j][k] == 0){
                    tmp++;
                    vis[j][k] = 1;
                    Q.push({j, k});
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                            if(vis[nx][ny] != 0) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        if(tmp > ans) ans = tmp;
    }
    cout << ans << '\n';
    return 0;
}

/*
    정사각형
    비의 양에 따라 일정 높이 이하 모든 지점은 침수
    아무 지역도 물에 잠기지 않을 수도 있음
    input:
        n => 정사각형 2 <= n <= 100
        높이 => 배열 1 <= 높이 <= 100
    output:
        ans => 물에 잠기지 않는 안전한 영역의 최대 개수
*/
